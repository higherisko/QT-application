#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <iomanip>


    std::vector<uint8_t> StringToVector_Uint8(const std::string &ToCnovert);
    std::vector<uint8_t> Uint16_To_Uint8_Litle(std::vector<uint16_t> &Data);
    std::string Vector_Uint8_ToString(const std::vector<uint8_t> &ToConvert);
    std::string uint16_ToString(const uint16_t &ToConvert);
    uint16_t DBX(int Byte,int Bit);
    uint32_t IntToMcProtocolAdress(const int32_t &Adress);
    uint8_t StringToMcProtocolMemoryArea(const std::string &ToConvert);
    std::vector<uint16_t>  ModbusFrameToUint16(const std::vector<uint8_t> &Data);

    #endif