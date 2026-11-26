#include "PlcTags.hpp"

Cylinder::Cylinder(const uint16_t AdressInit)
    : Move(AdressInit)
{
}

uint16_t Cylinder::Out_GetAdressMove()

{
    return Move.Adress;
}

uint16_t Cylinder::In_GetAdressIsForward()

{
    return IsForward.Adress;
}

uint16_t Cylinder::In_GetAdressIsBackward()

{
    return IsBackward.Adress;
}
