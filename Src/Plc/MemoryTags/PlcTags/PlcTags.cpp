#include "PlcTags.hpp"

Cylinder::Cylinder(const uint16_t AdressInit)
    : Move(AdressInit)
{
}

uint16_t Cylinder::GetAdressMove()

{
    return Move.Adress;
}

uint16_t Cylinder::GetAdressIsForward()

{
    return IsForward.Adress;
}

uint16_t Cylinder::GetAdressIsBackward()

{
    return IsBackward.Adress;
}
