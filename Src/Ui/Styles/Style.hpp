#pragma once

#include <QFile>
#include <QString>

class Style
{
public:
    static QString Style;
    void StylePath()
    {
        QFile file("C:/Users/cpp2m/Documents/QT-application/Src/Ui/Styles/PlcsButton.qss");
        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            Style = file.readAll();
            file.close();
        }
    }
};