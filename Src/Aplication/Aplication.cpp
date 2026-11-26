#include "Aplication.hpp"
// Constructor
Aplication::Aplication()
{

    w.show();
    setConfigPath();
    ConnectSignals();
    AppConfig();
    w.setStyleSheet(ActualStyle);
}

// Connects and settings
void Aplication::ConnectSignals()
{
    QObject::connect(w.GetaddPlc(), &addPlc::AddPlcSignal, this, &Aplication::AddPlc);
    QObject::connect(&w, &MainWindow::ipChanged, this, &Aplication::IpChangeSlot);
    QObject::connect(&w, &MainWindow::portChanged, this, &Aplication::PortChangeSlot);
    QObject::connect(w.GetaddPlc(), &addPlc::PlcChangedSignal, this, &Aplication::GetPlcAdressSlot);

    QObject::connect(w.getConnectButton(), &QPushButton::clicked, this, &Aplication::TcpClientConnectSlot);
    QObject::connect(w.GetipPortSelector(),&NetworkSetting::ProtocolChangeSignal,this,&Aplication::ProtocolChangeDetect);
    QObject::connect(w.GetipPortSelector(),&NetworkSetting::TransferChangeSignal,this,&Aplication::TransferChangeDetect);
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
    uint16_t Flag = Plcs.IpAdrresSetting(Value.toStdString(), w.GetipPortSelector()->GetCurrentPlc().toStdString());
    if (Flag < 0)
    {
        QLabel *FlagMassage = new QLabel;
        FlagMassage->setText("Protocol Not Changed");
        return;
    }
    std::ofstream Write(ConfigPath);
    Write << Config.dump(4);
    Config["Plcs"][w.GetipPortSelector()->GetCurrentPlc().toStdString()]["Ip"] = Value.toStdString();
}

void Aplication::PortChangeSlot(QString Value)
{
    uint16_t Flag = Plcs.PortSetting(Value.toStdString(), w.GetipPortSelector()->GetCurrentPlc().toStdString());
    if (Flag < 0)
    {
        QLabel *FlagMassage = new QLabel;
        FlagMassage->setText("Protocol Not Changed");
        return;
    }
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
    SendIp = connect(this, &Aplication::SendPlcAdressSignal, w.GetipPortSelector(), &NetworkSetting::PlcDisplayIpSlot);
    SendPort = connect(this, &Aplication::SendPlcPortSignal, w.GetipPortSelector(), &NetworkSetting::PlcDisplayPortSlot);
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
    if(Config.contains("Plcs") && Config["Plcs"].is_object())
    {
    for (auto It = Config["Plcs"].begin(); It != Config["Plcs"].end(); ++It)
    {
        if(It.value().is_object())
        {
        Plcs.AddPlc(It.key());
        if(It.value().contains("Ip"))
            Plcs.IpAdrresSetting(It.value()["Ip"], It.key());
        if(It.value().contains("Port"))
            Plcs.PortSetting(It.value()["Port"], It.key());
        if(It.value().contains("Protocol"))
            Plcs.ProtocolSetting(It.value()["Protocol"],It.key());
        if(It.value().contains("Transfer"))
            Plcs.TransferSetting(It.value()["Transfer"],It.key());
        QMetaObject::Connection PlcAddedConection = connect(this, &Aplication::PlcAdded, w.GetaddPlc(), &addPlc::PlcAdded);
        std::string Key = It.key();
        emit PlcAdded(Key.c_str());
        disconnect(PlcAddedConection);
        }
    }
}
};

void Aplication::setConfigPath()
{
    QDir Dir(QApplication::applicationDirPath());
    QString Root = "QT-application";
    while (Root != Dir.dirName())
    {
        Dir.cdUp();
    }
    ConfigPath = Dir.filePath("Src/Config/Config.json").toStdString();
}

void Aplication::ProtocolChangeDetect(const QString Protocol)
{
    uint16_t Flag = Plcs.ProtocolSetting(Protocol.toStdString(), w.GetipPortSelector()->GetCurrentPlc().toStdString());

    if (Flag < 0)
    {
        return;
    }
    Config["Plcs"][w.GetipPortSelector()->GetCurrentPlc().toStdString()]["Protocol"] = Protocol.toStdString();
    std::ofstream Write(ConfigPath);
    Write << Config.dump(4);
}

void Aplication::TransferChangeDetect(const QString Transfer)
{
    uint16_t Flag = Plcs.TransferSetting(Transfer.toStdString(), w.GetipPortSelector()->GetCurrentPlc().toStdString());
    if (Flag < 0)
    {
        QLabel *FlagMassage = new QLabel;
        FlagMassage->setText("Protocol Not Changed");
        return;
    }
    Config["Plcs"][w.GetipPortSelector()->GetCurrentPlc().toStdString()]["Transfer"] = Transfer.toStdString();
    std::ofstream Write(ConfigPath);
    Write << Config.dump(4);
}

