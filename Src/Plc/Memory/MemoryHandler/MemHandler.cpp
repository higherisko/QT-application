#include "MemHandler.hpp"

void Date_And_Time::SetDateAndTime(const std::vector<uint16_t> &Memory)
{
    Hour = Memory.at(22) & 0xFF;
    Minute = (Memory.at(22) >> 8) & 0xFF;
    Day = Memory.at(21) & 0xFF;
    Mounth = Memory.at(21) >> 8 & 0xFF;
    Year = Memory.at(21);
}

std::ostream &operator<<(std::ostream &os,Date_And_Time &RHS)
{
    os << static_cast<int>(RHS.Hour)<<":"<<static_cast<int>(RHS.Minute)<<":"<<" "<<static_cast<int>(RHS.Day)<<"."<<static_cast<int>(RHS.Mounth)<<"."<<RHS.Year<<"\n";
    return os;
}

void Bool::Invert()
{
    Adress ^= ~(1 << Bit);
}