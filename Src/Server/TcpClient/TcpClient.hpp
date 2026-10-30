#pragma once

#include <QTcpSocket>
#include <QDebug>
#include <QVector>

class TcpClient : public QTcpSocket
{
    Q_OBJECT
private:
    QObject *Socket;
    std::vector<uint8_t> RecvBuff;
public:
    explicit TcpClient(QObject *parent = nullptr) {}
    void Disconnect();
    int Recieve();
    std::vector<uint8_t> GetRecvBuff() { return RecvBuff; }
signals:
    void QTConnected(const QString Connected);
    void SendedSignal(const QString SendedFlag);
public slots:
    void Connect(QString Ip,QString Port);
    void Send(QVector<qint8> &Buffer);
};