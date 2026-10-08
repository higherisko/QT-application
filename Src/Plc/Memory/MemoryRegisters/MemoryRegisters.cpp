#include "MemoryRegisters.h"

Memory::Memory(const uint16_t RegistersSizeInit)
    : RegistersSize{RegistersSizeInit}
{
    Registers.resize(RegistersSize);
    IsUsed.resize(RegistersSize);
}

int Memory::IsUsedCheckBool(const uint16_t &ByteAdress, const uint16_t &BitAdress)
{
    if (BitAdress > 8)
        return -3;
    uint16_t AdressPos = ByteAdress % 2;
    uint16_t RegAdress = ByteAdress / 2;
    if (RegAdress > RegistersSize)
    {
        return -2;
    }
    if (AdressPos == 1)
    {
        if (IsUsed.at(RegAdress & (1 << BitAdress + 8)))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (IsUsed.at(RegAdress & (1 << BitAdress)))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    return -1;
}

int Memory::UseUpgradeBool(const uint16_t &ByteAdress, const uint16_t &BitAdress)
{
    if (BitAdress > 8)
    {
        return -3;
    }
    uint16_t AdressPos = ByteAdress % 2;
    uint16_t RegAdress = ByteAdress / 2;
    if (IsUsedCheckBool(ByteAdress, BitAdress) == 1)
    {
        if (AdressPos == 1)
        {
            IsUsed.at(RegAdress) |= (1 << BitAdress + 8);
            return 1;
        }
        else
        {
            IsUsed.at(RegAdress) |= (1 << BitAdress);
            return 2;
        }
    }
    return -1;
}

int Memory::UseEraseBool(const uint16_t &ByteAdress, const uint16_t &BitAdress)
{
    if (BitAdress > 8)
    {
        return -3;
    }
    uint16_t AdressPos = ByteAdress % 2;
    uint16_t RegAdress = ByteAdress / 2;
    if (IsUsedCheckBool(ByteAdress, BitAdress) == 1)
    {
        if (AdressPos == 1)
        {
            IsUsed.at(RegAdress) &= ~(1 << BitAdress + 8);
            return 1;
        }
        else
        {
            IsUsed.at(RegAdress) |= ~(1 << BitAdress);
            return 2;
        }
        return 0;
    }
}
int Memory::MemsInit(const std::vector<uint16_t> &Data)
{
    Registers.clear();

    Registers.assign(Data.begin(), Data.end());

    MemoryHandl.DateAndTime.SetDateAndTime(Data);
    std::cout << MemoryHandl.DateAndTime;
    return 0;
}

int Memory::MemsAtInit(const uint16_t &Data, const uint16_t &Adress)
{
    if (Adress < Registers.size())
    {
        Registers.at(Adress) = Data;
        return 0;
    }
    return -1;
}

int Memory::MemsBoolInit(const bool &Data, const uint16_t &ByteAdress, const uint16_t &BitAdress)
{
    uint16_t AdressPos = ByteAdress % 2;
    uint16_t RegAdress = ByteAdress / 2;
    if (AdressPos == 0)
    {
        if (Data)
            Registers.at(RegAdress) |= (1 << BitAdress + 8);
        else
            Registers.at(RegAdress) &= ~(1 << BitAdress + 8);
    }
    else
    {
        if (Data)
            Registers.at(RegAdress) |= (1 << BitAdress);
        else
            Registers.at(RegAdress) &= ~(1 << BitAdress);
    }
    return 1;
}

uint16_t Memory::GetMem1(const uint16_t &Adress)
{
    if (Adress < Registers.size())
        return Registers.at(Adress);

    return -1;
}

std::vector<uint16_t> Memory::GetMems(const uint16_t &StartAdress, const uint16_t &Lenght)
{
    std::vector<uint16_t> ReturnValue;
    uint16_t Size = StartAdress + Lenght;
    if (Size < Registers.size())
        ReturnValue.assign(Registers.begin() + StartAdress, Registers.begin() + Size);

    return ReturnValue;
}

uint16_t Memory::GetMemBools(const uint16_t &Adress)
{
    uint16_t AdressTemp = Adress / 2;
    if (AdressTemp < Registers.size())
        return Registers.at(AdressTemp);
    else
        return -1;
}
