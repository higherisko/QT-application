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

#include "widgets/credits.hpp"
#include "widgets/settings.hpp"
#include "widgets/ipportselector.hpp"

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    QPushButton *getConnectButton();

signals:
    void ipChanged(QString ip);
    void portChanged(QString port);

private:
    QVBoxLayout *mainLayout;
    QPushButton *connectButton;

    QMenu *fileMenu;
    QAction *quitAction;
    QAction *creditsAction;

    QMenu *settingsMenu;
    QAction *settingsAction;

    Credits *credits;

    Settings *settings;
    IpPortSelector *ipPortSelector;

    void setupWidgets();
    void setupMenus();
    void setupActions();
};