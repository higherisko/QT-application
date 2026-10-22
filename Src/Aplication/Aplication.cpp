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
}

// Slots Declaration
void Aplication::AddPlc(QString Name)
{
    std::string Flag = Plcs.AddPlc(Name.toStdString());
    connect(this, &Aplication::PlcAdded, &w, &MainWindow::PlcAdded);
    emit PlcAdded(Flag.c_str());
    disconnect();
}

void Aplication::IpChangeSlot(QString Value)
{
    
}

void Aplication::PortChangeSlot(QString Value)
{

}