#pragma once
#include "ModbusClient.h"

class SiemensBool
{
    private:
       bool Value;
       std::string Name;
       uint16_t Byte;
       uint16_t Bit;
       ModbusClient Client;
    public:
       void ValueSet(const bool Data){Value = Data;}
       bool ValueGet(){return Value;}
       void ByteSet(uint16_t ByteSet){Byte = ByteSet;}
       uint16_t ByteGet(){return Byte;}
       void BitSet(const uint16_t BitSet) {Bit = BitSet;}
       uint16_t ButGet() {return Bit;}
       void NameSet(const std::string NameSet) {Name = NameSet;}
       std::string NameGet() {return Name;}
       void write();
       SiemensBool () = default;
       ~SiemensBool () {Client.Disconnect();}


};
