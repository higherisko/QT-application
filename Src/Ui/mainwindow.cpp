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

    auto ipSelect = new IpPortSelector(this);
    mainLayout->addWidget(ipSelect, 0, Qt::AlignCenter);

    auto ip = new QLabel(this);
    mainLayout->addWidget(ip, 0, Qt::AlignCenter);
    QObject::connect(ipSelect, &IpPortSelector::ipChanged, ip, &QLabel::setText);

    auto port = new QLabel(this);
    mainLayout->addWidget(port, 0, Qt::AlignCenter);
    QObject::connect(ipSelect, &IpPortSelector::portChanged, port, &QLabel::setText);


    credits = new Credits;
    settings = new Settings;
}

void MainWindow::setupMenus() {
    fileMenu = new QMenu;
    fileMenu->setTitle(tr("File"));
    menuBar()->addMenu(fileMenu);
}

void MainWindow::setupActions() {
    quitAction = fileMenu->addAction(QIcon::fromTheme(QIcon::ThemeIcon::ProcessStop), tr("Quit"), tr("Ctrl + Q"));
    QObject::connect(quitAction, &QAction::triggered, this, &QWidget::close);

    settingsAction = fileMenu->addAction(tr("Settings"));
    //QObject::connect(settingsAction, &QAction::triggered, settings, &QWidget::show);

    creditsAction = menuBar()->addAction(tr("Credits"));
    QObject::connect(creditsAction, &QAction::triggered, credits, &QWidget::show);

}

QPushButton *MainWindow::getConnectButton() {
    return connectButton;
}