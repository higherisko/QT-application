#include "Aplication.hpp"

Aplication::Aplication()
{

    w.show();
    ConnectSignals();

    
}

void Aplication::ConnectSignals()
{
    connect(&w,&MainWindow::AddPlcSignal,&QtAdapt,&QtAdapter::AddPlc);
}