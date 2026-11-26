#include "TagsAdapter.hpp"

// Cylinder
uint16_t Tags::AddCylinder(Cylinder &Cyll, const std::string &Name)
{
    auto Move = Cyll.Out_GetAdressMove();
    auto IsFWD = Cyll.In_GetAdressIsForward();
    auto IsBWD = Cyll.In_GetAdressIsBackward();

    if (Move == IsFWD || Move == IsBWD || IsBWD == IsFWD)
        return -4;

    auto It = Cylinders.find(Name);
    if (It != Cylinders.end())
        return -1;
    if (Move > Mems.BoolsSize || IsBWD > Mems.BoolsSize || IsFWD > Mems.BoolsSize)
        return -2;
    if (Mems.IsUsedCheckBool(Move) || Mems.IsUsedCheckBool(IsBWD) || Mems.IsUsedCheckBool(IsFWD))
        return -3;

    Mems.MemsBoolInit(false, Move);
    Mems.MemsBoolInit(false, IsBWD);
    Mems.MemsBoolInit(false, IsFWD);

    return 1;
}

int Tags::CylinderForward(const std::string &CyllName)
{
    auto it = Cylinders.find(CyllName);
    if (it != Cylinders.end())
    {
        Cylinders[CyllName].UpgradeMoveValue(true);
        // Mems.MemsBoolInit(true, Cylinders[CyllName].Out_GetAdressMove().at(0), Cylinders[CyllName].Out_GetAdressMove().at(1));
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
        // Mems.MemsBoolInit(false, Cylinders[CyllName].Out_GetAdressMove().at(0), Cylinders[CyllName].Out_GetAdressMove().at(1));
        return 1;
    }
    else
        return -1;
}

int Tags::SetCylindersSensors(const std::string &CyllName, const uint16_t &SensorCount, const uint16_t &Sensors_Move_ADress, const uint16_t &Sensor_FWD_Adress, const uint16_t &Sensor_BWD_Adress)
{
    auto it = Cylinders.find(CyllName);
    if (it != Cylinders.end())
    {
        if (Mems.IsUsedCheckBool(Sensors_Move_ADress) < 0)
            return -1;
        if (Mems.IsUsedCheckBool(Sensor_FWD_Adress) < 0)
            return -2;
        if(Mems.IsUsedCheckBool(Sensor_BWD_Adress) < 0)
            return -3;

        Cylinders.at(CyllName).SetIsBackawardAdress(Sensor_FWD_Adress);
        Cylinders[CyllName].SetIsForwardAdress(Sensors_Move_ADress);
        Cylinders[CyllName].SetMoveAdress(Sensors_Move_ADress);
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
