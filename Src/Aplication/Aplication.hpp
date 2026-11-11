#pragma once

#include <QApplication>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QDir>
#include <QCoreApplication>


#include "mainwindow.hpp"
#include "PlcTags.hpp"
#include "PlcManager.hpp"
#include "QtToCpp.hpp"
#include "TcpClient.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
class Aplication:public QObject

{
    Q_OBJECT
private:
    MainWindow w;
    PlcManager Plcs;
    QtAdapter QtAdapt;
    TcpClient tcpClient;
    nlohmann::ordered_json Config;
    std::string ConfigPath;

    void setConfigPath();
public:
    Aplication();
    void ConnectSignals();
    void AppConfig();
    void PlcConfig(const nlohmann::json Plc);
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