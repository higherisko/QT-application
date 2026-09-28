#pragma once

#include "Converter.h"
#include "MemHandler.hpp"

class Memory
{
private:
    uint16_t RegistersSize;

    std::vector<uint16_t> Registers;
    std::vector<uint16_t> IsUsed;
    MemHandler MemoryHandl;

public:
    Memory(const uint16_t RegistersSizeInit = 1);
    int MemsInit(const std::vector<uint16_t> &Data);
    int MemsAtInit(const uint16_t &Data, const uint16_t &Adress);
    int MemsBoolInit(const bool &Data,const uint16_t &ByteAdress,const uint16_t &BitAdress);
    int IsUsedCheckBool(const uint16_t &ByteAdress,const uint16_t &BitAdress );
    int UseUpgradeBool(const uint16_t &ByteAdress,const uint16_t &BitAdress );
    int UseEraseBool(const uint16_t &ByteAdress,const uint16_t &BitAdress );


    std::vector<uint16_t> GetMems(const uint16_t &StartAdress, const uint16_t &Lenght);
    uint16_t GetMem1(const uint16_t &Adress);
    uint16_t GetMemBools(const uint16_t &Adress);

    void Display()
    {
        for (int i{}; i < Registers.size(); i++)
        {
            std::cout << "Data at " << i + 1 << " = " << Registers.at(i) << " ";
        }
        std::cout << std::endl;
    };

    void MemsSizeSet(const uint16_t SizeInit) {RegistersSize = SizeInit;
                                               Registers.resize(SizeInit);
                                               IsUsed.resize(SizeInit);}
};