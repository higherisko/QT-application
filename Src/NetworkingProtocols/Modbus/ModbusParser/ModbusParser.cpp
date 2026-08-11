#include "ModbusParser.h"

ModbusParser::ModbusParser() : MbapHead(0, 2)
{
    BuildMaps[1] = [this](uint16_t Byte, uint16_t Lenght)
    {
        std::vector<uint8_t> ReadRequest, PduHeadRead;
        int LenghtTemp = (Lenght + 15) / 16;
        MbapHead.Lenght = 6;
        PduHead.FunctionCode = 3;
        PduHead.Adress = ((Byte + 15) / 16) - 1;
        PduHead.Quantity_Value = LenghtTemp;
        ReadRequest = MbapHead.BuildMap();
        PduHeadRead = PduHead.PDUMap();
        ReadRequest.insert(ReadRequest.end(), PduHeadRead.begin(), PduHeadRead.end());
        return ReadRequest;
    };
    BuildMaps[3] = [this](uint16_t Byte, uint16_t Lenght)
    {
        std::vector<uint8_t> ReadRequest, PduHeadRead;
        MbapHead.Lenght = 6;
        PduHead.FunctionCode = 3;
        PduHead.Adress = Byte;
        PduHead.Quantity_Value = Lenght;
        ReadRequest = MbapHead.BuildMap();
        PduHeadRead = PduHead.PDUMap();
        ReadRequest.insert(ReadRequest.end(), PduHeadRead.begin(), PduHeadRead.end());

        return ReadRequest;
    };
    BuildMaps[15] = [this](uint16_t Byte, uint16_t Lenght)
    {
        std::vector<uint8_t> ReadRequest, PduHeadRead;
        MbapHead.Lenght = 7 + (((Lenght + 15) / 16) * 2);
        PduHead.FunctionCode = 0x10;
        PduHead.Adress = Byte;
        PduHead.Quantity_Value = (Lenght + 15) / 16;
        ReadRequest = MbapHead.BuildMap();
        PduHeadRead = PduHead.PDUMap();
        ReadRequest.insert(ReadRequest.end(), PduHeadRead.begin(), PduHeadRead.end());
        ReadRequest.push_back(Lenght * 2);

        return ReadRequest;
    };
       BuildMaps[16] = [this](uint16_t Byte, uint16_t Lenght)
    {
        std::vector<uint8_t> ReadRequest, PduHeadRead;
        MbapHead.Lenght = 6 + Lenght;
        PduHead.FunctionCode = 0x10;
        PduHead.Adress = Byte;
        PduHead.Quantity_Value = Lenght;
        ReadRequest = MbapHead.BuildMap();
        PduHeadRead = PduHead.PDUMap();
        ReadRequest.insert(ReadRequest.end(), PduHeadRead.begin(), PduHeadRead.end());

        return ReadRequest;
    };

}



void ModbusParser::BuildFrame(const std::vector<uint8_t> &Data)
{
    HandleFrame.SetTransactionID(Data);
    HandleFrame.SetUnitID(Data);
    HandleFrame.SetFunctionCode(Data);
    // HandleFrame.SetAdress();
    HandleFrame.SetQuantityValue(Data);
}

std::ostream &operator<<(std::ostream &Os, const ModbusParser &Rhs)
{
    Os << Rhs.HandleFrame;
    return Os;
}
