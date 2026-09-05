#include "SiemensTags.hpp"

void SiemensBool:: write()
{
    std::vector<bool> Data;

    Data.push_back(Value);
    Client.Connect();
    Client.WriteCoils(Data,Byte,1);
    Client.Disconnect();
}