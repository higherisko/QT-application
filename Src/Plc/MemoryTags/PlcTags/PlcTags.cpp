#include "PlcTags.hpp"

Cylinder::Cylinder(const uint16_t AdressInit, const uint16_t AdressBitInit)
    : Move(AdressInit, AdressBitInit)
{
}

std::vector<uint16_t> Cylinder::GetAdressMove()

{
    std::vector<uint16_t> ReturnAdress;
    ReturnAdress.push_back(Move.AdressByte);
    ReturnAdress.push_back(Move.AdressBit);
    return ReturnAdress;
}

std::vector<uint16_t> Cylinder::GetAdressIsForward()

{
    std::vector<uint16_t> ReturnAdress;
    ReturnAdress.push_back(IsForward.AdressByte);
    ReturnAdress.push_back(IsForward.AdressBit);
    return ReturnAdress;
}

std::vector<uint16_t> Cylinder::GetAdressIsBackward()

{
    std::vector<uint16_t> ReturnAdress;
    ReturnAdress.push_back(IsBackward.AdressByte);
    ReturnAdress.push_back(IsBackward.AdressBit);
    return ReturnAdress;
}
