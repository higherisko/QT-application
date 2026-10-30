#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>

class Settings : public QWidget {
    Q_OBJECT

public:
    Settings(QWidget *parent = nullptr);
    void addWidget(QWidget *widget);

private:
    QVBoxLayout *mainLayout;

    QScrollArea *area;
    QWidget *container;
    QVBoxLayout *cLayout;
};