#include "PLcNetworkingSettings.hpp"

NetworkSetting::NetworkSetting(QWidget *parent) : QWidget(parent)
{

    // Setting all widgets
    mainLayout = new QHBoxLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    this->setObjectName("NetworkSetting");

    setLayout(mainLayout);
    TextsSet();
    SetGroups();

    StyleSet();
    LinesCreate();

    mainLayout->addWidget(IpBox);
    mainLayout->addWidget(PortBox);
    mainLayout->addWidget(ProtocolAndTransferBox);
    updateIp();
    updatePort();
    AllInstantConection();
}

void NetworkSetting::updateIp()
{
    QString result;
    int i = 0;
    for (auto &line : lines)
    {
        for (QChar chr : line->text())
            if (chr.isLetter())
            {
                line->setStyleSheet("QLineEdit { border: 2px solid red; border-radius: 4px; }");
                return;
            }
        line->setStyleSheet("");
        result += (line->text() == "") ? "0" : line->text();
        if (i >= 3)
            break;
        result += ".";
        i++;
    }
    emit ipChanged(result);
}

void NetworkSetting::updatePort()
{
    for (QChar chr : lines[4]->text())
        if (chr.isLetter())
        {
            lines[4]->setStyleSheet("QLineEdit { border: 2px solid red; border-radius: 4px; }");
            return;
        }
    lines[4]->setStyleSheet("");
    emit portChanged(lines[4]->text());
}

void NetworkSetting::TextsSet()
{
}

void NetworkSetting::SetGroups()
{
    // Protocol and transfer layer set
    ProtocolAndTransferMainLayout = new QVBoxLayout(this);
    ProtocolLayout = new QHBoxLayout(this);
    ProtocolAndTransferBox = new QGroupBox("Transfer settings", this);
    TransferLayout = new QHBoxLayout(this);

    ProtocolSetButton = new QPushButton("ChangeProtocol", this);
    TransferSetButton = new QPushButton("ChangeTransfer", this);
    ProtocolSelect = new QComboBox(this);
    TransferSelect = new QComboBox(this);
    ProtocolSelect->addItem("Modbus");
    ProtocolSelect->addItem("McProtocol");
    TransferSelect->addItem("TCP");
    TransferSelect->addItem("UDP");

    ProtocolLayout->addWidget(ProtocolSelect);
    ProtocolLayout->addWidget(ProtocolSetButton);
    TransferLayout->addWidget(TransferSelect);
    TransferLayout->addWidget(TransferSetButton);

    ProtocolAndTransferMainLayout->addLayout(ProtocolLayout);
    ProtocolAndTransferMainLayout->addLayout(TransferLayout);

    ProtocolAndTransferBox->setLayout(ProtocolAndTransferMainLayout);
    // Port set
    ChangePortButton = new QPushButton("Change Port", this);
    PortBox = new QGroupBox("Port", this);
    PortBoxLayout = new QVBoxLayout(this);
    PortBox->setObjectName("PortBox");
    PortBoxLayout->addWidget(ChangePortButton);
    PortBox->setLayout(PortBoxLayout);
    // Ip Set
    ChangeIpButton = new QPushButton("Change IP", this);
    IpBox = new QGroupBox("Ip", this);
    IpBoxLayout = new QHBoxLayout(this);
    IpVBoxLayout = new QVBoxLayout(this);
    IpBox->setObjectName("IpBox");
    IpBox->setLayout(IpVBoxLayout);
    IpVBoxLayout->addLayout(IpBoxLayout);
    IpVBoxLayout->addWidget(ChangeIpButton);
}

void NetworkSetting::PlcDisplayIpSlot(QString ip)
{
    auto It = ip.begin();
    QString Temp;
    int i{0};
    while (It != ip.end() && lines[i] != nullptr)
    {
        while (It != ip.end() && *It != ".")
        {
            Temp.push_back(*It);
            It++;
        }
        lines[i]->setText(Temp);
        Temp.clear();
        i++;
        if (It != ip.end())
            It++;
    }
}

void NetworkSetting::PlcDisplayPortSlot(QString port)
{
    lines[4]->setText(port);
}

void NetworkSetting::StyleSet()
{
    this->setStyleSheet(ActualStyle);
}

void NetworkSetting::LinesCreate()
{
    int i = 0;
    for (auto &line : lines)
    {
        line = new QLineEdit(this);
        line->setPlaceholderText("0");
        line->setFrame(false);
        line->setMaxLength(5);

        QFontMetrics fm(line->font());
        line->setFixedWidth(fm.horizontalAdvance("00000") + 20);

        if (i > 3)
        {
            line->setPlaceholderText("00000");
            PortBoxLayout->addWidget(line);
            break;
        }
        else
        {
            IpBoxLayout->addWidget(line);
        }

        // QObject::connect(line, &QLineEdit::textChanged, this, &NetworkSetting::updateIp);
        if (i < 3)
        {
            dots[i] = new QLabel(".", this);
            IpBoxLayout->addWidget(dots[i]);
        }

        i++;
    }
}

void NetworkSetting::AllInstantConection()
{
    // connect(ProtocolSelect, &QComboBox::currentIndexChanged, this, &NetworkSetting::PlcChangeDetect);
    QObject::connect(ChangeIpButton, &QPushButton::clicked, this, &NetworkSetting::updateIp);
    QObject::connect(ChangePortButton, &QPushButton::clicked, this, &NetworkSetting::updatePort);
    QObject::connect(ProtocolSetButton, &QPushButton::clicked, this, &NetworkSetting::ProtocolSelectDetect);
    QObject::connect(TransferSetButton, &QPushButton::clicked, this, &NetworkSetting::TransferSelectDetect);
}

void NetworkSetting::ProtocolSelectDetect(const bool Clicked)
{
    emit(ProtocolChangeSignal(ProtocolSelect->currentText()));
    QLabel *Debug = new QLabel;
    Debug->setText(ProtocolSelect->currentText());
    mainLayout->addWidget(Debug);
}

void NetworkSetting::TransferSelectDetect(const bool Clicked)
{
    emit(TransferChangeSignal(TransferSelect->currentText()));
}