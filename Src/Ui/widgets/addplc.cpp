#include "addplc.hpp"

addPlc::addPlc(QWidget *parent) : QGroupBox("Add plc", parent) {
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);
    setMaximumHeight(150);

    addButton = new QPushButton("Add Plc", this);
    mainLayout->addWidget(addButton);

    nameEdit = new QLineEdit(this);
    nameEdit->setPlaceholderText("Set name");
    mainLayout->addWidget(nameEdit);

    statusLabel = new QLabel("No action", this);
    mainLayout->addWidget(statusLabel);

    QObject::connect(addButton, &QPushButton::clicked, this, &addPlc::AddPlc);
    QObject::connect(nameEdit, &QLineEdit::returnPressed, this, &addPlc::AddPlc);
}

void addPlc::AddPlc() {
    emit AddPlcSignal(nameEdit->text());
}

void addPlc::PlcAdded(QString Name) {
    if (Name != "Plc already exist !!")
        statusLabel->setText("Plc " + Name + " was succesufully added.");
    else
        statusLabel->setText(Name);
    if (Name != "Plc already exist !!")
        emit PlcNameToIpSelectMenu(Name);
}