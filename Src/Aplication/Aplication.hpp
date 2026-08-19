#include "mainwindow.hpp"
#include <QApplication>
#include <QObject>
#include "SiemensTags.hpp"

class Aplication:public QObject

{
    Q_OBJECT
private:
    MainWindow w;
    SiemensBool Motor;
    
public:
    Aplication();
};