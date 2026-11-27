#include "TagsAdapter.hpp"

// Cylinder
std::string Tags::AddCylinder(Cylinder &Cyll, const std::string &Name)
{
    auto Move = Cyll.GetAdressMove();
    auto IsFWD = Cyll.GetAdressIsForward();
    auto IsBWD = Cyll.GetAdressIsBackward();

    if (Move == IsFWD || Move == IsBWD || IsBWD == IsFWD)
        return "Input adresses are same!";

    auto It = Cylinders.find(Name);
    if (It != Cylinders.end())
        return "Cylinder with " + Name + " Alerady exists!";
    for (auto &Adress : AdressUsed)
    {
        if (Adress == Cyll.GetAdressIsBackward())
            return "Adress for Backward already used!";
        if (Adress == Cyll.GetAdressIsForward())
            return "Adress for Forward already used!";
        if (Adress == Cyll.GetAdressMove())
            return "Adress for Move already used!";
    }

    Cylinders.try_emplace(Name);

    return "Cylinder added";
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

std::string Tags::SetCylindersSensors(const std::string &CyllName, const uint16_t &SensorCount, const uint16_t &Sensors_Move_ADress, const uint16_t &Sensor_FWD_Adress, const uint16_t &Sensor_BWD_Adress)
{
    auto it = Cylinders.find(CyllName);
    if (it != Cylinders.end())
    {
        for (auto &Adress : AdressUsed)
        {
            if (Adress == Sensor_BWD_Adress)
                return "Adress for Backward already used!";
            if (Adress == Sensor_FWD_Adress)
                return "Adress for Forward already used!";
            if (Adress == Sensors_Move_ADress)
                return "Adress for Move already used!";
        }

        Cylinders.at(CyllName).SetIsBackawardAdress(Sensor_FWD_Adress);
        Cylinders[CyllName].SetIsForwardAdress(Sensors_Move_ADress);
        Cylinders[CyllName].SetMoveAdress(Sensors_Move_ADress);
    }

    return "Cylinder not found!";
}


