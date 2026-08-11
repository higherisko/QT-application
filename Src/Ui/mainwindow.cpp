#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) {
    resize(600,800);

    setupActions();
    setupMenus();
}

void MainWindow::setupActions() {
    quitAction = new QAction;
    quitAction->setText(tr("Quit"));
    quitAction->setShortcut(tr("Ctrl + Q"));
    QObject::connect(quitAction, &QAction::triggered, this, &QWidget::close);
}

void MainWindow::setupMenus() {
    fileMenu = new QMenu;
    fileMenu->setTitle(tr("File"));
    fileMenu->addAction(quitAction);
    menuBar()->addMenu(fileMenu);
}