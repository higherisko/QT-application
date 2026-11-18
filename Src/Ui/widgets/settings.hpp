#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>
#include "PlcSettings.hpp"

class Settings : public QWidget {
    Q_OBJECT

public:
    Settings(QWidget *parent = nullptr);
    void addWidget(QWidget *widget);

private:
    IpPortSelector *ipPortSelector;

    QVBoxLayout *mainLayout;

    QScrollArea *area;
    QWidget *container;
    QVBoxLayout *cLayout;
};