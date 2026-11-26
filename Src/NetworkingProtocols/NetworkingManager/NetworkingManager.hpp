#pragma once

#include "TcpClient.hpp"
#include "McProtocol.h"
#include "ModbusClient.h"
#include "PlcManager.hpp"
#include <QObject>

class NetworkingManager:public QObject
{
    Q_OBJECT
    private:
        TcpClient Tcp_Client;
    public:

    signals:
        std::string SendToPlcSignal(const Plc &PlcData,const std::vector<uint8_t> &DataToSend);
    slots:
        std::string SendToPlc(const Plc &PlcData,const std::vector<uint8_t> &DataToSend);


};
