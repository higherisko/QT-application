#include "Aplication.hpp"

Aplication::Aplication()
{

    w.show();
    

    
}

void Aplication::ConnectSignals()
{
    connect(&w,&MainWindow::AddPlcSignal,&QtAdapt,&QtAdapter::AddPlc);
}