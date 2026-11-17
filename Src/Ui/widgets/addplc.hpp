#pragma once

#include <QObject>
#include <QWidget>
#include <QStyle>
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QScrollArea>
#include <QHash>
#include "Style.hpp"

class addPlc : public QWidget
{
    Q_OBJECT

public:
    explicit addPlc(QWidget *parent = nullptr);
    QString GetCurrentPlc() { return CurrentPlc; }
    void PlcSelectSet();
    void PlcAddSet();
signals:
    void AddPlcSignal(QString Name); // This func is used for qt adapter for sending name for new plc
    void PlcNameToIpSelectMenu(QString Name);
    void PlcQcomboBoxChangedSignal(QString Name);

    void PlcChangedSignal(QString Name);

public slots:
    void AddPlc(); // This slot react to button of AddPlc
    void PlcAdded(QString Name);

    void PlcSelectAddSlot(QString Name);
    void PlcChangeDetect(int Index);

private:
    QGroupBox *AddPlcBox;
    QHBoxLayout *AddPlcLayout;
    QVBoxLayout *mainLayout;
    QPushButton *addButton;
    QLineEdit *nameEdit;
    QLabel *statusLabel;

    // All needed settings for QScrollArea
    QString CurrentPlc;
    QHash<QString, QPushButton *> PlcsButtonMap;

    QScrollArea *AllPlcs;
    QWidget *PlcsContainer;
    QVBoxLayout *PlcsLayot;
};
