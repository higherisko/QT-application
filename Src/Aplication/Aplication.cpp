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
    connect(&w,&MainWindow::ipChanged,this,&Aplication::IpChangeSlot);
    connect(&w,&MainWindow::portChanged,this,&Aplication::PortChangeSlot);
    connect(w.GetipPortSelector(),&IpPortSelector::PlcChangedSignal,this,&Aplication::GetPlcAdressSlot);
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
    Plcs.IpAdrresSetting(Value.toStdString(),"Plc1");
}

void Aplication::PortChangeSlot(QString Value)
{

}

void Aplication::GetPlcAdressSlot(QString Value)
{
    std::string Flag = Plcs.GetPlcAdress(Value.toStdString());
    QMetaObject::Connection Send;
    Send = connect(this,&Aplication::SendPlcAdressSignal,w.GetipPortSelector(),&IpPortSelector::PlcChangeIp);
    if(Flag == "Plc not found.")
        emit(SendPlcAdressSignal(""));
    else
        emit(SendPlcAdressSignal(Flag.c_str()));
    disconnect(Send);
    
    
}