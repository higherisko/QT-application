#include "Aplication.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DownloadStyle(0);
    Aplication App;

    return a.exec();
}
