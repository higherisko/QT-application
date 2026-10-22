#include "QtToCpp.hpp"



std::string QtAdapter::QStringToStdString(QString Name)
{
    std::string ReturnValue;
    ReturnValue = Name.toStdString();
    return ReturnValue;
}