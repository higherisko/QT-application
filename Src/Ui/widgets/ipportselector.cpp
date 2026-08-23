#include "ipportselector.hpp"

IpPortSelector::IpPortSelector(QWidget *parent) : QWidget(parent) {
    mainLayout = new QHBoxLayout;
    setLayout(mainLayout);

    QString placeholder[] = {"127", "0", "0", "1", "0000"};

    int i = 0;
    for (auto &line : lines) {
        line = new QLineEdit(this);
        line->setPlaceholderText(placeholder[i]);
        line->setFrame(false);
        mainLayout->addWidget(line);
        
        if (i > 3) {
            QObject::connect(line, &QLineEdit::textChanged, this, &IpPortSelector::updatePort);
            break;
        }

        QObject::connect(line, &QLineEdit::textChanged, this, &IpPortSelector::updateIp);
        
        dots[i] = new QLabel((i < 3) ? "." : ":", this);
        mainLayout->addWidget(dots[i]);

        i++;
    }
}

void IpPortSelector::updateIp() {
    QString result;
    int i = 0;
    for (auto &line : lines) {
        for (QChar chr : line->text())
            if (chr.isLetter()) {
                line->setText("");
                return;
            }
        result += line->text();
        if (i >= 3)
            break;
        result += ".";
        i++;
    }
    emit ipChanged(result);
}

void IpPortSelector::updatePort() {
    for (QChar chr : lines[4]->text())
        if (chr.isLetter()) {
            lines[4]->setText("");
            return;
        }
    emit portChanged(lines[4]->text());
}