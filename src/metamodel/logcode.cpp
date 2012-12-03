#include "logcode.h"

LogCode::LogCode(unsigned int value, QString name)
{
    this->value = value;
    this->name = name;
}

unsigned int LogCode::getValue()
{
    return value;
}

QString LogCode::getName()
{
    return name;
}
