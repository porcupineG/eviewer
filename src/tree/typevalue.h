#ifndef TYPEVALUE_H
#define TYPEVALUE_H

#include "idvalue.h"
#include "idname.h"
#include "levelname.h"
#include "typename.h"
#include "typevalue.h"
#include "../metamodel/event.h"

class LogEvent;
class TypeName;

class TypeValue
{
private:
    TypeName * parent;
    QMap<unsigned long long int, LogEvent *> childs;
    unsigned long long int value;

public:
    TypeValue(unsigned long long int value);
    QMap<unsigned long long int, LogEvent *> * getChilds();
    void insertChild(LogEvent * value);
    unsigned long long int getValue();
    TypeName * getParent();
    void setParent(TypeName * parent);
};

#endif // TYPEVALUE_H
