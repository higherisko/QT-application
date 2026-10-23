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

    ipLabel = new QLabel(centralWidget());
    mainLayout->addWidget(ipLabel, 0, Qt::AlignCenter);

    portLabel = new QLabel(centralWidget());
    mainLayout->addWidget(portLabel, 0, Qt::AlignCenter);

    settings = new Settings;

    ipPortSelector = new IpPortSelector(settings);
    settings->addWidget(ipPortSelector);

    QObject::connect(ipPortSelector, &IpPortSelector::ipChanged, this, &MainWindow::IpChangeSlot);
    QObject::connect(ipPortSelector, &IpPortSelector::portChanged, this, &MainWindow::PortChangeSlot);

    QObject::connect(ipPortSelector, &IpPortSelector::ipChanged, ipLabel, &QLabel::setText);
    QObject::connect(ipPortSelector, &IpPortSelector::portChanged, portLabel, &QLabel::setText);

    credits = new Credits;

    AddPlcBuild();
}

void MainWindow::setupMenus()
{
    fileMenu = new QMenu("File", this);
    menuBar()->addMenu(fileMenu);

    // settingsMenu = new QMenu("Settings", this);
    // menuBar()->addMenu(settingsMenu);
}

void MainWindow::setupActions()
{
    quitAction = fileMenu->addAction(QIcon::fromTheme(QIcon::ThemeIcon::ProcessStop), tr("Quit"), tr("Ctrl + Q"));
    QObject::connect(quitAction, &QAction::triggered, this, &QWidget::close);

    settingsAction = menuBar()->addAction(tr("Settings"));
    QObject::connect(settingsAction, &QAction::triggered, settings, &Settings::show);

    creditsAction = menuBar()->addAction(tr("Credits"));
    QObject::connect(creditsAction, &QAction::triggered, credits, &QWidget::show);
}

void MainWindow::AddPlcBuild()
{
    QLabel *QlineName = new QLabel;
    QlineName->setText("Set Name");
    PlcAddedLabel = new QLabel;
    PlcAddedLabel->setText("No Action.");

    AddPlcButton = new QPushButton("Add Plc", centralWidget());
    AddPlcButton->setMaximumSize(100,200);
    AddPlcGroup = new QGroupBox("Buttons");
    AddPlcGroup->setMaximumSize(300,300);
    AddPLcLayot = new QVBoxLayout;
    AddPlcName = new QLineEdit;

    AddPLcLayot->addWidget(AddPlcButton,0,Qt::AlignCenter);
    AddPLcLayot->addWidget(QlineName);
    AddPLcLayot->addWidget(AddPlcName,0,Qt::AlignCenter);
    AddPLcLayot->addWidget(PlcAddedLabel);
    AddPlcGroup->setLayout(AddPLcLayot);
    mainLayout->addWidget(AddPlcGroup,0,Qt::AlignTop);


    QObject::connect(AddPlcButton, &QPushButton::clicked, this, &MainWindow::AddPlc);
}

QPushButton *MainWindow::getConnectButton()
{
    return connectButton;
}

void MainWindow::AddPlc()
{
    
    emit AddPlcSignal(AddPlcName->text());
}

void MainWindow::PlcAdded(QString Name)
{
    PlcAddedLabel->setText(Name);
    QMetaObject::Connection PlcAddingConnect = connect(this,&MainWindow::PlcNameToIpSelectMenu,ipPortSelector,&IpPortSelector::PlcSelectAddSlot);
    emit PlcNameToIpSelectMenu(Name);
    disconnect(PlcAddingConnect);
}

void MainWindow::IpChangeSlot(QString Value)
{
    emit ipChanged(Value);
}

void MainWindow::PortChangeSlot(QString Value)
{
    emit portChanged(Value);
}