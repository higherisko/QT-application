#pragma once

#include "Converter.h"
#include "MemHandler.hpp"

class Memory
{
private:
    uint16_t RegistersSize;
    uint16_t BoolsSize;

    std::vector<uint16_t> Registers;
    std::vector<bool> Bools;
    std::vector<bool> IsUsedRegisters;
    std::vector<bool> IsUsedBools;
    MemHandler MemoryHandl;

public:
    Memory(const uint16_t RegistersSizeInit = 1,const uint16_t BoolsSizeInit = 1);
    int MemsInit(const std::vector<uint16_t> &Data);
    int MemsAtInit(const uint16_t &Data, const uint16_t &Adress);
    int MemsBoolInit(const bool &Data,const uint16_t &Adress);
    uint16_t MemsBoolsInit(const std::vector<bool> &Data);
    int IsUsedCheckBool(const uint16_t &Adress);

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
                                               IsUsedRegisters.resize(SizeInit);}
};