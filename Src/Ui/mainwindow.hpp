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
#include "widgets/addplc.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    QPushButton *getConnectButton();
    IpPortSelector *GetipPortSelector(){return ipPortSelector;}
    addPlc *GetaddPlc(){return addPlcWidget;}
    void Debug(QString debug);

signals:
    void ipChanged(QString ip);
    void portChanged(QString port);
private:
    QVBoxLayout *mainLayout;
    QPushButton *connectButton;

    QMenu *fileMenu;
    QAction *quitAction;
    QAction *creditsAction;

    // QMenu *settingsMenu;
    QAction *settingsAction;

    Credits *credits;

    Settings *settings;
    IpPortSelector *ipPortSelector;
    addPlc *addPlcWidget;

    void setupWidgets();
    void setupMenus();
    void setupActions();
public slots:
    void IpChangeSlot(QString Value);
    void PortChangeSlot(QString Value);
};