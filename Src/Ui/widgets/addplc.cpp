#include "addplc.hpp"

addPlc::addPlc(QWidget *parent)
{
    mainLayout = new QVBoxLayout;
    this->setLayout(mainLayout);
    this->setStyleSheet(ActualStyle);

    PlcSelectSet();
    PlcAddSet();

    QObject::connect(addButton, &QPushButton::clicked, this, &addPlc::AddPlc);
    QObject::connect(nameEdit, &QLineEdit::returnPressed, this, &addPlc::AddPlc);
}

void addPlc::PlcAddSet()
{
    AddPlcBox = new QGroupBox("AddPlc",this);
    AddPlcLayout = new QHBoxLayout(this);

    addButton = new QPushButton("Add Plc", this);
    AddPlcLayout->addWidget(addButton);

    nameEdit = new QLineEdit(this);
    nameEdit->setPlaceholderText("Set name");
    AddPlcLayout->addWidget(nameEdit);

    statusLabel = new QLabel("No action", this);
    AddPlcLayout->addWidget(statusLabel);

    AddPlcBox->setLayout(AddPlcLayout);
    mainLayout->addWidget(AddPlcBox);
}

void addPlc::AddPlc()
{
    emit AddPlcSignal(nameEdit->text());
}

void addPlc::PlcAdded(QString Name)
{
    if (Name != "Plc already exist !!")
    {
        statusLabel->setText("Plc " + Name + " was succesufully added.");
        // This signal is connected with PlcSelectAddSlot in IpPortSelector
        emit PlcNameToIpSelectMenu(Name);
    }
    else
        statusLabel->setText(Name);
}

void addPlc::PlcSelectSet()
{
    PlcsContainer = new QWidget(this);
    PlcsLayot = new QVBoxLayout(this);
    PlcsContainer->setLayout(PlcsLayot);
    PlcsContainer->resize(100, 50);
    PlcsContainer->setObjectName("PlcsBox");

    AllPlcs = new QScrollArea(this);
    AllPlcs->setWidget(PlcsContainer);
    AllPlcs->setWidgetResizable(true);
    AllPlcs->setMinimumSize(200, 100);
    AllPlcs->setObjectName("PlcsScroll");
    QLabel *PlcsText = new QLabel("All Plcs");
    PlcsLayot->addWidget(PlcsText, 0, Qt::AlignTop | Qt::AlignCenter);

    mainLayout->addWidget(AllPlcs);
}

void addPlc::PlcSelectAddSlot(QString Name)
{
    QHash<QString, QPushButton *>::Iterator It = PlcsButtonMap.find(Name);
    if (It != PlcsButtonMap.end() && !PlcsButtonMap.isEmpty())
    {
        return;
    }
    QPushButton *NewPlc = new QPushButton(Name, PlcsContainer);
    NewPlc->setObjectName(Name);
    NewPlc->addAction(Name);
    PlcsButtonMap.insert_or_assign(Name, NewPlc);
    PlcsLayot->addWidget(NewPlc);
    // PlcsButtonMap[Name]->setStyleSheet("background-color: #516179;");
    QObject::connect(PlcsButtonMap[Name], &QPushButton::clicked, this, &addPlc::PlcChangeDetect);
}

void addPlc::PlcChangeDetect(int Index)
{
    QObject *Obj = sender();
    QPushButton *Button = qobject_cast<QPushButton *>(Obj);
    CurrentPlc = Button->objectName();
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
    emit PlcChangedSignal(CurrentPlc);
}