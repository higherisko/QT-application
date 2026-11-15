#include "Style.hpp"

QString ActualStyle;
bool DownloadStyle(uint16_t styleId)
{
    QString filePath;

    switch (styleId) {
    case Black:
        filePath = QStringLiteral(":/Styles/Dark.qss");
        break;
    default:
        return false;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    ActualStyle = QString::fromUtf8(file.readAll());
    return true;
}