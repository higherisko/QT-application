#pragma once

#include "McProtocolFrame.h"

struct Header
{
        // mcProtocol header
        uint16_t SubHeader;
        uint8_t Network_No;
        uint8_t PLC_No;
        uint16_t IO_No;
        uint8_t Station_No;
        uint16_t Request_Data_Lenght;
        uint16_t Monitoring_Timer;
        // Mcprotocl comands
        uint16_t Comand;
        uint16_t SubComand;
        uint8_t DeviceCode;
        uint16_t Adress1;
        uint8_t Adress2;
        uint16_t DevicePoints;
        std::vector<uint8_t> Map()
        {
                std::vector<uint8_t> map;

                // 1. Subheader (2 byty) - 50 00
                map.push_back(SubHeader & 0xFF);
                map.push_back((SubHeader >> 8) & 0xFF);

                // 2. Network No. (1 byt) - 00
                map.push_back(Network_No);

                // 3. PC No. (1 byt) - FF
                map.push_back(PLC_No);

                // 4. Destination Module I/O No. (2 byty) - FF 03
                map.push_back(IO_No & 0xFF);
                map.push_back((IO_No >> 8) & 0xFF);

                // 5. Destination Station No. (1 byt) - 00
                map.push_back(Station_No);

                // 6. Request Data Length (2 byty) - SEM IDE POČET BAJTOV OD TIMERU PO KONIEC DAT
                map.push_back(Request_Data_Lenght & 0xFF);
                map.push_back((Request_Data_Lenght >> 8) & 0xFF);

                // --- Odteraz sa počíta dĺžka (Request_Data_Length) ---

                // 7. CPU Monitoring Timer (2 byty) - 0A 00
                map.push_back(Monitoring_Timer & 0xFF);
                map.push_back((Monitoring_Timer >> 8) & 0xFF);

                // 8. Command (2 byty) - 01 14 (Write)
                map.push_back(Comand & 0xFF);
                map.push_back((Comand >> 8) & 0xFF);

                // 9. Subcommand (2 byty) - 01 00 (Bit)
                map.push_back(SubComand & 0xFF);
                map.push_back((SubComand >> 8) & 0xFF);

                // 10. Head Device (Address) (3 byty) - C8 00 00
                map.push_back(Adress1 & 0xFF);
                map.push_back((Adress1 >> 8) & 0xFF);
                map.push_back(Adress2); // Toto je ten tretí bajt adresy

                // 11. Device Code (1 byt) - 90 (M register)
                map.push_back(DeviceCode);

                // 12. Number of Device Points (2 byty) - 01 00
                map.push_back(DevicePoints & 0xFF);
                map.push_back((DevicePoints >> 8) & 0xFF);

                return map;
        }
};

class McProtocolParser;
std::ostream &operator<<(std::ostream &Os,const McProtocolParser &Rhs);
class McProtocolParser
{
private:
        Header HeadReq;
        McProtocolFrame PlcFrame;
public:
        McProtocolParser();
        ~McProtocolParser() = default;
        std::vector<uint8_t> ReadBitHead(const std::string &MemoryArea,const uint32_t&Adress,const uint16_t &Points);
        std::vector<uint8_t> WriteBitHead(const std::string &MemoryArea,const uint32_t &Adress,const uint16_t &Points);
        std::vector<uint8_t> WriteWordHead(const std::string &MemoryArea,const uint32_t &Adress,const uint16_t &Points);
        std::vector<uint8_t> ReadWordHead(const std::string &MemoryArea,const uint32_t&Adress,const uint16_t &Points);
        void CreateFrameToHandler(const std::vector<uint8_t> &InputFrame);
        friend std::ostream &operator<<(std::ostream &Os,const McProtocolParser &Rhs);
};