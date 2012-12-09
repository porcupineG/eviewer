#include "id.h"

Id::Id(unsigned int size, QString name)
{
    this->size = size;
    this->name = name;
}

QString * Id::getName()
{
    return &name;
}

unsigned long long Id::getValue()
{
    return value;
}

unsigned int Id::getSize()
{
    return size;
}

void Id::parse(char * data)
{
    value = 0;
    for (int i = 0; i < (size / 8); i++) {
        value += ((unsigned long long int) data[i] << (i * 8));
    }
}
