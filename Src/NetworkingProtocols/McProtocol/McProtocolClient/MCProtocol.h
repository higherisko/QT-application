#ifndef _MCPROTOCOL_H_
#define _MCPROTOCOL_H_

#include "McProtocolParser.h"
#include "McHandler.h"
#include <functional>
#include <unordered_map>


class MCProtocol 
{
private:
        McProtocolParser McParser;
public:
        MCProtocol();
        ~MCProtocol() = default;
        std::vector<std::vector<uint8_t>> MemoryInit(std::vector<uint16_t> &Data);
        std::unordered_map<std::string,std::function <std::vector<uint8_t>(std::vector<uint8_t>,uint32_t&,uint16_t&,std::string)>> write;
        std::unordered_map<std::string,std::function <std::vector<uint8_t>(uint32_t&,uint16_t&,std::string)>> read;
        std::unordered_map<std::string,std::function <std::vector<uint8_t>(std::vector<uint8_t>,uint32_t&,uint16_t&,uint16_t&,std::string)>> WriteBW;
        McProtocolParser GetMcParser() {return McParser;}
        void DisplayFrameToHandle(){std::cout<<McParser;}
};

#endif