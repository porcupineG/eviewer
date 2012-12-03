#ifndef ID_H
#define ID_H

#include <QString>

class Id
{
private:
    unsigned int size;
    QString name;

public:
    Id(unsigned int size, QString name);
    QString getName();
    unsigned int getSize();
};

#endif // ID_H
