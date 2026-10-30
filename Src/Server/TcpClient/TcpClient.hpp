#pragma once

#include <QTcpSocket>
#include <QDebug>
#include <QVector>

class TcpClient : public QTcpSocket
{
    Q_OBJECT
private:
    QObject *Socket;
    QVector<qint8> RecvBuff;
public:
    explicit TcpClient(QObject *parent = nullptr) {}
signals:
    void QTConnected(const QString Connected);
    void SendedSignal(const QString SendedFlag);
    void GetRecvBuff();
public slots:
    void Connect(QString Ip,QString Port);
    void Send(QVector<qint8> &Buffer);
    void Recieve();
    void Disconnect();

};