#include <QApplication>
#include "mainwindow.hpp"
#include "TcpClient.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    TcpClient SiemensPLC;
    



    
    return a.exec();
}
