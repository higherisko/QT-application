#pragma once

#include <QTcpSocket>
#include <QDebug>

class TcpClient : public QTcpSocket
{
    Q_OBJECT
private:
    QObject *Socket;
    std::vector<uint8_t> RecvBuff;
    bool Connected;
    char *IpAdrres;
    uint16_t Port;

public:
    explicit TcpClient(QObject *parent = nullptr) {}
    void Disconnect();
    bool Connect();
    bool Send(std::vector<uint8_t> &Buffer);
    int Recieve();
    std::vector<uint8_t> GetRecvBuff() { return RecvBuff; }
    bool Get_Connected() { return Connected; }
signals:
    void QTConnected(bool connected_temp);
};