#include "Aplication.hpp"
// Constructor
Aplication::Aplication()
{

    w.show();
    ConnectSignals();
}
// Connects and settings
void Aplication::ConnectSignals()
{
    QObject::connect(&w, &MainWindow::AddPlcSignal, this, &Aplication::AddPlc);
    QObject::connect(&w, &MainWindow::ipChanged, this, &Aplication::IpChangeSlot);
    QObject::connect(&w, &MainWindow::portChanged, this, &Aplication::PortChangeSlot);
    QObject::connect(w.GetipPortSelector(), &IpPortSelector::PlcChangedSignal, this, &Aplication::GetPlcAdressSlot);

    QObject::connect(w.getConnectButton(),&QPushButton::clicked,this,&Aplication::TcpClientConnectSlot);
}

// Slots Declaration
void Aplication::AddPlc(QString Name)
{
    std::string Flag = Plcs.AddPlc(Name.toStdString());
    QMetaObject::Connection PlcAddedConection = connect(this, &Aplication::PlcAdded, &w, &MainWindow::PlcAdded);
    emit PlcAdded(Flag.c_str());
    disconnect(PlcAddedConection);
}

void Aplication::IpChangeSlot(QString Value)
{
    Plcs.IpAdrresSetting(Value.toStdString(),w.GetipPortSelector()->GetPlcSelect()->currentText().toStdString());
}

void Aplication::PortChangeSlot(QString Value)
{
}

void Aplication::GetPlcAdressSlot(QString Value)
{
    std::string Flag = Plcs.GetPlcAdress(Value.toStdString());
    QMetaObject::Connection Send;
    Send = connect(this, &Aplication::SendPlcAdressSignal, w.GetipPortSelector(), &IpPortSelector::PlcChangeIp);
    if (Flag == "Plc not found.")
        emit(SendPlcAdressSignal(""));
    else
        emit(SendPlcAdressSignal(Flag.c_str()));
    disconnect(Send);
}

void Aplication::TcpClientConnectSlot(bool Button)
{
    std::string IpString,PortString;
    IpString = Plcs.GetPlcAdress(w.GetipPortSelector()->GetPlcSelect()->currentText().toStdString());
    PortString = Plcs.GetPlcPort(w.GetipPortSelector()->GetPlcSelect()->currentText().toStdString());
    QString IP = IpString.c_str();
    QString Port = PortString.c_str();
    QMetaObject::Connection Connectio = connect(this,Aplication::TcpClientConnectToSignal,&tcpClient,&TcpClient::Connect);
    emit TcpClientConnectToSignal(IP,Port);
    disconnect(Connectio);
    w.Debug("Sended");
}
