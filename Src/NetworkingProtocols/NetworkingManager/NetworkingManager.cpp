#include "NetworkingManager.hpp"

std::string NetworkingManager::SendToPlc(Plc &PlcData,std::string Operation_Name)
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
            std::vector<uint8_t> Data_To_Send;
            uint32_t Adress = PlcData.GetCyllInfo(Operation_Name).GetAdressMove();
            if(PlcData.GetCyllInfo(Operation_Name).GetMoveValue())
                Data_To_Send.push_back(0x10);
            else
                Data_To_Send.push_back(0x00);
            uint16_t Lenght = 1;
            SendFrame = McProtocol_Manager.write["B"](Data_To_Send,Adress,Lenght,"M");


        }
    }
    return "Sended";
}