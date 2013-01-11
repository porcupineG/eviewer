#include "id.h"

#include <QDebug>

Id::Id(unsigned int size, QString name, unsigned int ordinal)
{
    this->size = size;
    this->name = name;
    this->ordinal = ordinal;
}

QString * Id::getName()
{
    return &name;
}

unsigned long long Id::getValue()
{
    return value;
}

void Id::setValue(unsigned long long value)
{
    this->value = value;
}

unsigned int Id::getSize()
{
    return size;
}

unsigned int Id::getOrdinal()
{
    return ordinal;
}

void Id::parse(char * data)
{
    value = 0;

    for (int i = 0; i < (size / 8); i++) {
        value += ((unsigned long long int) data[i] << (i * 8));
    }

    //qDebug() << name;
    //qDebug() << "size:" << (size / 8);
    //qDebug() << "value:" << QString::number(value, 16);

}
