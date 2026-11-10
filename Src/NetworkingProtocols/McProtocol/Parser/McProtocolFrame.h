#pragma once

#include "Converter.h"
#include <vector>

class McProtocolFrame;
std::ostream &operator<<(std::ostream &Os, const McProtocolFrame &Rhs);

class McProtocolFrame
{
private:
    uint16_t SubHeader;
    uint16_t EndCode;
    std::vector<uint8_t> Data;

public:
    void SetSubHeader(const std::vector<uint8_t> &InputFrame) { SubHeader = (static_cast<uint16_t>(InputFrame.at(0))) | (static_cast<uint16_t>(InputFrame.at(1) << 8)); }
    void SetEndCode(const std::vector<uint8_t> &InputFrame) { EndCode = static_cast<uint16_t>(InputFrame[8]) | (static_cast<uint16_t>(InputFrame.at(9) << 8)); }
    void SetData(const std::vector<uint8_t> &InputFrame)
    {
        int i{11};
        for (i; i < InputFrame.size(); i++)
        {
            Data.push_back(InputFrame.at(i));
        }
    }
    friend std::ostream &operator<<(std::ostream &Os, const McProtocolFrame &Rhs);
};
