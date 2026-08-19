#include "Aplication.hpp"

Aplication::Aplication()
{
    Motor.ByteSet(0);
    Motor.ValueSet(true);
    QObject::connect(w.getConnectButton(),&QPushButton::clicked,&Motor,&SiemensBool::write);
    w.show();
}
