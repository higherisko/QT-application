#pragma once

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QFontMetrics>
#include <QSizePolicy>

class IpPortSelector : public QWidget {
    Q_OBJECT

public:
    IpPortSelector(QWidget *parent = nullptr);
    
private:
    QHBoxLayout *mainLayout;
    
    QLineEdit *lines[5];
    QLabel *dots[4];
    
private slots:
    void updateIp();
    void updatePort();

signals:
    void ipChanged(QString value);
    void portChanged(QString value);
};