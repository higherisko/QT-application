#pragma once

#include "PlcTags.hpp"
#include <unordered_map>
#include <functional>
#include "ModbusClient.h"
#include "MemoryRegisters.h"

class ComunicationInfo
{
public:
    std::string IpAdress;
    std::string TransportLayer;
    uint16_t Port;
    std::string Protocol;
    Cylinder StoperBeforeWeight;
    
};

class Plc
{

private:
    std::string Name;
    ComunicationInfo Comn;
    std::unordered_map<std::string,Cylinder> Cylinders;
public:
    Plc(const std::string &NameInit = "");
    //Comunication
    void NameChange(const std::string &NameSet);
    void ComnSetting(const std::string &IpAdressSet, const std::string &TransportLayerSet, const uint16_t &PortSet, const std::string ProtocolSet);
    void CylinderSend(const std::string CylName,const bool &Data);
    //Tags
    int AddCylinder(const std::string CyllName,const uint16_t CylByteAdress,const uint16_t CylBitAdress);
    
};   