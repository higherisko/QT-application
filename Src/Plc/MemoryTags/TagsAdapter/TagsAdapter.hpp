#pragma once

#include "PlcTags.hpp"
#include <unordered_map>
#include "MemoryRegisters.h"

class Tags
{
private:
   std::unordered_map<std::string, Cylinder> Cylinders;
   Memory Mems;

public:
   // Funcitons for Cylinder
   bool AddCylinder(const std::string &CyllName, const uint16_t &CylByteAdress, const uint16_t &CylBitAdress);
   int SetCylindersSensors(const std::string &CyllName, const uint16_t &SensorCount,const std::vector<uint16_t> &SensorsByteAndBit);
   int CylinderForward(const std::string &CyllName);
   int CylinderBackward(const std::string &CyllName);
   int CylinderIsForward(const std::string &CyllName);
   int CylinderIsBackward(const std::string &CyllName);
   // Function for memoryregisters
   int InitRegisterSize(const uint16_t &SizeInit);
   int InitAllRegisters(const std::vector<uint16_t> &Data);
};