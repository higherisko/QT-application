#include "MCProtocol.h"

MCProtocol::MCProtocol()
{
    write["B"] = [this](std::vector<uint8_t> Data, uint32_t &Adress, uint16_t &Lenght, std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.WriteBitHead(Register, Adress, Lenght);
        ToSend.insert(ToSend.end(), Data.begin(), Data.end());
        return ToSend;
    };
    write["W"] = [this](std::vector<uint8_t> Data, uint32_t &Adress, uint16_t &Lenght, std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.WriteWordHead(Register, Adress, Lenght);

        return ToSend;
    };
    read["B"] = [this](uint32_t &Adress, uint16_t &Lenght, std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.ReadBitHead(Register, Adress, Lenght);

        return ToSend;
    };
    read["W"] = read["B"] = [this](uint32_t &Adress, uint16_t &Lenght, std::string Register)
    {
        std::vector<uint8_t> ToSend = McParser.ReadWordHead(Register, Adress, Lenght);

        return ToSend;
    };
    WriteBW["BW"] = [this](std::vector<uint8_t> Data, uint32_t &Adress, uint16_t &Bit, uint16_t &Lenght, std::string Register)
    {
        std::vector<uint16_t> Registers;
        uint16_t LenghtBool = ((Lenght + 15) / 16) + 1;
        std::vector<uint8_t> ToSend = McParser.WriteWordHead(Register, Adress, LenghtBool);
        for (uint16_t i{0}; i < Data.size(); i++)
        {
        }

        return ToSend;
    };
}

std::vector<std::vector<uint8_t>> MCProtocol::MemoryInit(std::vector<uint16_t> &Data)
{
    uint32_t Adrres = 6000;
    uint16_t Lenght = 3000;
    std::vector<std::vector<uint8_t>> ReturnValue;
    ReturnValue.push_back(MCProtocol::read["B"](Adrres, Lenght, "M"));
    ReturnValue.push_back(MCProtocol::read["W"](Adrres, Lenght, "D"));
    return ReturnValue;
}
