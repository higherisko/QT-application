#include "ipportselector.hpp"

IpPortSelector::IpPortSelector(QWidget *parent) : QWidget(parent)
{

    // Setting all widgets
    AllPlcs = new QScrollArea(this);
    mainLayout = new QHBoxLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);
    TextsSet();
    SetIpGroup();
    PlcSelectSet();
    mainLayout->addWidget(AllPlcs);
    int i = 0;

    QFile file("C:/Users/cpp2m/Documents/QT-application/Src/Ui/Styles/PlcsButton.qss");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        Style = file.readAll();
        PlcsContainer->setStyleSheet(Style);
        file.close();
    }
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

    ChangePortButton = new QPushButton("Change Port", this);
    PortBox = new QGroupBox("Port", this);
    PortBoxLayout = new QVBoxLayout(this);
}

void IpPortSelector::PlcSelectSet()
{
    PlcSelect = new QComboBox;

    PlcsContainer = new QWidget(this);
    PlcsLayot = new QVBoxLayout(this);
    PlcsContainer->setLayout(PlcsLayot);
    PlcsContainer->resize(100, 50);

    AllPlcs->setWidget(PlcsContainer);
    AllPlcs->setWidgetResizable(true);
    AllPlcs->setMinimumSize(200, 100);
    QLabel *PlcsText = new QLabel("All Plcs");
    PlcsLayot->addWidget(PlcsText, 0, Qt::AlignTop | Qt::AlignCenter);
}

void IpPortSelector::PlcSelectAddSlot(QString Name)
{
    QHash<QString, QPushButton *>::Iterator It = PlcsButtonMap.find(Name);
    if (It != PlcsButtonMap.end() && !PlcsButtonMap.isEmpty())
    {
        return;
    }
    QPushButton *NewPlc = new QPushButton(Name, PlcsContainer);
    NewPlc->addAction(Name);
    PlcsButtonMap.insert_or_assign(Name, NewPlc);
    PlcsLayot->addWidget(NewPlc);
    // PlcsButtonMap[Name]->setStyleSheet("background-color: #516179;");
    connect(PlcsButtonMap[Name], &QPushButton::clicked, this, &IpPortSelector::PlcChangeDetect);
}

void IpPortSelector::PlcChangeDetect(int Index)
{
    QObject *Obj = sender();
    QPushButton *Button = qobject_cast<QPushButton *>(Obj);
    for (auto &button : PlcsButtonMap)
    {
        button->setProperty("active", false);
        button->style()->unpolish(button);
        button->style()->polish(button);
        button->update();
    }
    Button->setProperty("active", true);
    Button->style()->unpolish(Button);
    Button->style()->polish(Button);
    Button->update();
    emit PlcChangedSignal("");
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
