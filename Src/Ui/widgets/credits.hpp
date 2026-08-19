#pragma once

#include <QWidget>
#include <QScrollArea>

#include <QVBoxLayout>
#include <QSizePolicy>

#include <QLabel>

class Credits : public QWidget {
    Q_OBJECT

public:
    explicit Credits(QWidget *parent = nullptr);
    void addWidget(QWidget *widget);

private:
    QVBoxLayout *mainLayout;

    QLabel *title;
    QScrollArea *area;
    QWidget *container;
    QVBoxLayout *cLayout;
};

class CreditLabel : public QWidget {
    Q_OBJECT

public:
    explicit CreditLabel(QString user, QString desc, QWidget *parent = nullptr);

private:
    QVBoxLayout *mainLayout;
    QLabel *name;
    QLabel *description;
};