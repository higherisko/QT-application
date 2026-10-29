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
            QObject::connect(line, &QLineEdit::textChanged, this, &IpPortSelector::updatePort);
            PortBoxLayout->addWidget(line);
            break;
        }
        else
        {
            IpBoxLayout->addWidget(line);
        }

        // QObject::connect(line, &QLineEdit::textChanged, this, &IpPortSelector::updateIp);

        dots[i] = new QLabel((i < 3) ? "." : ":", this);
        IpBoxLayout->addWidget(dots[i]);

        i++;
    }

    IpBox->setLayout(IpBoxLayout);
    PortBox->setLayout(PortBoxLayout);
    IpBoxLayout->addWidget(ChangeIpButton);
    mainLayout->addWidget(IpBox);
    mainLayout->addWidget(PortBox);
    updateIp();
    updatePort();
    connect(PlcSelect, &QComboBox::currentIndexChanged, this, &IpPortSelector::PlcChangeDetect);
    QObject::connect(ChangeIpButton, &QPushButton::clicked, this, &IpPortSelector::updateIp);
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

    PortBox = new QGroupBox("Port", this);
    PortBoxLayout = new QHBoxLayout(this);
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

void IpPortSelector::PlcChangeIp(QString Name)
{
    auto It = Name.begin();
    QString Temp;
    int i{0};
    while (It != Name.end() && lines[i] != nullptr)
    {
        while (It != Name.end() && *It != ".")
        {
            Temp.push_back(*It);
            It++;
        }
        lines[i]->setText(Temp);
        Temp.clear();
        i++;
        if (It != Name.end())
            It++;
    }
    QLabel *Debug = new QLabel;
    Debug->setText(Name);
    mainLayout->addWidget(Debug);
}