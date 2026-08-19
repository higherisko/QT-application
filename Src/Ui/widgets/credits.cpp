#include "credits.hpp"

Credits::Credits(QWidget *parent) : QWidget(parent) {
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    title = new QLabel("Kredity", this);
    title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    mainLayout->addWidget(title, 0, Qt::AlignHCenter);

    area = new QScrollArea(this);
    area->setFrameStyle(QFrame::NoFrame);
    mainLayout->addWidget(area);
    
    container = new QWidget(area);
    area->setWidget(container);

    cLayout = new QVBoxLayout;
    container->setLayout(cLayout);
}

void Credits::addWidget(QWidget *widget) {
    cLayout->addWidget(widget);
}

CreditLabel::CreditLabel(QString user, QString desc, QWidget *parent) : QWidget(parent) {
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    name = new QLabel();
}