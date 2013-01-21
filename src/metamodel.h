#ifndef METAMODEL_H
#define METAMODEL_H

#include <QObject>
#include <QList>
#include <QDomElement>

#include "metamodel/level.h"
#include "metamodel/event.h"
#include "tree/idname.h"
#include "tree.h"

class MetaModel : public QObject
{
    Q_OBJECT
private:
    Level * cpuAndNetwork;
    Level * runtimeEnvironment;
    Level * process;
    Level * applicationComponent;

    QList<LogEvent *> events;
    Tree root;

    unsigned int idsCount;
    unsigned int sublevelCount;

    bool parseLevel(Level * level, QDomElement * levelElement);

public:
    explicit MetaModel(QObject * parent = 0);
    bool setModel(const QString file);
    bool parse(const QString fileName);

    void arrangeEvents();

    void printLevel(Level * level);

    Tree * getTree();
    QList<LogEvent *> * getEvents();
    Level * getCpuAndNetwork();
    Level * getRuntimeEnvironment();
    Level * getProcess();
    Level * getApplicationComponent();

    bool getIndicator(unsigned int type);
    unsigned int getPriority(unsigned int type);
    unsigned int getLogStruct(unsigned int type);
    unsigned int getLogLevel(unsigned int type);
    unsigned int getLogType(unsigned int type);

    Id * getId(unsigned int idNum);

    SubLevel * getSubLevel(LogType *logType);

signals:
    
public slots:
    
};

#endif // METAMODEL_H
