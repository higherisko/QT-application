#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include "PlcSettings.hpp"
#include "PLcNetworkingSettings.hpp"

class Settings : public QWidget
{
    Q_OBJECT

public:
    Settings(QWidget *parent = nullptr);
    void addWidget(QWidget *widget);

    NetworkSetting *ReturnipPortSelector() { return ipPortSelector; }
    addPlc *ReturnaddPlcWidget(){return addPlcWidget;}
private:
    NetworkSetting *ipPortSelector;
    addPlc *addPlcWidget;

    QVBoxLayout *mainLayout;

    QScrollArea *area;
    QWidget *container;
    QVBoxLayout *cLayout;

    void SettingWidgets();
};