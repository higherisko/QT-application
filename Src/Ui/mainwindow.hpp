#pragma once

#include <QApplication>

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include <QMainWindow>

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QIcon>

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>

#include "widgets/credits.hpp"
#include "widgets/settings.hpp"
#include "widgets/ipportselector.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    QPushButton *getConnectButton();
    IpPortSelector *GetipPortSelector(){return ipPortSelector;}
    void AddPlcBuild();
    void PlcQComboBoxChangedBuild();

signals:
    void ipChanged(QString ip);
    void portChanged(QString port);
    void AddPlcSignal(QString Name);    //This func is used for qt adapter for sending name for new plc
    void PlcNameToIpSelectMenu(QString Name);
    void PlcQcomboBoxChangedSignal(QString Name);
private:
    QVBoxLayout *mainLayout;
    QGroupBox *AddPlcGroup;
    QPushButton *connectButton;
    QPushButton *AddPlcButton;       
    QLabel *ipLabel;
    QLabel *portLabel;
    QLabel *PlcAddedLabel;
    QVBoxLayout MainLayot;
    QVBoxLayout *AddPLcLayot;

    QLineEdit *AddPlcName;
    QMenu *fileMenu;
    QAction *quitAction;
    QAction *creditsAction;

    // QMenu *settingsMenu;
    QAction *settingsAction;

    Credits *credits;

    Settings *settings;
    IpPortSelector *ipPortSelector;

    void setupWidgets();
    void setupMenus();
    void setupActions();
public slots:
    void AddPlc();   //This slot react to button of AddPlc
    void PlcAdded(QString Name);
    void IpChangeSlot(QString Value);
    void PortChangeSlot(QString Value);
};