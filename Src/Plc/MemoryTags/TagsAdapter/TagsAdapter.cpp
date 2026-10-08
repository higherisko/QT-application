#include "TagsAdapter.hpp"

// Cylinder
uint16_t Tags::AddCylinder(Cylinder &Cyll, const std::string &Name)
{
    auto Move = Cyll.GetAdressMove();
    auto IsFWD = Cyll.GetAdressIsForward();
    auto IsBWD = Cyll.GetAdressIsBackward();

    if (Cylinders.try_emplace(Name, Cyll).second)
    {
        if (Mems.IsUsedCheckBool(Move.at(0), Move.at(1)) == 1)
        {
            Mems.UseUpgradeBool(Move.at(0), Move.at(1));
            if (!IsFWD.empty())
            {
                if ((Mems.IsUsedCheckBool(IsFWD.at(0), IsFWD.at(1)) == 1))
                {
                    Mems.UseUpgradeBool(IsFWD.at(0), IsFWD.at(1));
                }
                else
                    return -2;
            }
            if (!IsBWD.empty())
            {
                if ((Mems.IsUsedCheckBool(IsBWD.at(0), IsBWD.at(1)) == 1))
                {
                    Mems.UseUpgradeBool(IsBWD.at(0), IsBWD.at(1));
                }
                else
                    return -3;
            }
        }
        else
            return -1;
    }
    else 
        return -4;
    return 1;
}

int Tags::CylinderForward(const std::string &CyllName)
{
    auto it = Cylinders.find(CyllName);
    if (it != Cylinders.end())
    {
        Cylinders[CyllName].UpgradeMoveValue(true);
        Mems.MemsBoolInit(true, Cylinders[CyllName].GetAdressMove().at(0), Cylinders[CyllName].GetAdressMove().at(1));
        return 1;
    }
    else
        return -1;
}

int Tags::CylinderBackward(const std::string &CyllName)
{
    auto it = Cylinders.find(CyllName);
    if (it != Cylinders.end())
    {
        Cylinders[CyllName].UpgradeMoveValue(false);
        Mems.MemsBoolInit(false, Cylinders[CyllName].GetAdressMove().at(0), Cylinders[CyllName].GetAdressMove().at(1));
        return 1;
    }
    else
        return -1;
}

int Tags::SetCylindersSensors(const std::string &CyllName, const uint16_t &SensorCount, const std::vector<uint16_t> &SensorsByteAndBit)
{
    auto it = Cylinders.find(CyllName);
    if (it != Cylinders.end())
    {
        if (Mems.IsUsedCheckBool(SensorsByteAndBit.at(0), SensorsByteAndBit.at(1)) == 1)
        {
            Cylinders[CyllName].SetIsForwardAdress(SensorsByteAndBit.at(0), SensorsByteAndBit.at(1));
            Mems.UseUpgradeBool(SensorsByteAndBit.at(0), SensorsByteAndBit.at(1));
        }
        else
            return -1;
        if (SensorCount == 2)
        {
            if (Mems.IsUsedCheckBool(SensorsByteAndBit.at(2), SensorsByteAndBit.at(3)) == 1)
            {
                Cylinders.at(CyllName).SetIsBackawardAdress(SensorsByteAndBit.at(2), SensorsByteAndBit.at(3));
                Mems.UseUpgradeBool(SensorsByteAndBit.at(2), SensorsByteAndBit.at(3));
                return 2;
            }
            else
            {
                Mems.UseEraseBool(SensorsByteAndBit.at(0), SensorsByteAndBit.at(1));
                return -2;
            }
        }
        else
            return 1;
    }
    return 0;
}

// Memory
int Tags::InitAllRegisters(const std::vector<uint16_t> &Data)
{
    Mems.MemsInit(Data);
    return 0;
}

int Tags::InitRegisterSize(const uint16_t &SizeInit)
{
    Mems.MemsSizeSet(SizeInit);
    return 0;
}
