#pragma once

#include "ModbusFrame.h"
#include "Converter.h"
#include<functional>
#include <unordered_map>


struct UnitInfo
{
    uint16_t TransactionID;
    std::string Unit;
};

struct DataInfo
{
    uint8_t FunctionCode;
    uint16_t Adress;
    uint16_t Quantity;
};

class ModbusHandler
{
private:
    ModbusFrame FrameToHandle;
    UnitInfo UnitInf;
    DataInfo DataInf;
    std::vector<bool> BooleanData;
    std::vector<int> IntData;
    std::vector<std::string> StringData;

public:
    ~ModbusHandler() = default;
    ModbusHandler();
    void SetUnitInf(const ModbusFrame &Frame);
    void SetDataInf(const ModbusFrame &Frame);
    void SetData(const ModbusFrame &Frame);
    std::vector<bool> BuildCiols(const std::vector<uint8_t> &Frame,int Lenght,uint16_t BitIndex);


    std::string GetPlcName() const { return UnitInf.Unit; }
    uint16_t GetTransactionID() const { return UnitInf.TransactionID; }
    bool GetBoolData(int index){return BooleanData.at(index);}

    void DisplayBoolData(){for(uint16_t i{};i < BooleanData.size();i++){std::cout<<BooleanData.at(i)<<" , ";}std::cout<<std::endl;}
};