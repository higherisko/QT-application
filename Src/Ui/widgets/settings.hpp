#pragma once

#include <QWidget>
#include <QScrollArea>

class Settings : QWidget {
    Q_OBJECT

public:
    Settings(QWidget *parent = nullptr);

private:
    QScrollArea *mainArea;
};