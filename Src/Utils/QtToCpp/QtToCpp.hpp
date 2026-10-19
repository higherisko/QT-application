#pragma once

#include <QObject>
#include "ModbusClient.h"
#include "PlcManager.hpp"
#include <unordered_map>
#include <QDebug>
 

class QtAdapter:public QObject
{
    Q_OBJECT
    private:
    public:
        
    public slots:
        void AddPlc(QString Name);
  


};