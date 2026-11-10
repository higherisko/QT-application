#include "McProtocolFrame.h"

std::ostream &operator<<(std::ostream &Os,const McProtocolFrame &Rhs)
{
    Os<<"SubHeader :"<<uint16_ToString(Rhs.SubHeader)<<" EndCode :"<<uint16_ToString(Rhs.EndCode)<<" Data: ";
    std::string Temp = Vector_Uint8_ToString(Rhs.Data);
    for(int i{};i < Rhs.Data.size();i++)
    {
        Os<<Temp.at(i);
    }
    Os<<"\n";
    return Os;
}