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

<<<<<<< HEAD
    credits = new Credits(this);
=======
    ipLabel = new QLabel(centralWidget());
    mainLayout->addWidget(ipLabel, 0, Qt::AlignCenter);

    portLabel = new QLabel(centralWidget());
    mainLayout->addWidget(portLabel, 0, Qt::AlignCenter);
    
    settings = new Settings;
    
    ipPortSelector = new IpPortSelector(settings);
    settings->addWidget(ipPortSelector);
    
    QObject::connect(ipPortSelector, &IpPortSelector::ipChanged, this, &MainWindow::ipChanged);
    QObject::connect(ipPortSelector, &IpPortSelector::portChanged, this, &MainWindow::portChanged);
    
    QObject::connect(this, &MainWindow::ipChanged, ipLabel, &QLabel::setText);
    QObject::connect(this, &MainWindow::portChanged, portLabel, &QLabel::setText);
    

    credits = new Credits;
>>>>>>> 037877f (fixed a segmentation fault that tried assigning a non existent widget to a layout)
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