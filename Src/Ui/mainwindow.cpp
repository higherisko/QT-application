#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) {
    resize(800, 600);

    setupWidgets();
    setupActions();
    setupMenus();
}

void MainWindow::setupWidgets() {
    setCentralWidget(new QWidget);

    credits = new QLabel(tr("NASI DRAHOCENNY DEVELOPERI\n\nViliam Tabaček - šikovný chlapec, ktorý je múdry a pekný\nKristian Tabaček - Backend alebo take cosi"));
    credits->setAlignment(Qt::AlignTop);
    credits->setFixedSize(500, 300);
}

void MainWindow::setupActions() {
    quitAction = new QAction;
    quitAction->setText(tr("Quit"));
    quitAction->setShortcut(tr("Ctrl + Q"));
    QObject::connect(quitAction, &QAction::triggered, this, &QWidget::close);

    creditsAction = new QAction;
    creditsAction->setText(tr("Credits"));
    QObject::connect(creditsAction, &QAction::triggered, credits, &QLabel::show);
}

void MainWindow::setupMenus() {
    fileMenu = new QMenu;
    fileMenu->setTitle(tr("File"));
    fileMenu->addAction(quitAction);
    menuBar()->addMenu(fileMenu);

    menuBar()->addAction(creditsAction);
}