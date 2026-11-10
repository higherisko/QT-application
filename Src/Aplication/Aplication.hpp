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
    const std::string ConfigPath = "C:/Users/cpp2m/Documents/QT-application/Src/Config/Config.json";
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