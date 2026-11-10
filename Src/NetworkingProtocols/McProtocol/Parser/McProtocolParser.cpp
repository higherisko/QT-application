#include "McProtocolParser.h"

McProtocolParser::McProtocolParser()
{
    HeadReq.SubHeader = 0x0050;
    HeadReq.Network_No = 0x00;
    HeadReq.PLC_No = 0xFF;
    HeadReq.IO_No = 0x03FF;
    HeadReq.Station_No = 0x00;
    HeadReq.Monitoring_Timer = 0x000a;
}

std::vector<uint8_t> McProtocolParser::ReadBitHead(const std::string &MemoryArea, const uint32_t &Adress, const uint16_t &Points)
{
    std::vector<uint8_t> ReturnValue;
    HeadReq.Comand = 0x0401;
    HeadReq.SubComand = 0x0001;
    HeadReq.DeviceCode = StringToMcProtocolMemoryArea(MemoryArea);
    HeadReq.Adress1 = (Adress) & 0xFFFF;
    HeadReq.Adress2 = (Adress >> 16) & 0xFF;
    HeadReq.DevicePoints = Points;
    HeadReq.Request_Data_Lenght = 0x000C;
    ReturnValue = HeadReq.Map();
    return ReturnValue;
}

std::vector<uint8_t> McProtocolParser::WriteBitHead(const std::string &MemoryArea, const uint32_t &Adress, const uint16_t &Points)
{
    std::vector<uint8_t> ReturnValue;
    HeadReq.Comand = 0x1401;
    HeadReq.SubComand = 0x0001;
    HeadReq.DeviceCode = StringToMcProtocolMemoryArea(MemoryArea);
    HeadReq.Adress1 = (Adress) & 0xFFFF;
    HeadReq.Adress2 = (Adress >> 16) & 0xFF;
    HeadReq.DevicePoints = Points;
    HeadReq.Request_Data_Lenght = 0x000C + Points;
    ReturnValue = HeadReq.Map();
    return ReturnValue;
}

std::vector<uint8_t> McProtocolParser::WriteWordHead(const std::string &MemoryArea, const uint32_t &Adress, const uint16_t &Points)
{
    std::vector<uint8_t> ReturnValue;
    HeadReq.Comand = 0x1401;
    HeadReq.SubComand = 0x0000;
    HeadReq.DeviceCode = StringToMcProtocolMemoryArea(MemoryArea);
    HeadReq.Adress1 = (Adress) & 0xFFFF;
    HeadReq.Adress2 = (Adress >> 16) & 0xFF;
    HeadReq.DevicePoints = Points;
    HeadReq.Request_Data_Lenght = 0x000C + (Points * 2);
    ReturnValue = HeadReq.Map();
    return ReturnValue;
}

std::vector<uint8_t> McProtocolParser::ReadWordHead(const std::string &MemoryArea, const uint32_t &Adress, const uint16_t &Points)
{
    std::vector<uint8_t> ReturnValue;
    HeadReq.Comand = 0x0401;
    HeadReq.SubComand = 0x0000;
    HeadReq.DeviceCode = StringToMcProtocolMemoryArea(MemoryArea);
    HeadReq.Adress1 = (Adress) & 0xFFFF;
    HeadReq.Adress2 = (Adress >> 16) & 0xFF;
    HeadReq.DevicePoints = Points;
    HeadReq.Request_Data_Lenght = 0x000C;
    ReturnValue = HeadReq.Map();
    return ReturnValue;
}

void McProtocolParser::CreateFrameToHandler(const std::vector<uint8_t> &InputFrame)
{
    PlcFrame.SetSubHeader(InputFrame);
    PlcFrame.SetEndCode(InputFrame);
    PlcFrame.SetData(InputFrame);
}

std::ostream &operator<<(std::ostream &Os, const McProtocolParser &Rhs)
{
    Os << Rhs.PlcFrame;
    return Os;
}

