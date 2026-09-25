#ifndef _MODBUSCLIENT_H_
#define _MODBUSCLIENT_H_

#include <vector>
#include "Converter.h"
#include <string>
#include "ModbusParser.h"
#include "ModbusHandler.h"
#include "QtToCpp.hpp"


class ModbusClient 
{
private:
    ModbusParser ModbusPArser;
    ModbusHandler ModbusHNDlr;
    
public:
    ModbusClient();
    ~ModbusClient() = default;
    std::vector<uint8_t> ReadCoils(int Byte,const uint16_t Bit,int Lenght);
    std::vector<uint8_t> WriteCoils(const std::vector<bool> &Data,const uint16_t Byte,const uint16_t Bit,const uint16_t Lenght,const std::vector<uint16_t> &Memory);
    std::vector<uint8_t> WriteRegisters(std::vector<uint8_t> &Data,const uint16_t Byte,const uint16_t Lenght);
    std::vector<uint8_t> ReadInputRegisters(const uint16_t Byte,const uint16_t Lenght);
    void DisplayFrame(){std::cout<<ModbusPArser.GetHandleFrame();}
    void DisplayBoolData(int Index){std::cout<<ModbusHNDlr.GetBoolData(Index)<<std::endl;}
    void DisplayCoils(){ModbusHNDlr.DisplayBoolData();}
};

#endif