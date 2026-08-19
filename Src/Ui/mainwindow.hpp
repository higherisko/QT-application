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

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    QPushButton *getConnectButton();

private:
    QVBoxLayout *mainLayout;
    QPushButton *connectButton;

    QMenu *fileMenu;
    QAction *quitAction;
    QAction *creditsAction;

    Credits *credits;

    void setupWidgets();
    void setupMenus();
    void setupActions();
};