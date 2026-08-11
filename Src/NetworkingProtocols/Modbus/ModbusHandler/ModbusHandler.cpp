#include "ModbusHandler.h"

ModbusHandler::ModbusHandler()
{
}

void ModbusHandler::SetUnitInf(const ModbusFrame &Frame)
{
    UnitInf.TransactionID = Frame.GetTransactionID();
    if (Frame.GetUnitID() == 2)
    {
        UnitInf.Unit = "SiemensPlc Virtual 1";
    }
}

void ModbusHandler::SetDataInf(const ModbusFrame &Frame)
{
    DataInf.FunctionCode = Frame.GetFunctionCode();
    DataInf.Adress = Frame.GetAdress();
    DataInf.Quantity = Frame.GetQuantity();
}

void ModbusHandler::SetData(const ModbusFrame &Frame)
{
}

std::vector<bool> ModbusHandler::BuildCiols(const std::vector<uint8_t> &Frame, int Lenght,uint16_t BitIndex)
{

    std::vector<bool> ReturnValue;

    int byteCount = Frame.at(8);

    for (int i = 0; i < byteCount; i++)
    {
        uint8_t dataByte = Frame[9 + i];
        uint16_t j;
        if(i == 0)
        {
            j = BitIndex;
        }
        else
        j = 0;
        for (j; j < 8; j++)
        {
            if (ReturnValue.size() >= Lenght)
                break;

            ReturnValue.push_back(
                (dataByte >> j) & 0x01);
        }
    }
    BooleanData = ReturnValue;
    return ReturnValue;
}