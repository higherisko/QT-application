#pragma once

#include "TagsAdapter.hpp"
#include <functional>
#include "ModbusClient.h"


class ComunicationInfo
{
public:
    std::string IpAdress;
    std::string TransportLayer;
    std::string Port;
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
    //Settings for comunication 
    void ComnSetting(const std::string &IpAdressSet = "", const std::string &TransportLayerSet = "", const std::string &PortSet = "", const std::string ProtocolSet = "");
    void CylinderSend(const std::string CylName,const bool &Data);
    int AddCylinder(Cylinder &Cyll);
    std::string GetIp(){return Comn.IpAdress;}
    std::string GetPort(){return Comn.Port;}
    uint16_t SetIP(const std::string IP){Comn.IpAdress = IP;return 1;}
    uint16_t SetPort(const std::string Port){Comn.Port = Port;return 1;}
    
};   