#ifndef EVENTSCOLLECTOR_H
#define EVENTSCOLLECTOR_H

#include <QObject>
#include "metamodel.h"
#include "groupfilter.h"

class EventsCollector : public QObject
{
    Q_OBJECT
public:
    explicit EventsCollector(QObject * parent = 0);
    void setMetaModel(MetaModel & metaModel);
    void setGroupFilter(GroupFilter & groupFiler);
    friend std::istream & operator >> (std::istream & in, EventsCollector & eventsCollector);

signals:
    
public slots:
    
};

#endif // EVENTSCOLLECTOR_H
