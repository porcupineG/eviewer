#ifndef METAMODEL_H
#define METAMODEL_H

#include <QObject>

class MetaModel : public QObject
{
    Q_OBJECT
public:
    explicit MetaModel(QObject *parent = 0);
    bool setModel(const QString & string);



signals:
    
public slots:
    
};

#endif // METAMODEL_H
