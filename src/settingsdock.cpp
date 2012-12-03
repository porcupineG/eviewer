#include "settingsdock.h"

#include <QLabel>

SettingsDock::SettingsDock(const QString &title) :
    QDockWidget(title)
{
    layout = new QGridLayout();
    setLayout(layout);

    layout->addWidget(new QLabel("Session: "), 0, 0);

}
