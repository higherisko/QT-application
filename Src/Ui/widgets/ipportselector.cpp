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

        QObject::connect(line, &QLineEdit::textChanged, this, &IpPortSelector::updateIp);

        dots[i] = new QLabel((i < 3) ? "." : ":", this);
        IpBoxLayout->addWidget(dots[i]);

        i++;
    }
    
    IpBox->setLayout(IpBoxLayout);
    PortBox->setLayout(PortBoxLayout);
    mainLayout->addWidget(IpBox);
    mainLayout->addWidget(PortBox);
    updateIp();
    updatePort();
    connect(PlcSelect,&QComboBox::currentIndexChanged,this,&IpPortSelector::PlcChangeDetect);
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
    IpBox = new QGroupBox("Ip");
    IpBoxLayout = new QHBoxLayout;
    
    PortBox = new QGroupBox("Port");
    PortBoxLayout = new QHBoxLayout;
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

}