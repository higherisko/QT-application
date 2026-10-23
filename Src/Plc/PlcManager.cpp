#include "PlcManager.hpp"

std::string PlcManager::AddPlc(const std::string Name)
{
    if (Find(Name) == "Plc found.")
        return "Plc already exist !!";
    else
        Plcs.try_emplace(Name);
    return Name;
}

std::string PlcManager::Find(const std::string Name)
{
    auto ReturnValue = Plcs.begin();
    while (ReturnValue != Plcs.end())
    {
        if (Name == ReturnValue->first)
            return "Plc found.";
        ReturnValue++;
    }
    return "Plc not found.";
}

uint16_t PlcManager::ComnSetting(const std::string &Name,const std::string &IpAdressSet, const std::string &TransportLayerSet,
                                 const uint16_t &PortSet, const std::string ProtocolSet)
{
    std::string TransportLayer = TransportLayerSet,Protocol = ProtocolSet;
        if(Find(Name) != "Plc found.")
        {
            return -1;
        }
        ToLower(TransportLayer);
        if(TransportLayer != "tcp")
        {
            return -2;
        }
        if(PortSet < 0)
        {
            return -3;
        }
        ToLower(Protocol);
        if(Protocol != "modbus")
        {
            return -4;
        }
        for(auto plc:Plcs)
        {
            if(plc.second.GetIp() == IpAdressSet)
                return -5;
        }
        Plcs.at(Name).ComnSetting(IpAdressSet,TransportLayer,PortSet,Protocol);
        return 1;
        
}