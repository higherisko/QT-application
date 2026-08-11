#ifndef _MODBUSPARSER_H_
#define _MODBUSPARSER_H_

#include "Converter.h"
#include"ModbusFrame.h"
#include <unordered_map>
#include <functional>

class ModbusParser;
std::ostream &operator<<(std::ostream &Os,const ModbusParser &Rhs);

class MBAP
{
private:
public:
    uint16_t TransactionID; // Je to identifikacia cisla transakcie
    uint16_t ProtocolIdent; // Je to aby sme vedeli aky protokol bol pouzity pre modbus je to 0
    uint16_t Lenght;        // Tu zadavame Unit ID a PDU velkost pre PDU hlavicku
    uint8_t unitID;         // Je to nieco ako profbus adrres daneho zariadenia
    MBAP(uint16_t lenght, uint8_t unitid) : Lenght{lenght}, unitID{unitid}
    {
        TransactionID = 0;
        ProtocolIdent = 0;
    }
    std::vector<uint8_t> BuildMap()
    {
        std::vector<uint8_t> mbap;
        mbap.push_back(TransactionID >> 8);
        mbap.push_back(TransactionID & 0xFF);

        mbap.push_back(ProtocolIdent >> 8);
        mbap.push_back(ProtocolIdent & 0xFF);

        mbap.push_back(Lenght >> 8);
        mbap.push_back(Lenght & 0xFF);

        mbap.push_back(unitID);
        TransactionID++;
        return mbap;
    }
};

class PDU
{
private:
public:
    uint8_t FunctionCode; // tu urcujeme aku chcem funckiu napr 01 read coils
    uint16_t Adress;      // tu urcujeme adresu uz napr z db v siemens
    uint16_t Quantity_Value;    // tu urcujeme quantitu kolko registrov alebo coils chceme precitat... 
    //   pri single coil tu dame value ktoru chceme citat/pisat pri multiple je to quantita citanych / pisanych
    PDU(uint8_t functioncode = 0, uint16_t adress = 0, uint16_t quantity = 0)
        : FunctionCode{functioncode}, Adress{adress}, Quantity_Value{quantity}
    {
    }
    std::vector<uint8_t> PDUMap()
    {
        std::vector<uint8_t> Map;
        Map.push_back(FunctionCode);
        
        Map.push_back(Adress >> 8);
        Map.push_back(Adress & 0xFF);

        Map.push_back(Quantity_Value >> 8);
        Map.push_back(Quantity_Value & 0xFF);

        return Map;
    }
};

class ModbusParser
{
    private:
       MBAP MbapHead;
       PDU PduHead;
       ModbusFrame HandleFrame;
    public:
       ModbusParser();
       ~ModbusParser() = default;
       std::unordered_map<std::uint16_t,std::function<std::vector<uint8_t>(uint16_t,uint16_t)>> BuildMaps;
       void SetQuantityValue(uint16_t Value) {PduHead.Quantity_Value = Value;}
       void BuildFrame(const std::vector<uint8_t> &Data);
       friend std::ostream &operator<<(std::ostream &Os,const ModbusParser &Rhs);
       ModbusFrame GetHandleFrame() {return HandleFrame;}
       
       
};

#endif