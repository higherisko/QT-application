#include "MemoryRegisters.h"

Memory::Memory(const uint16_t RegistersSizeInit, const uint16_t BoolsSizeInit) 
: RegistersSize{RegistersSizeInit}, BoolsSize{BoolsSizeInit}
{
}

int Memory::MemsInit(const std::vector<uint16_t> &Data)
{
    if (Data.empty())
        return -1;
    Registers.insert(Registers.begin(), Data.begin(), Data.end());
    return 1;
}

int Memory::MemsAtInit(const uint16_t &Data, const uint16_t &Adress)
{
    if (Adress > Registers.size())
    {
        return -1;
    }
    Registers.at(Adress) = Data;
    return 1;
}

uint16_t Memory::MemsBoolsInit(const std::vector<bool> &Data)
{
    if (Data.empty())
        return -1;
    Bools.insert(Bools.begin(), Data.begin(), Data.end());
    return 1;
}

int Memory::MemsBoolInit(const bool &Data,const uint16_t &Adress)
{
    if(Adress > BoolsSize)
    {
        return -1;
    }
    Bools.at(Adress) = Data;
    return 1;
}