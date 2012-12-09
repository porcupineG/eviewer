#ifndef ID_H
#define ID_H

#include <QString>

class Id
{
private:
    unsigned int size;
    unsigned long long int value;
    QString name;


public:
    Id(unsigned int size, QString name);
    QString * getName();
    unsigned long long int getValue();
    unsigned int getSize();

    void parse(char * data);
};

#endif // ID_H
