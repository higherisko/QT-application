#pragma once

#include "PlcTags.hpp"
#include <unordered_map>
#include "MemoryRegisters.h"

//This adapter works with tags and memory and joining them together
//Then we can use tags esaily in PLC.hpp and work with PLC memory

class Tags
{
private:
   std::unordered_map<std::string, Cylinder> Cylinders;
   Memory Mems;

public:
   std::unordered_map<std::string, Cylinder> GetCyllinders(){return Cylinders;}
   // Funcitons for Cylinder
   Tags() {}
   uint16_t AddCylinder(Cylinder &Cyll,const std::string &Name);
   int SetCylindersSensors(const std::string &CyllName, const uint16_t &SensorCount,const uint16_t &Sensor_Move_Adress = -1,
                           const uint16_t &Sensor_FWD_Adress = -1,const uint16_t &Sensor_BWD_Adress = -1);
   
   int CylinderForward(const std::string &CyllName);
   int CylinderBackward(const std::string &CyllName);
   int CylinderIsForward(const std::string &CyllName);
   int CylinderIsBackward(const std::string &CyllName);
   // Function for memoryregisters
   int InitRegisterSize(const uint16_t &SizeInit);
   int InitAllRegisters(const std::vector<uint16_t> &Data);

   
};