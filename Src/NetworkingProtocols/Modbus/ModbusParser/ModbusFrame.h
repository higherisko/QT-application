#pragma once
#include "Converter.h"
#include <vector>

class ModbusFrame;
std::ostream &operator<<(std::ostream &Os,const ModbusFrame &Rhs);

class ModbusFrame
{
    private:
       uint16_t TransactionID;
       uint8_t UnitID;
       uint8_t FunctionCode;
       uint16_t Adress;
       uint8_t QuantityValue;
       std::vector<uint8_t> Data;
    public:
       void SetTransactionID(const std::vector<uint8_t> &InputFrame);
       void SetUnitID(const std::vector<uint8_t> &InputFrame);
       void SetFunctionCode(const std::vector<uint8_t> &InputFrame);
       void SetAdress(const uint16_t &InputFrame);
       void SetQuantityValue(const std::vector<uint8_t> &InputFrame);
       void SetData (const std::vector<uint8_t> &InputFrame);
       uint16_t GetTransactionID () const {return TransactionID;}
       uint8_t GetUnitID () const {return UnitID;}
       uint8_t GetFunctionCode() const {return FunctionCode;}
       uint16_t GetAdress() const {return Adress;}
       uint8_t GetQuantity() const {return QuantityValue;}
       uint16_t GetWordData() const {uint16_t Value = (Data.at(0) << 8) | (Data.at(1));return Value;}
       friend std::ostream &operator<<(std::ostream &Os,const ModbusFrame &Rhs);
};