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

uint16_t PlcManager::ComnSetting(const std::string &Name, const std::string &IpAdressSet, const std::string &TransportLayerSet,
                                 const std::string &PortSet, const std::string ProtocolSet)
{
    std::string TransportLayer = TransportLayerSet, Protocol = ProtocolSet;
    if (Find(Name) != "Plc found.")
    {
        return -1;
    }
    ToLower(TransportLayer);
    if (TransportLayer != "tcp")
    {
        return -2;
    }
    if (PortSet.empty())
    {
        return -3;
    }
    ToLower(Protocol);
    if (Protocol != "modbus")
    {
        return -4;
    }
    for (auto plc : Plcs)
    {
        if (plc.second.GetIp() == IpAdressSet)
            return -5;
    }
    Plcs.at(Name).ComnSetting(IpAdressSet, TransportLayer, PortSet, Protocol);
    return 1;
}

std::string PlcManager::GetPlcAdress(const std::string Name)
{
    std::string Flag = Find(Name);
    if (Flag == "Plc not found.")
        return "Plc not found.";
    Flag = Plcs.at(Name).GetIp();
    return Flag;
}

uint16_t PlcManager::IpAdrresSetting(const std::string Ip, const std::string Name)
{
    std::string Flag = Find(Name);
    if (Flag == "Plc not found.")
        return -1;
    for(auto &plc:Plcs)
    {
        // if(plc.second.GetIp() == Ip)
        //     return -2;
    }
    Plcs.at(Name).SetIP(Ip);
    return 1;
}

uint16_t PlcManager::PortSetting(const std::string Port, const std::string Name)
{
    std::string Flag = Find(Name);
    if (Flag == "Plc not found.")
        return -1;
    for(auto &plc:Plcs)
    {
        // if(plc.second.GetIp() == Ip)
        //     return -2;
    }
    Plcs.at(Name).SetPort(Port);
    return 1;
}