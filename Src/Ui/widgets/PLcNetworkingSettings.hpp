#pragma once

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QFontMetrics>
#include <QSizePolicy>
#include <QGroupBox>
#include <QComboBox>
#include <QPushButton>
#include <QScrollArea>
#include <QIcon>
#include <QHash>
#include <QFile>
#include <QApplication>

#include "Style.hpp"


class NetworkSetting : public QWidget
{
    Q_OBJECT

public:
    NetworkSetting(QWidget *parent = nullptr);
    void TextsSet();
    void SetGroups();
    void PlcSelectSet();
    QString GetCurrentPlc(){return CurrentPlc;}

private:
    QHBoxLayout *mainLayout;
    
    //Buttons in QScrollArea AddPlcs when adding new plc
    QHash<QString,QPushButton*> PlcsButtonMap;
    QString CurrentPlc;

    QPushButton *ChangeIpButton;
    QPushButton *ChangePortButton;
    QLineEdit *lines[5];
    QLabel *dots[3];
    QLabel *Texts[5];
    QGroupBox *IpBox;
    QHBoxLayout *IpBoxLayout;
    QVBoxLayout *IpVBoxLayout;
    QGroupBox *PortBox;
    QVBoxLayout *PortBoxLayout;
    //Protocol Select Setting
    QPushButton *ProtocolSetButton,*TransferSetButton;
    QComboBox *ProtocolSelect;
    QComboBox *TransferSelect;
    QVBoxLayout *ProtocolAndTransferMainLayout;
    QHBoxLayout *ProtocolLayout;
    QHBoxLayout *TransferLayout;
    QGroupBox *ProtocolAndTransferBox;

    //Setting page funstions
    void StyleSet();
    void LinesCreate();
    void AllInstantConection();

private slots:
    void updateIp();
    void updatePort();
public slots:
    void PlcDisplayIpSlot(QString ip);
    void PlcDisplayPortSlot(QString port);

    void ProtocolSelectDetect(const bool clicked);
    void TransferSelectDetect(const bool clicked);
signals:
    void ipChanged(QString value);
    void portChanged(QString value);
    void PlcChangedSignal(QString Name);

    void ProtocolChangeSignal(const QString Portocol);
    void TransferChangeSignal(const QString Transfer);
    
};