#ifndef GROUPFILTER_H
#define GROUPFILTER_H

#include <QObject>

#include "metamodel.h"

class GroupFilter : public QObject
{
    Q_OBJECT

private:
    MetaModel * metaModel;

public:
    explicit GroupFilter(MetaModel * metaModel, QObject * parent = 0);
    
signals:
    
public slots:
    
};

#endif // GROUPFILTER_H
