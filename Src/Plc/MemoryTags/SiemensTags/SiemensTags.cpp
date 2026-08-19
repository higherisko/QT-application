#include "SiemensTags.hpp"

void SiemensBool:: write()
{
    std::vector<bool> Data;

    Data.push_back(Value);
    Client.Connect("127.0.0.1",2505);
    Client.WriteCoils(Data,Byte,1);
    Client.Disconnect();
}