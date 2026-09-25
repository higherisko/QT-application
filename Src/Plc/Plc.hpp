#pragma once

#include "PlcTags.hpp"
#include <unordered_map>
#include <functional>
#include "MemoryRegisters.h"
class ComunicationInfo
{
public:
    std::string IpAdress;
    std::string TransportLayer;
    uint16_t Port;
    std::string Protocol;
    Memory PlcMemory;
    Cylinder StoperBeforeWeight;
    
};

class Plc
{

private:
    std::string Name;
    ComunicationInfo Comn;

public:
    Plc(const std::string &NameInit = "");
    void NameChange(const std::string &NameSet);
    void ComnSetting(const std::string &IpAdressSet, const std::string &TransportLayerSet, const uint16_t &PortSet, const std::string ProtocolSet);
};