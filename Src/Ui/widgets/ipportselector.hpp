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



class IpPortSelector : public QWidget
{
    Q_OBJECT

public:
    IpPortSelector(QWidget *parent = nullptr);
    void TextsSet();
    void SetIpGroup();
    void PlcSelectSet();
    QComboBox* GetPlcSelect(){return PlcSelect;}

private:
    QHBoxLayout *mainLayout;
    QHash<QString,QPushButton*> PlcsButtonMap;

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
    QComboBox *PlcSelect;
    QScrollArea *AllPlcs;
    QWidget *PlcsContainer;
    QVBoxLayout *PlcsLayot;


private slots:
    void updateIp();
    void updatePort();
public slots:
    void PlcSelectAddSlot(QString Name);
    void PlcChangeDetect(int Index);
    void PlcDisplayIpSlot(QString ip);
    void PlcDisplayPortSlot(QString port);
signals:
    void ipChanged(QString value);
    void portChanged(QString value);
    void PlcChangedSignal(QString value);
    
};