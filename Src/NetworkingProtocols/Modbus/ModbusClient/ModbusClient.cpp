#include "ModbusClient.h"

ModbusClient::ModbusClient() : TcpClient()
{
}

std::vector<uint8_t> ModbusClient::ReadCoils(const int Byte, const uint16_t Bit, const int Lenght)
{
    std::vector<uint8_t> SendMap = ModbusPArser.BuildMaps[1](Byte, Lenght), returnvalue;
    if (Send(SendMap))
    {
        int Lenght = Recieve();
        if (Lenght > 0)
            returnvalue = GetRecvBuff();
        else
        {
            throw std::runtime_error("Recv = 0");
        }
    }
    else
    {
        throw std::runtime_error("Send Fail");
    }
    // ModbusPArser.BuildFrame(returnvalue);
    ModbusHNDlr.BuildCiols(returnvalue, Lenght, Byte);
    return returnvalue;
}

std::vector<uint8_t> ModbusClient::ReadInputRegisters(const uint16_t Byte, const uint16_t Lenght)
{
    std::vector<uint8_t> SendMap = ModbusPArser.BuildMaps[3](Byte, Lenght), returnvalue;
    if (Send(SendMap))
    {
        int RecieveInt = Recieve();
        if (RecieveInt > 0)
        {
            returnvalue = GetRecvBuff();
        }
        else
        {
            throw std::runtime_error("Recv = 0");
        }
    }
    else
    {
        throw std::runtime_error("Send Fail");
    }
    return returnvalue;
}

bool ModbusClient::WriteCoils(const std::vector<bool> &Data,
                              const uint16_t Byte, const uint16_t Bit,
                              const uint16_t Lenght)
{
    uint16_t Count = 0;

    std::vector<uint8_t> SendMap, DataToSend;

    uint16_t ByteLenght = (Lenght + 15) / 16;
    uint16_t j;
    for (uint16_t i = 0; i < ByteLenght; i++)
    {
        uint16_t Mask = memory.GetMem1(Byte + i);
        uint8_t SendMask = (Mask >> 8) & 0xFF;

        if (i = 0)
            j = Bit;
        else
            j = 0;
        for (j; j < 8 && Count < Lenght; j++)
        {
            if (Data.at(Count))
            {
                SendMask |= 1 << j;
            }
            else
            {
                SendMask &= ~(1 << j);
            }

            Count++;
        }

        DataToSend.push_back(SendMask);
        SendMask = Mask & 0xFF;
        for (uint16_t j = 0; j < 8 && Count < Lenght; j++)
        {
            if (Data.at(Count))
            {
                SendMask |= 1 << j;
            }
            else
            {
                SendMask &= ~(1 << j);
            }

            Count++;
        }
        DataToSend.push_back(SendMask);
    }

    SendMap = ModbusPArser.BuildMaps[15](Byte, ByteLenght);

    SendMap.insert(SendMap.end(),
                   DataToSend.begin(),
                   DataToSend.end());

    return Send(SendMap);
}

bool ModbusClient::WriteRegisters(std::vector<uint8_t> &Data, const uint16_t Byte, const uint16_t Lenght)
{
    std::vector<uint8_t> SendMAp;

    SendMAp = ModbusPArser.BuildMaps[16](Byte, Lenght);
    SendMAp.insert(SendMAp.end(), Data.begin(), Data.end());

    MemoryInitWrite(Data, Byte);

    return Send(SendMAp);
}
void ModbusClient::InitMemory()
{

    std::vector<uint8_t> SendMap = ModbusPArser.BuildMaps[3](0, 30);
    std::vector<uint16_t> DataInit;
    if (Send(SendMap))
    {
        int Lenght = Recieve();
        if (Lenght)
        {
            DataInit = ModbusFrameToUint16(GetRecvBuff());
            memory.MemsInit(DataInit, 0);
        }
        memory.Display();
    }
}

void ModbusClient::MemoryInitWrite(std::vector<uint8_t> &Data, const uint16_t &Adress)
{
    uint16_t MemoryInit;

    for (int i{}; i < Data.size(); i += 2)
    {
        MemoryInit = (static_cast<uint16_t>(Data.at(i + 1)) | (static_cast<uint16_t>(Data.at(i)) >> 8));
        memory.MemsAtInit(MemoryInit, Adress);
    }
}