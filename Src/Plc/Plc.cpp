#include "Plc.hpp"

Plc::Plc(const std::string &NameInit):Name{NameInit}
{
}

void Plc::NameChange(const std::string &NameSet)
{
    Name = NameSet;
}

void Plc::ComnSetting(const std::string &IpAdressSet,const std::string &TransportLayerSet,const uint16_t &PortSet,const std::string ProtocolSet)
{
    Comn.IpAdress = IpAdressSet;
    Comn.Port = PortSet;
    Comn.Protocol = ProtocolSet;
    Comn.TransportLayer = TransportLayerSet;
}

void Plc::CylinderSend(const std::string Name,const bool &Data)
{
    
}