#include "id.h"

Id::Id(unsigned int size, QString name)
{
    this->size = size;
    this->name = name;
}

QString Id::getName()
{
    return name;
}

unsigned int Id::getSize()
{
    return size;
}
