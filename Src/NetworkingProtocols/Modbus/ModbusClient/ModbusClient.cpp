#include "ModbusClient.h"

ModbusClient::ModbusClient() 
{
}

std::vector<uint8_t> ModbusClient::ReadCoils(const int Byte, const uint16_t Bit, const int Lenght)
{
    if (Byte > 4)
    {
        throw std::runtime_error("Coils lenght bigger than 4");
    }
    std::vector<uint8_t> SendMap = ModbusPArser.BuildMaps[1](Byte, Lenght), returnvalue;
    // ModbusPArser.BuildFrame(returnvalue);
    return SendMap;
}

std::vector<uint8_t> ModbusClient::ReadInputRegisters(const uint16_t Byte, const uint16_t Lenght)
{
    std::vector<uint8_t> SendMap = ModbusPArser.BuildMaps[3](Byte, Lenght), returnvalue;
   
    return SendMap;
}

std::vector<uint8_t> ModbusClient::WriteCoils(const std::vector<bool> &Data,
                              const uint16_t Byte, const uint16_t Bit,
                              const uint16_t Lenght,const std::vector<uint16_t> &MemoryMask)
{
    uint16_t Count = 0;

    std::vector<uint8_t> SendMap, DataToSend;

    uint16_t ByteLenght = (Lenght + 15) / 16;
    uint16_t j;
    for (uint16_t i = 0; i < ByteLenght; i++)
    {
        uint16_t Mask = MemoryMask.at(Byte + i);
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

    return SendMap;
}

std::vector<uint8_t> ModbusClient::WriteRegisters(std::vector<uint8_t> &Data, const uint16_t Byte, const uint16_t Lenght)
{
    std::vector<uint8_t> SendMAp;

    SendMAp = ModbusPArser.BuildMaps[16](Byte, Lenght);
    SendMAp.insert(SendMAp.end(), Data.begin(), Data.end());

    return SendMAp;
}
