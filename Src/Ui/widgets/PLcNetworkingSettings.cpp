#include "PLcNetworkingSettings.hpp"

IpPortSelector::IpPortSelector(QWidget *parent) : QWidget(parent)
{

    // Setting all widgets
    mainLayout = new QHBoxLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    this->setObjectName("IpPortSelector");

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

void IpPortSelector::updateIp()
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

void IpPortSelector::updatePort()
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

void IpPortSelector::TextsSet()
{
}

void IpPortSelector::SetGroups()
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

void IpPortSelector::PlcDisplayIpSlot(QString ip)
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

void IpPortSelector::PlcDisplayPortSlot(QString port)
{
    lines[4]->setText(port);
}

void IpPortSelector::StyleSet()
{
    this->setStyleSheet(ActualStyle);
}

void IpPortSelector::LinesCreate()
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

        // QObject::connect(line, &QLineEdit::textChanged, this, &IpPortSelector::updateIp);
        if (i < 3)
        {
            dots[i] = new QLabel(".", this);
            IpBoxLayout->addWidget(dots[i]);
        }

        i++;
    }
}

void IpPortSelector::AllInstantConection()
{
    // connect(ProtocolSelect, &QComboBox::currentIndexChanged, this, &IpPortSelector::PlcChangeDetect);
    QObject::connect(ChangeIpButton, &QPushButton::clicked, this, &IpPortSelector::updateIp);
    QObject::connect(ChangePortButton, &QPushButton::clicked, this, &IpPortSelector::updatePort);
    QObject::connect(ProtocolSetButton, &QPushButton::clicked, this, &IpPortSelector::ProtocolSelectDetect);
    QObject::connect(TransferSetButton, &QPushButton::clicked, this, &IpPortSelector::TransferSelectDetect);
}

void IpPortSelector::ProtocolSelectDetect(const bool Clicked)
{
    emit(ProtocolChangeSignal(ProtocolSelect->currentText()));
    QLabel *Debug = new QLabel;
    Debug->setText(ProtocolSelect->currentText());
    mainLayout->addWidget(Debug);
}

void IpPortSelector::TransferSelectDetect(const bool Clicked)
{
    emit(TransferChangeSignal(TransferSelect->currentText()));
}