#include "TcpClient.hpp"

bool TcpClient::Connect()
{
    connectToHost(IpAdrres,Port);
    if(state() == ConnectedState)
    {
       Connected = true;
       qDebug() << "Connected";
    }
    else
    {
        Connected = false;
        qDebug() << "Not Connected";  
    }
    emit QTConnected(Connected);
    return Connected;
}

void TcpClient::Disconnect()
{
    Connected = false;
    emit QTConnected(Connected);
    disconnectFromHost();
}

bool TcpClient::Send(std::vector<uint8_t> &Buffer)
{
    uint16_t Flag;
    bool ReturnValue;
    Flag = QTcpSocket::write(reinterpret_cast<char*>(Buffer.data()),Buffer.size());
    if (Flag == -1)
    {
        qDebug() << "Not Sended";
        ReturnValue = false;
    }
    else
    { 
        qDebug() << "Sended "<<Flag << " bytes";
        ReturnValue = true;

    }
    return ReturnValue;
    
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