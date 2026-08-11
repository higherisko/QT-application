#ifndef _MODBUSCLIENT_H_
#define _MODBUSCLIENT_H_

#include "TcpClient.hpp"
#include <vector>
#include "Converter.h"
#include <string>
#include "ModbusParser.h"
#include "ModbusHandler.h"
#include "MemoryRegisters.h"


class ModbusClient : public TcpClient
{
private:
    ModbusParser ModbusPArser;
    ModbusHandler ModbusHNDlr;
    Memory Memory;
public:
    ModbusClient();
    ~ModbusClient() = default;
    std::vector<uint8_t> ReadCoils(int Byte,int Lenght);
    bool WriteCoils(const std::vector<bool> &Data,const uint16_t Byte,const uint16_t Lenght);
    bool WriteRegisters(std::vector<uint8_t> &Data,const uint16_t Byte,const uint16_t Lenght);
    std::vector<uint8_t> ReadInputRegisters(const uint16_t Byte,const uint16_t Lenght);
    void DisplayFrame(){std::cout<<ModbusPArser.GetHandleFrame();}
    void DisplayBoolData(int Index){std::cout<<ModbusHNDlr.GetBoolData(Index)<<std::endl;}
    void DisplayCoils(){ModbusHNDlr.DisplayBoolData();}
    void InitMemory();
    void MemoryInitWrite(std::vector<uint8_t> &Data,const uint16_t &Adrres);
};

#endif