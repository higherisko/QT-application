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

    ipLabel = new QLabel(centralWidget());
    mainLayout->addWidget(ipLabel, 0, Qt::AlignCenter);

    portLabel = new QLabel(centralWidget());
    mainLayout->addWidget(portLabel, 0, Qt::AlignCenter);
    
    settings = new Settings;
    
    settings->addWidget(ipPortSelector);
    ipPortSelector = new IpPortSelector(settings);
    
    QObject::connect(ipPortSelector, &IpPortSelector::ipChanged, this, &MainWindow::ipChanged);
    QObject::connect(ipPortSelector, &IpPortSelector::portChanged, this, &MainWindow::portChanged);
    
    QObject::connect(this, &MainWindow::ipChanged, ipLabel, &QLabel::setText);
    QObject::connect(this, &MainWindow::portChanged, portLabel, &QLabel::setText);
    

    credits = new Credits;
}

void MainWindow::setupMenus() {
    fileMenu = new QMenu("File", this);
    menuBar()->addMenu(fileMenu);

    // settingsMenu = new QMenu("Settings", this);
    // menuBar()->addMenu(settingsMenu);
}

void MainWindow::setupActions() {
    quitAction = fileMenu->addAction(QIcon::fromTheme(QIcon::ThemeIcon::ProcessStop), tr("Quit"), tr("Ctrl + Q"));
    QObject::connect(quitAction, &QAction::triggered, this, &QWidget::close);

    settingsAction = menuBar()->addAction(tr("Settings"));
    QObject::connect(settingsAction, &QAction::triggered, settings, &Settings::show);

    creditsAction = menuBar()->addAction(tr("Credits"));
    QObject::connect(creditsAction, &QAction::triggered, credits, &QWidget::show);

}

QPushButton *MainWindow::getConnectButton() {
    return connectButton;
}