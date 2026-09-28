#pragma once

#include "Converter.h"

class Booleans
{
public:
   Booleans(const uint16_t AdressByteInit = -1,const uint16_t AdressBitInit = -1)
   : AdressBit{AdressBitInit},AdressByte{AdressByteInit}{}
   uint16_t AdressByte;
   uint16_t AdressBit;
   bool Value;
};

class Cylinder
{

private:
   Booleans Move;
   Booleans IsForward;
   Booleans IsBackward;

public:
   Cylinder(const uint16_t AdrresInit = -1, const uint16_t AdressBitInit = -1);

   void SetMoveAdress(const uint16_t AdressTemp, const uint16_t AdressBitTemp)
   {
      Move.AdressByte = AdressTemp;
      Move.AdressBit = AdressBitTemp;
   }
   void UpgradeMoveValue(const bool Data) { Move.Value = Data; }
   void SetIsForwardAdress(const uint16_t AdressTemp, const uint16_t AdressBitTemp)
   {
      IsForward.AdressByte = AdressTemp;
      IsForward.AdressBit = AdressBitTemp;
   }
   void UpgradeIsForwardValue(const bool Data) { IsForward.Value = Data; }
   void SetIsBackawardAdress(const uint16_t AdressTemp, const uint16_t AdressBitTemp)
   {
      IsBackward.AdressByte = AdressTemp;
      IsBackward.AdressBit = AdressBitTemp;
   }
   void UpgradeIsBackwardValue(const bool Data) { IsBackward.Value = Data; }

   bool GetMoveValue() { return Move.Value; }
   bool GetIsForwardValue() { return IsForward.Value; }
   bool GetIsBackwardValue() { return IsBackward.Value; }

   std::vector<uint16_t> GetAdressMove();
   std::vector<uint16_t> GetAdressIsForward();
   std::vector<uint16_t> GetAdressIsBackward();

   std::vector<uint8_t> WriteMove(const bool Value);
};
