#include "SiemensTags.hpp"

void SiemensBool:: write()
{
    std::vector<bool> Data;

    Data.push_back(Value);
    Client.Connect();
    Client.WriteCoils(Data,Byte,Bit,1);
    Client.Disconnect();
};

bool SiemensBool:: read()
{
     Client.Connect();
     Client.ReadCoils(Byte,Bit,1);
     


}