#include "NetworkingManager.hpp"

std::string NetworkingManager::SendToPlc(Plc &PlcData)
{
    if (PlcData.GetIp() == "")
        return "Ip is not Set!";
    if (PlcData.GetPort() == "")
        return "Port is not Set!";
    if (PlcData.GetProtocol() == "")
        if (PlcData.GetTransfer() == "TCP")
        {

        }
    if(PlcData.GetProtocol() == "McProtocol")
    {
        std::vector<uint8_t> SendFrame;
        if (PlcData.GetTransfer() == "TCP")
        {

        }
    }
    return "Sended";
}