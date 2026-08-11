#include "ModbusFrame.h"

void ModbusFrame::SetTransactionID(const std::vector<uint8_t> &InputFrame)
{
    TransactionID = static_cast<uint16_t>(InputFrame.at(1)|(static_cast<uint16_t>(InputFrame.at(0)>>8)));
}

void ModbusFrame::SetUnitID(const std::vector<uint8_t> &InputFrame)
{
    UnitID = InputFrame.at(6);
}

void ModbusFrame::SetFunctionCode(const std::vector<uint8_t> &InputFrame)
{
    FunctionCode = InputFrame.at(7);
}

void ModbusFrame::SetAdress(const uint16_t &InputFrame)
{
    Adress = static_cast<uint16_t>(InputFrame|static_cast<uint16_t>(InputFrame>>8));
}

void ModbusFrame::SetQuantityValue(const std::vector<uint8_t> &InputFrame)
{
    QuantityValue = InputFrame.at(8);
}

void ModbusFrame::SetData(const std::vector<uint8_t> &InputFrame)
{
     for(int i{};i < InputFrame.size() - 9;i++)
     {
        Data.push_back(InputFrame.at(i + 9));
     }
}

std::ostream &operator<<(std::ostream &Os,const ModbusFrame &Rhs)
{
    Os<<"TransactionID: "<<uint16_ToString(Rhs.TransactionID)<<" Data: "<<uint16_ToString(Rhs.QuantityValue)<<"\n";
    return Os;
}