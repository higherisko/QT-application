#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
{
    resize(300, 200);
    setupWidgets();
    setupMenus();
    setupActions();
}

void MainWindow::setupWidgets()
{
    setCentralWidget(new QWidget(this));
    mainLayout = new QVBoxLayout;
    centralWidget()->setLayout(mainLayout);

    connectButton = new QPushButton("connect", centralWidget());
    mainLayout->addWidget(connectButton, 0, Qt::AlignCenter);

    settings = new Settings;

    addPlcWidget = new addPlc(settings);
    settings->addWidget(addPlcWidget);

    ipPortSelector = new IpPortSelector(settings);
    settings->addWidget(ipPortSelector);

    QObject::connect(ipPortSelector, &IpPortSelector::ipChanged, this, &MainWindow::IpChangeSlot);
    QObject::connect(ipPortSelector, &IpPortSelector::portChanged, this, &MainWindow::PortChangeSlot);
    QObject::connect(addPlcWidget, &addPlc::PlcNameToIpSelectMenu, addPlcWidget, &addPlc::PlcSelectAddSlot);

    credits = new Credits;
}

void MainWindow::setupMenus()
{
    fileMenu = new QMenu("File", this);
    menuBar()->addMenu(fileMenu);

    SettingsMenu= new QMenu("Settings", this);
    menuBar()->addMenu(SettingsMenu);
}

void MainWindow::setupActions()
{
    quitAction = fileMenu->addAction(QIcon::fromTheme(QIcon::ThemeIcon::ProcessStop), tr("Quit"), tr("Ctrl + Q"));
    QObject::connect(quitAction, &QAction::triggered, this, &QWidget::close);

    settingsPlcAction = SettingsMenu->addAction(tr("Plc Settings"));

    QObject::connect(settingsPlcAction, &QAction::triggered, settings, &Settings::show);
    settings->resize(1000, 600);
    settings->setStyleSheet(ActualStyle);

    creditsAction = menuBar()->addAction(tr("Credits"));
    QObject::connect(creditsAction, &QAction::triggered, credits, &QWidget::show);
}

QPushButton *MainWindow::getConnectButton()
{
    return connectButton;
}

void MainWindow::IpChangeSlot(QString Value)
{
    emit ipChanged(Value);
}

void MainWindow::PortChangeSlot(QString Value)
{
    emit portChanged(Value);
}

void MainWindow::Debug(QString debug)
{
    QLabel *Label = new QLabel(debug);
    mainLayout->addWidget(Label);
}
