#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>
#include <QTableWidgetItem>

class Source : public QObject
{

    Q_OBJECT

public:

private:
    QList<unsigned long long int> timestamps;

public:

    explicit Source(QObject * parent = 0);
    void addTimestamp(unsigned long long int timestamp);

    QList<unsigned long long int> geTimestamps();
    QTableWidgetItem * getSideWidget();
    QTableWidgetItem * getEventWidget();

signals:
    
public slots:
    
};

#endif // SOURCE_H
