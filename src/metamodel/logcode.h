#ifndef LOGCODE_H
#define LOGCODE_H

#include <QString>

class LogCode
{
private:
    unsigned int value;
    QString name;
public:
    LogCode(unsigned int value, QString name);

    unsigned int getValue();
    QString * getName();
};

#endif // LOGCODE_H
