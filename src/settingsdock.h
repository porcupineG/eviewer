#ifndef SETTINGSDOCK_H
#define SETTINGSDOCK_H

#include <QDockWidget>
#include <QGridLayout>

class SettingsDock : public QDockWidget
{
private:
    QGridLayout * layout;

public:
    SettingsDock(const QString & title);
};

#endif // SETTINGSDOCK_H
