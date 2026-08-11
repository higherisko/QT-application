#pragma once

#include <QApplication>

#include <QObject>
#include <QWidget>
#include <QMainWindow>

#include <QMenu>
#include <QMenuBar>
#include <QAction>

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QMenu *fileMenu;
    QAction *quitAction;

    void setupMenus();
    void setupActions();
};