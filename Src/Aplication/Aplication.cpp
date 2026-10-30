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
    connect(&w, &MainWindow::AddPlcSignal, this, &Aplication::AddPlc);
    connect(&w, &MainWindow::ipChanged, this, &Aplication::IpChangeSlot);
    connect(&w, &MainWindow::portChanged, this, &Aplication::PortChangeSlot);
    connect(w.GetipPortSelector(), &IpPortSelector::PlcChangedSignal, this, &Aplication::GetPlcAdressSlot);
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
    Plcs.PortSetting(Value.toStdString(),w.GetipPortSelector()->GetPlcSelect()->currentText().toStdString());
}

void Aplication::GetPlcAdressSlot(QString Name)
{
    std::string ipFlag = Plcs.GetPlcAdress(Name.toStdString());
    std::string portFlag = Plcs.GetPlcPort(Name.toStdString());
    QMetaObject::Connection SendIp;
    QMetaObject::Connection SendPort;
    SendIp = connect(this, &Aplication::SendPlcAdressSignal, w.GetipPortSelector(), &IpPortSelector::PlcDisplayIpSlot);
    SendPort = connect(this, &Aplication::SendPlcPortSignal, w.GetipPortSelector(), &IpPortSelector::PlcDisplayPortSlot);
    if (ipFlag == "Plc not found.") {
        emit(SendPlcAdressSignal(""));
        emit(SendPlcPortSignal(""));
    } else {
        emit(SendPlcAdressSignal(ipFlag.c_str()));
        emit(SendPlcPortSignal(portFlag.c_str()));
    }
    disconnect(SendIp);
    disconnect(SendPort);
}

