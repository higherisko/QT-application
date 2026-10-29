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

    QPushButton *ChangeIpButton;
    QLineEdit *lines[5];
    QLabel *dots[4];
    QLabel *Texts[5];
    QGroupBox *IpBox;
    QHBoxLayout *IpBoxLayout;
    QVBoxLayout *IpVBoxLayot;
    QGroupBox *PortBox;
    QHBoxLayout *PortBoxLayout;
    QComboBox *PlcSelect;

private slots:
    void updateIp();
    void updatePort();
public slots:
    void PlcSelectAddSlot(QString Name);
    void PlcChangeDetect(int Index);
    void PlcChangeIp(QString ip);
signals:
    void ipChanged(QString value);
    void portChanged(QString value);
    void PlcChangedSignal(QString value);
    
};