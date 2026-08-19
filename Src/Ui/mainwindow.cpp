#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) {
    resize(300, 200);

    setupWidgets();
    setupMenus();
    setupActions();
}

void MainWindow::setupWidgets() {
    setCentralWidget(new QWidget(this));
    mainLayout = new QVBoxLayout;
    centralWidget()->setLayout(mainLayout);

    connectButton = new QPushButton("connect", centralWidget());
    mainLayout->addWidget(connectButton, 0, Qt::AlignCenter);

    credits = new Credits(this);
}

void MainWindow::setupMenus() {
    fileMenu = new QMenu;
    fileMenu->setTitle(tr("File"));
    menuBar()->addMenu(fileMenu);
}

void MainWindow::setupActions() {
    quitAction = fileMenu->addAction(QIcon::fromTheme(QIcon::ThemeIcon::ProcessStop), tr("Quit"), tr("Ctrl + Q"));
    QObject::connect(quitAction, &QAction::triggered, this, &QWidget::close);

    creditsAction = menuBar()->addAction(tr("Credits"));
    QObject::connect(creditsAction, &QAction::triggered, credits, &QWidget::show);
}

QPushButton *MainWindow::getConnectButton() {
    return connectButton;
}