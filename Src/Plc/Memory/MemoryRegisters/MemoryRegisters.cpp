#include "MemoryRegisters.h"

Memory::Memory(const uint16_t RegistersStartInit,const uint16_t RegistersEndInit,const uint16_t BoolsStartInit,const uint16_t BoolsEndInit) 
: RegistersStart{RegistersStartInit}, BoolsStart{BoolsStartInit},BoolsEnd{BoolsEndInit},RegistersEnd{RegistersEndInit}
{
    RegistersSize = RegistersEnd = RegistersStart;
    Registers = std::vector<uint16_t>(RegistersSize);
    BoolsSize = BoolsEnd - BoolsStart;
    Bools = std::vector<bool>(BoolsSize);
}

int Memory::MemsInit(const std::vector<uint16_t> &Data)
{
    if (Data.empty())
        return -1;
    if(Data.size() > RegistersSize)
        return -2;
    for(uint16_t i = 0;i < Data.size();i++)
    {
        if(IsUsedRegisters.at(i) == true)
            Registers.at(i) = Data.at(i);
        
    }
    return 1;
}

int Memory::MemsAtInit(const uint16_t &Data, const uint16_t &Adress)
{
    if (Adress > Registers.size())
    {
        return -1;
    }
    Registers.at(Adress) = Data;
    RegisterUseSet(Adress);
    return 1;
}

uint16_t Memory::MemsBoolsInit(const std::vector<bool> &Data)
{
    if (Data.empty())
        return -1;
    if(Data.size() > BoolsSize)
        return -2;
    for(uint16_t i = 0;i < Data.size();i++)
    {
        if(IsUsedBools.at(i) == true)
            Bools.at(i) = Data.at(i);
        
    }
    return 1;
}

int Memory::MemsBoolInit(const bool &Data,const uint16_t &Adress)
{
    if(Adress > BoolsStart)
    {
        return -1;
    }
    Bools.at(Adress) = Data;
    BoolUseSet(Adress);
    return 1;
}

int Memory::IsUsedCheckBool(const uint16_t &Adress)
{
    if(Adress > BoolsStart)
    {
        return -1;
    }
    else if (Bools.at(Adress) == true)
    {
        return -2;
    }
    return 0;
}

uint16_t Memory::RegisterUseSet(const uint16_t &Adress)
{
    if(Adress > RegistersSize)
        return -1;
    if(IsUsedRegisters.at(Adress) == true)
        return -2;
    IsUsedRegisters.at(Adress) = true;
    return 0;
}

uint16_t Memory::BoolUseSet(const uint16_t &Adress)
{
    if(Adress > BoolsSize)
        return -1;
    if(IsUsedBools.at(Adress) == true)
        return -2;
    IsUsedBools.at(Adress) = true;
    return 0;
}