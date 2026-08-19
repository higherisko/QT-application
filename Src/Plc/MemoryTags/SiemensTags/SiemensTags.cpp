#include "SiemensTags.hpp"

void SiemensBool:: write()
{
    std::vector<bool> Data;

    Data.push_back(Value);
    Client.Connect("127.0.0.0",2500);
    Client.WriteCoils(Data,Byte,1);
    Client.Disconnect();
}