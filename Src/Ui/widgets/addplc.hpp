#pragma once
#include <QGroupBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

class addPlc : public QGroupBox {
    Q_OBJECT

public:
    explicit addPlc(QWidget *parent = nullptr);

signals:
    void AddPlcSignal(QString Name);    //This func is used for qt adapter for sending name for new plc
    void PlcNameToIpSelectMenu(QString Name);
    void PlcQcomboBoxChangedSignal(QString Name);

public slots:
    void AddPlc();   //This slot react to button of AddPlc
    void PlcAdded(QString Name);

private:
    QVBoxLayout *mainLayout;
    QPushButton *addButton;
    QLineEdit *nameEdit;
    QLabel *statusLabel;
};
