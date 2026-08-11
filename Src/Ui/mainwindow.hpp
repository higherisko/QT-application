#pragma once

#include <QApplication>

#include <QObject>
#include <QWidget>
#include <QMainWindow>

#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include <QLabel>

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QLabel *credits;
    QMenu *fileMenu;
    QAction *quitAction;
    QAction *creditsAction;

    void setupWidgets();
    void setupMenus();
    void setupActions();
};