#pragma once

#include <QObject>
#include "ModbusClient.h"
#include "Plc.hpp"
#include <unordered_map>

class Adapter:QObject
{
    Q_OBJECT
    private:
        std::unordered_map<std::string ,Plc>  Plcs;
    public:
        
    public slots:
        void AddPlc(QString Name );
        void SetIp(QString Ip);


};