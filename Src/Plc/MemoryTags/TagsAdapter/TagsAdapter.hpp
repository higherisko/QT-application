#pragma once

#include "PlcTags.hpp"
#include <unordered_map>


//This adapter works with tags and memory and joining them together
//Then we can use tags esaily in PLC.hpp and work with PLC memory

class Tags
{
private:
   std::unordered_map<std::string, Cylinder> Cylinders;
   std::vector<uint16_t> AdressUsed;

public:
   std::unordered_map<std::string, Cylinder> GetCyllinders(){return Cylinders;}

   // Funcitons for Cylinder
   Tags() {}
   std::string AddCylinder(Cylinder &Cyll,const std::string &Name);
   std::string SetCylindersSensors(const std::string &CyllName, const uint16_t &SensorCount,const uint16_t &Sensor_Move_Adress = -1,
                           const uint16_t &Sensor_FWD_Adress = -1,const uint16_t &Sensor_BWD_Adress = -1);
   
   int CylinderForward(const std::string &CyllName);
   int CylinderBackward(const std::string &CyllName);
   int CylinderIsForward(const std::string &CyllName);
   int CylinderIsBackward(const std::string &CyllName);



   
};