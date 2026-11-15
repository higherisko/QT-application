#pragma once

#include <QFile>
#include <QString>
#include <QDir>
#include <QApplication>

class Styles
{
public:
    QString SettingsStyle;
    void StylePath()
    {
        QDir FindPath(QApplication::applicationDirPath());
        while (FindPath.dirName() != "QT-application")
        {
            FindPath.cdUp();
        }
        QString Path = FindPath.filePath("Src/Ui/Styles/SettingsButton.qss");
        QFile file(Path);
        if (file.open(QFile::ReadOnly | QFile::Text))
        {
            SettingsStyle = file.readAll();
            file.close();
        }
    }
};