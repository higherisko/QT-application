#include "mainwindow.hpp"
#include <QApplication>
#include <QObject>
#include "PlcTags.hpp"
#include "PlcManager.hpp"
#include "QtToCpp.hpp"

class Aplication:public QObject

{
    Q_OBJECT
private:
    MainWindow w;
    PlcManager Plcs;
    QtAdapter QtAdapt;


    
public:
    Aplication();
    void ConnectSignals();
signals:
    void PlcAdded(QString Name);
    void SendPlcAdressSignal(QString Name);

public slots:
    void AddPlc(QString Name);
    void IpChangeSlot(QString Value);
    void PortChangeSlot(QString Value);
    void GetPlcAdressSlot(QString Value);
};