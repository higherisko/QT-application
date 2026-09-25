#include "mainwindow.hpp"
#include <QApplication>
#include <QObject>
#include "PlcTags.hpp"

class Aplication:public QObject

{
    Q_OBJECT
private:
    MainWindow w;

    
public:
    Aplication();
};