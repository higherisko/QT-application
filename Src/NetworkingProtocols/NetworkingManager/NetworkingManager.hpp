#pragma once

#include "TcpClient.hpp"
#include "McProtocol.h"
#include "ModbusClient.h"
#include "PlcManager.hpp"
#include <QObject>
#include <QVector>

class NetworkingManager : public QObject
{
    Q_OBJECT
private:
    TcpClient Tcp_Client;
    MCProtocol McProtocol_Manager;
    ModbusClient Modbus_Manager;

public:
signals:
    std::string SendToPlcSignal(const QVector<qint8> SendBuff);
public slots:
    std::string SendToPlc(Plc &PlcData);
};
