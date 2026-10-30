#include "ipportselector.hpp"

IpPortSelector::IpPortSelector(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QHBoxLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);
    TextsSet();
    SetIpGroup();
    PlcSelectSet();
    mainLayout->addWidget(PlcSelect);
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
        if (i<3)
            dots[i] = new QLabel(".", this);
        IpBoxLayout->addWidget(dots[i]);

        i++;
    }
    PortBoxLayout->addWidget(ChangePortButton);
    IpBox->setLayout(IpVBoxLayout);
    PortBox->setLayout(PortBoxLayout);
    IpVBoxLayout->addLayout(IpBoxLayout);
    IpVBoxLayout->addWidget(ChangeIpButton);

    mainLayout->addWidget(IpBox);
    mainLayout->addWidget(PortBox);
    updateIp();
    updatePort();
    connect(PlcSelect, &QComboBox::currentIndexChanged, this, &IpPortSelector::PlcChangeDetect);
    QObject::connect(ChangeIpButton, &QPushButton::clicked, this, &IpPortSelector::updateIp);
    QObject::connect(ChangePortButton, &QPushButton::clicked, this, &IpPortSelector::updatePort);
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

void IpPortSelector::SetIpGroup()
{
    ChangeIpButton = new QPushButton("Change IP", this);
    IpBox = new QGroupBox("Ip", this);
    IpBoxLayout = new QHBoxLayout(this);
    IpVBoxLayout = new QVBoxLayout(this);

    ChangePortButton = new QPushButton("Change Port",this);
    PortBox = new QGroupBox("Port", this);
    PortBoxLayout = new QVBoxLayout(this);
}

void IpPortSelector::PlcSelectSet()
{
    PlcSelect = new QComboBox;
}

void IpPortSelector::PlcSelectAddSlot(QString Name)
{
    PlcSelect->addItem(Name);
}

void IpPortSelector::PlcChangeDetect(int Index)
{
    emit PlcChangedSignal(PlcSelect->currentText());
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

void IpPortSelector::PlcDisplayPortSlot(QString port) {
    lines[4]->setText(port);
}
