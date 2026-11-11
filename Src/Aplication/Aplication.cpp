#include "Aplication.hpp"
// Constructor
Aplication::Aplication()
{

    w.show();
    setConfigPath();
    ConnectSignals();
    AppConfig();

    w.Debug(ConfigPath.c_str());
    // Loading of qss styles for using
}

// Connects and settings
void Aplication::ConnectSignals()
{
    QObject::connect(w.GetaddPlc(), &addPlc::AddPlcSignal, this, &Aplication::AddPlc);
    QObject::connect(&w, &MainWindow::ipChanged, this, &Aplication::IpChangeSlot);
    QObject::connect(&w, &MainWindow::portChanged, this, &Aplication::PortChangeSlot);
    QObject::connect(w.GetipPortSelector(), &IpPortSelector::PlcChangedSignal, this, &Aplication::GetPlcAdressSlot);

    QObject::connect(w.getConnectButton(), &QPushButton::clicked, this, &Aplication::TcpClientConnectSlot);
}

// Slots Declaration
void Aplication::AddPlc(QString Name)
{
    std::string Flag = Plcs.AddPlc(Name.toStdString());
    QMetaObject::Connection PlcAddedConection = connect(this, &Aplication::PlcAdded, w.GetaddPlc(), &addPlc::PlcAdded);
    emit PlcAdded(Flag.c_str());
    disconnect(PlcAddedConection);
    if (Flag != "Plc already exist !!")
    {
        std::ofstream Write(ConfigPath);
        Config["Plcs"][Name.toStdString()] = {{"Ip", "0.0.0.0"}, {"Port", "0"}};
        Write << Config.dump(4);
    }
}

void Aplication::IpChangeSlot(QString Value)
{
    Plcs.IpAdrresSetting(Value.toStdString(), w.GetipPortSelector()->GetCurrentPlc().toStdString());
    Config["Plcs"][w.GetipPortSelector()->GetCurrentPlc().toStdString()]["Ip"] = Value.toStdString();
    std::ofstream Write(ConfigPath);
    Write << Config.dump(4);
}

void Aplication::PortChangeSlot(QString Value)
{
    Plcs.PortSetting(Value.toStdString(), w.GetipPortSelector()->GetCurrentPlc().toStdString());
    Config["Plcs"][w.GetipPortSelector()->GetCurrentPlc().toStdString()]["Port"] = Value.toStdString();
    std::ofstream Write(ConfigPath);
    Write << Config.dump(4);
}

void Aplication::GetPlcAdressSlot(QString Name)
{
    std::string ipFlag = Plcs.GetPlcAdress(Name.toStdString());
    std::string portFlag = Plcs.GetPlcPort(Name.toStdString());
    QMetaObject::Connection SendIp;
    QMetaObject::Connection SendPort;
    SendIp = connect(this, &Aplication::SendPlcAdressSignal, w.GetipPortSelector(), &IpPortSelector::PlcDisplayIpSlot);
    SendPort = connect(this, &Aplication::SendPlcPortSignal, w.GetipPortSelector(), &IpPortSelector::PlcDisplayPortSlot);
    if (ipFlag == "Plc not found.")
    {
        emit(SendPlcAdressSignal(""));
        emit(SendPlcPortSignal(""));
    }
    else
    {
        emit(SendPlcAdressSignal(ipFlag.c_str()));
        emit(SendPlcPortSignal(portFlag.c_str()));
    }
    disconnect(SendIp);
    disconnect(SendPort);
}

void Aplication::TcpClientConnectSlot(bool Button)
{
    std::string IpString, PortString;
    IpString = Plcs.GetPlcAdress(w.GetipPortSelector()->GetPlcSelect()->currentText().toStdString());
    PortString = Plcs.GetPlcPort(w.GetipPortSelector()->GetPlcSelect()->currentText().toStdString());
    QString IP = IpString.c_str();
    QString Port = PortString.c_str();
    QMetaObject::Connection Connectio = connect(this, Aplication::TcpClientConnectToSignal, &tcpClient, &TcpClient::Connect);
    emit TcpClientConnectToSignal(IP, Port);
    disconnect(Connectio);
    w.Debug("Sended");
}

void Aplication::AppConfig()
{
    std::ifstream Read(ConfigPath);
    std::string name;
    if (!Read.is_open())
    {
        w.Debug("Config Failed");
        return;
    }
    Read >> Config;
    name = Config["api"]["Name"];
    w.setWindowTitle(name.c_str());
    PlcConfig(Config);
}

void Aplication::PlcConfig(const nlohmann::json Plc)
{
    if (!Config.contains("Plcs"))
        return;
    for (auto It = Config["Plcs"].begin(); It != Config["Plcs"].end(); ++It)
    {
        Plcs.AddPlc(It.key());
        Plcs.IpAdrresSetting(It.value()["Ip"], It.key());
        Plcs.PortSetting(It.value()["Port"], It.key());
        QMetaObject::Connection PlcAddedConection = connect(this, &Aplication::PlcAdded, w.GetaddPlc(), &addPlc::PlcAdded);
        std::string Key = It.key();
        emit PlcAdded(Key.c_str());
        disconnect(PlcAddedConection);
    }
};

void Aplication::setConfigPath()
{
    QDir Dir(QApplication::applicationDirPath());
    QString Root = "QT-application";
    while(Root != Dir.dirName())
    {
        Dir.cdUp();
    }
    ConfigPath = Dir.filePath("Src/Config/Config.json").toStdString();
}