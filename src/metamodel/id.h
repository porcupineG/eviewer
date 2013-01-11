#ifndef ID_H
#define ID_H

#include <QString>

class Id
{
private:
    unsigned int size;
    unsigned long long int value;
    QString name;
    unsigned int ordinal;

public:
    Id(unsigned int size, QString name, unsigned int ordinal);
    QString * getName();
    unsigned long long int getValue();
    void setValue(unsigned long long int value);
    unsigned int getSize();
    unsigned int getOrdinal();

    void parse(char * data);
};

#endif // ID_H
