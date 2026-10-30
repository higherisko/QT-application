#pragma once

#include "Plc.hpp"
#include <algorithm>
#include "Converter.h"

class PlcManager
{
    private:
        std::unordered_map<std::string ,Plc>  Plcs;
    public:
        std::string AddPlc(const std::string Name);
        std::string Find(const std::string Name);
        uint16_t ComnSetting(const std::string &Name,const std::string &IpAdressSet = "", const std::string &TransportLayerSet = "", const std::string &PortSet = "", const std::string ProtocolSet = "");
        std::string GetPlcAdress(const std::string Name);
        std::string GetPlcPort(const std::string Name);
        uint16_t IpAdrresSetting(const std::string Ip,const std::string Name);
        uint16_t PortSetting(const std::string Port,const std::string Name);
};