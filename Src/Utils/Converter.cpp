#include "Converter.h"

std::vector<uint8_t> StringToVector_Uint8(const std::string &ToConvert)
{
    std::vector<uint8_t> ReturnValue;
    if (ToConvert.length() == 0)
    {
        return ReturnValue;
    }
    for (long long unsigned int i{}; i < ToConvert.size(); i++)
    {
        ReturnValue.push_back((ToConvert.at(i)));
    }
    return ReturnValue;
}

std::string Vector_Uint8_ToString(const std::vector<uint8_t> &data)
{
    {
        if (data.empty())
            return "Data = 0";

        std::ostringstream oss;

        for (uint8_t byte : data)
        {
            oss << std::hex << std::setw(2) << std::setfill('0')
                << (int)byte << " ";
        }

        return oss.str();
    }
}

uint16_t DBX(int Byte, int Bit)
{
    if (Bit > 7)
    {
        if (Bit < 0 || Bit > 7)
        {
            throw std::runtime_error("Bit out of range");
        } // Bity mozu byt len do 7 ako u siemens
    }
    uint16_t offset = static_cast<uint16_t>(Byte * 8 + Bit);

    return offset;
}

uint8_t StringToMcProtocolMemoryArea(const std::string &ToConvert)
{
    if(ToConvert == "SM" || ToConvert == "sm")
    {
        return 0x91;
    }
    if(ToConvert == "SD" || ToConvert == "sd")
    {
        return 0xA9;
    }
    if(ToConvert == "X" || ToConvert == "x")
    {
        return 0x9C;
    }
    if(ToConvert == "Y" || ToConvert == "y")
    {
        return 0x9D;
    }
    if(ToConvert == "M" || ToConvert == "m")
    {
        return 0x90;
    }
    if(ToConvert == "L" || ToConvert == "l")
    {
        return 0x92;
    }
    if(ToConvert == "F" || ToConvert == "f")
    {
        return 0x93;
    }
    if(ToConvert == "V" || ToConvert == "v")
    {
        return 0x94;
    }
    if(ToConvert == "B" || ToConvert == "b")
    {
        return 0xA0;
    }
    if(ToConvert == "D" || ToConvert == "d")
    {
        return 0xA8;
    }
    if(ToConvert == "W" || ToConvert == "w")
    {
        return 0xB4;
    }
    if(ToConvert == "TN" || ToConvert == "tn")
    {
        return 0xC2;
    }
    if(ToConvert == "STN" || ToConvert == "stn")
    {
        return 0xC8;
    }
    if(ToConvert == "SB" || ToConvert == "sb")
    {
        return 0xA1;
    }
    if(ToConvert == "SW" || ToConvert == "sw")
    {
        return 0xB5;
    }
    if(ToConvert == "S" || ToConvert == "s")
    {
        return 0x98;
    }
    if(ToConvert == "Z" || ToConvert == "z")
    {
        return 0xCC;
    }
    if(ToConvert == "R" || ToConvert == "r")
    {
        return 0xAF;
    }
    if(ToConvert == "ZR" || ToConvert == "zr")
    {
        return 0xB0;
    }
    return 0x00;

}

uint32_t IntToMcProtocolAdress(const int32_t &Adress)
{
     uint32_t ReturnValue = static_cast<uint32_t>(Adress);
     return ReturnValue;
}

std::string uint16_ToString(const uint16_t &ToConvert)
{
    std::ostringstream oss;
    oss << std::hex << std::setw(4) << std::setfill('0')<<ToConvert;
    return oss.str();
    
}

std::vector<uint16_t> ModbusFrameToUint16(const std::vector<uint8_t> &Data)
{
    std::vector<uint16_t> ReturnValue;
    for(int i{};i + 9 < Data.size();i += 2)
    {
        ReturnValue.push_back(static_cast<uint16_t>(Data.at(i + 9 + 1)|static_cast<uint16_t>(Data.at(i + 9)<<8)));
    }
    return ReturnValue;
}

std::vector<uint8_t> Uint16_To_Uint8_Litle(std::vector<uint16_t> &Data)
{
    std::vector<uint8_t> ReturnValue;
    for(int i{};i < Data.size();i++)
    {
        ReturnValue.push_back((Data.at(i))& 0xFF);
        ReturnValue.push_back((Data.at(i)>>8)&0xFF);
    }
    return ReturnValue;
}