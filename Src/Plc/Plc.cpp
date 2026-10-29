#include "Plc.hpp"

Plc::Plc(const std::string &NameInit):Name{NameInit}
{
    Comn.IpAdress = "0.0.0.0";
}

void Plc::NameChange(const std::string &NameSet)
{
    Name = NameSet;
}

void Plc::ComnSetting(const std::string &IpAdressSet,const std::string &TransportLayerSet,const std::string &PortSet,const std::string ProtocolSet)
{
    Comn.IpAdress = IpAdressSet;
    Comn.Port = PortSet;
    Comn.Protocol = ProtocolSet;
    Comn.TransportLayer = TransportLayerSet;
}

void Plc::CylinderSend(const std::string Name,const bool &Data)
{
    
}

int Plc::AddCylinder(Cylinder &Cyll)
{
    return 0;
}

