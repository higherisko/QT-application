#pragma once

#include "TagsAdapter.hpp"
#include <functional>
#include "ModbusClient.h"


class ComunicationInfo
{
public:
    std::string IpAdress;
    std::string TransportLayer;
    uint16_t Port;
    std::string Protocol;
    
};

class Plc
{

private:
    std::string Name;
    ComunicationInfo Comn;
    Tags TaGS;
    
    
public:
    Plc(const std::string &NameInit = "");
    //Comunication
    void NameChange(const std::string &NameSet);
    void ComnSetting(const std::string &IpAdressSet, const std::string &TransportLayerSet, const uint16_t &PortSet, const std::string ProtocolSet);
    void CylinderSend(const std::string CylName,const bool &Data);
    int AddCylinder(Cylinder &Cyll);
    
};   