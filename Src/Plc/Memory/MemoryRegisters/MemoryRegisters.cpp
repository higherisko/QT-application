#include "MemoryRegisters.h"

void Memory::MemsInit(const std::vector<uint16_t> &Data,const uint16_t &Adress)
{
    if(Adress == 0)
    {
        Registers.clear();
    }
   
    Registers.assign(Data.begin(),Data.end());

    MemoryHandl.DateAndTime.SetDateAndTime(Data);
    std::cout<<MemoryHandl.DateAndTime;


} 

void Memory::MemsAtInit(const uint16_t &Data,const uint16_t &Adress)
{
    if(Adress < Registers.size())
    Registers.at(Adress) = Data;
}

uint16_t Memory::GetMem1(const uint16_t &Adress)
{
    if(Adress < Registers.size())
    return Registers.at(Adress);
    else
    return -1;
}

std::vector<uint16_t> Memory::GetMems(const uint16_t &StartAdress,const uint16_t &Lenght)
{
    std::vector<uint16_t> ReturnValue;
    uint16_t Size = StartAdress + Lenght;
    if(Size < Registers.size())
    ReturnValue.assign(Registers.begin() + StartAdress,Registers.begin() + Size);
     
    return ReturnValue;
}

