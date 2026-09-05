#include "ipportselector.hpp"

IpPortSelector::IpPortSelector(QWidget *parent) : QWidget(parent) {
    mainLayout = new QHBoxLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);

    int i = 0;
    for (auto &line : lines) {
        line = new QLineEdit(this);
        line->setPlaceholderText("0");
        line->setFrame(false);
        line->setMaxLength(5);

        QFontMetrics fm(line->font());
        line->setFixedWidth(fm.horizontalAdvance("00000")+20);

        mainLayout->addWidget(line);
        
        if (i > 3) {
            line->setPlaceholderText("00000");
            QObject::connect(line, &QLineEdit::textChanged, this, &IpPortSelector::updatePort);
            break;
        }

        QObject::connect(line, &QLineEdit::textChanged, this, &IpPortSelector::updateIp);
        
        dots[i] = new QLabel((i < 3) ? "." : ":", this);
        mainLayout->addWidget(dots[i]);

        i++;
    }

    updateIp();
    updatePort();
}

void IpPortSelector::updateIp() {
    QString result;
    int i = 0;
    for (auto &line : lines) {
        for (QChar chr : line->text())
            if (chr.isLetter()) {
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

void IpPortSelector::updatePort() {
    for (QChar chr : lines[4]->text())
        if (chr.isLetter()) {
            lines[4]->setStyleSheet("QLineEdit { border: 2px solid red; border-radius: 4px; }");
            return;
        }
    lines[4]->setStyleSheet("");
    emit portChanged(lines[4]->text());
}