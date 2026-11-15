#pragma once

#include <QFile>
#include <QString>
#include <QDir>
#include <stdint.h>

enum StyleId : uint16_t {
    Black = 0
};

extern QString ActualStyle;

bool DownloadStyle(uint16_t styleId);



