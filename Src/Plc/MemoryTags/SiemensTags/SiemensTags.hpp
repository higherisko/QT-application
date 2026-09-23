#pragma once

#include <QObject>
#include "MemoryRegisters.h"
class Cylinder : public QObject
{
   Q_OBJECT
private:
   QString Name;
   uint16_t StartAdress;
   const uint8_t Size = 3;
   bool Move;
   bool IsForward;
   bool IsBackward;

public:
explicit Cylinder(QObject *parent = nullptr,uint16_t Startadress):StartAdress{Startadress}{}

signals:
   void Move(bool Value);
public slots:
   
   
};
