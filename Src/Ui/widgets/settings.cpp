#include "settings.hpp"

Settings::Settings(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Settings");
    setObjectName("settingsWindow");

    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    area = new QScrollArea(this);
    area->setWidgetResizable(true);
    area->setObjectName("SettingsScroll");
    area->viewport()->setObjectName("SettingsWievPort");
    mainLayout->addWidget(area);

    container = new QWidget(area);
    container->setObjectName("SettingsConteiner");
    area->setWidget(container);

    cLayout = new QVBoxLayout;
    container->setLayout(cLayout);
}

void Settings::addWidget(QWidget *widget) {
    cLayout->addWidget(widget, 0, Qt::AlignHCenter);
    adjustSize();
    // setFixedSize(size());
}