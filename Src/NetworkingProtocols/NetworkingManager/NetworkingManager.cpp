#include "NetworkingManager.hpp"

void NetworkingManager::SendToPlc(const Plc &PlcData, const std::vector<uint8_t> &DataToSend)
{
    if (PlcData.GetIp() == "")
        return "Ip is not Set!";
    if (PlcData.GetPort() == "")
        return "Port is not Set!";
    if (PlcData.GetProtocol() == "")
        if (PlcData.GetTransfer() == "TCP")
        {
            Tcp_Client.Send(DataToSend);
        }
}