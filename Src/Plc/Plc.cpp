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

std::vector<uint8_t> Plc::WriteCoils(const std::vector<bool> Data,const std::vector<uint16_t> Adrresses)
{
    if(Comn.Protocol == "McProtocol")
    {
        std::vector<uint8_t> DataToSend;
        for(auto BOOL:Data)
        {
            if(BOOL)
            {
                DataToSend.push_back(0x10);
            }
            else
            {
                DataToSend.push_back(0x00);
            }
        }
        // std::vector<uint8_t> ReturnValue = MCProtocol::write["B"](DataToSend,)

    }
    
}