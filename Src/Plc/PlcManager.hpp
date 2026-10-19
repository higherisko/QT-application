#pragma once

#include "Plc.hpp"


class PlcManager
{
    private:
        std::unordered_map<std::string ,Plc>  Plcs;
    public:
        void AddPlc(const std::string Name);
};