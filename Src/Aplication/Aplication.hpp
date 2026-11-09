#pragma once

#include <QApplication>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QMessageBox>

#include "mainwindow.hpp"
#include "PlcTags.hpp"
#include "PlcManager.hpp"
#include "QtToCpp.hpp"
#include "TcpClient.hpp"
#include <nlohmann/json.hpp>
class Aplication:public QObject

{
    Q_OBJECT
private:
    MainWindow w;
    PlcManager Plcs;
    QtAdapter QtAdapt;
    TcpClient tcpClient;
public:
    Aplication();
    void ConnectSignals();
signals:
    void PlcAdded(QString Name);
    void SendPlcAdressSignal(QString Name);
    void SendPlcPortSignal(QString Name);

    void TcpClientConnectToSignal(QString Ip,QString Port);
public slots:
    void AddPlc(QString Name);
    void IpChangeSlot(QString Value);
    void PortChangeSlot(QString Value);

    void TcpClientConnectSlot(bool Button);
    void GetPlcAdressSlot(QString Name);
};