#pragma once

#include "Converter.h"
#include "MemHandler.hpp"

class Memory
{
private:
    std::vector<uint16_t> Registers;
    MemHandler MemoryHandl;

    std::vector<bool> Booleans;

public:
    void MemsInit(const std::vector<uint16_t> &Data, const uint16_t &Adress);
    void MemsAtInit(const uint16_t &Data, const uint16_t &Adress);
    void RegistersInit(const uint16_t Lenght);

    std::vector<uint16_t> GetMems(const uint16_t &StartAdress, const uint16_t &Lenght);
    uint16_t GetMem1(const uint16_t &Adress);
    
    void BooleansInitAt(const uint16_t Lenght,const uint16_t StartByte,std::vector<bool> &Data);
    void BoolAtInit(const uint16_t &StartAdress,const uint16_t &BitStartAdress,const bool &Data);
    
    std::vector<bool>BooleansGet(){return Booleans;}
    bool BooleanGetAt(uint16_t &StartAdress){return Booleans.at(StartAdress);}

    void Display()
    {
        for (int i{}; i < Registers.size(); i++)
        {
            std::cout << "Data at " << i + 1 << " = " << Registers.at(i) << " ";
        }
        std::cout << std::endl;
    };
};