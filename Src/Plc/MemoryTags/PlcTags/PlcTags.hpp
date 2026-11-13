#pragma once

#include "Converter.h"

// This class is used for easier working with memory;
// In this class you can define name of some objects for example (Cylinders,motors) and you can join memory with this tags

class Booleans
{
public:
   Booleans( const uint16_t AdressBitInit = -1)
       : Adress{AdressBitInit} {}
   uint16_t Adress;
   bool Value;
   Booleans(const Booleans &Lhs):Adress{Lhs.Adress}{}
};

class Cylinder
{

private:
   Booleans Move;
   Booleans IsForward;
   Booleans IsBackward;

public:
   Cylinder(const uint16_t AdrresInit = -1);
   Cylinder(const Cylinder &Cyll):IsBackward{Cyll.IsBackward},IsForward{Cyll.IsForward},Move{Cyll.Move}{}
   
   void SetMoveAdress(const uint16_t AdressTemp)
   {
      Move.Adress = AdressTemp;
   }
   void UpgradeMoveValue(const bool Data) { Move.Value = Data; }
   void SetIsForwardAdress(const uint16_t AdressTemp, const uint16_t AdressBitTemp)
   {
      IsForward.Adress = AdressTemp;
   }
   void UpgradeIsForwardValue(const bool Data) { IsForward.Value = Data; }
   void SetIsBackawardAdress(const uint16_t AdressTemp, const uint16_t AdressBitTemp)
   {
      IsBackward.Adress = AdressTemp;
   }
   void UpgradeIsBackwardValue(const bool Data) { IsBackward.Value = Data; }

   bool GetMoveValue() { return Move.Value; }
   bool GetIsForwardValue() { return IsForward.Value; }
   bool GetIsBackwardValue() { return IsBackward.Value; }

   uint16_t GetAdressMove();
   uint16_t GetAdressIsForward();
   uint16_t GetAdressIsBackward();

   std::vector<uint8_t> WriteMove(const bool Value);
};
