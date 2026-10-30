#include "TcpClient.hpp"

void TcpClient::Connect(QString Ip,QString Port)
{
    qint16 PortTemp = Port.toInt();
    connectToHost(Ip,PortTemp);
    if(state() == ConnectedState)
    {
        emit QTConnected("Connected");
    }
    else 
    {
        emit QTConnected("Not Connected");
    }

}

void TcpClient::Disconnect()
{
    emit QTConnected("Disconnected");
    disconnectFromHost();
}

void TcpClient::Send(QVector<qint8> &Buffer)
{
    qint16 Flag;
    Flag = QTcpSocket::write(reinterpret_cast<char*>(Buffer.data()),Buffer.size());
    if (Flag == -1)
    {
        emit SendedSignal("Data Sended");
    }
    else
    { 
        emit SendedSignal("Data Not Sended");

    }

    
}

int TcpClient::Recieve()
{
    QByteArray Data = QTcpSocket::readAll();
    for (int i{};i < Data.size();i++)
    {
        RecvBuff.at(i) = Data.at(i); 
    }
    return 0;
}