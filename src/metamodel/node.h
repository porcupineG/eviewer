#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QMultiMap>
#include <QMap>

class Node : public QObject
{
    Q_OBJECT
public:

    enum NodeType {
        ROOT,
        ID,
        LEVEL,
        TYPE,
        EVENT
    };

private:
    Node * parentNode;
    QMap<unsigned long long int, Node * > ids;
    QMap<unsigned long long int, Node * > levels;
    QMap<unsigned long long int, Node * > types;
    QMultiMap<unsigned long long int, Node * > events;

    void * value;
    NodeType nodeType;

    unsigned long long int getKey(Node * node);

public:
    explicit Node(Node * parentNode, NodeType nodeType, void * value, QObject * parent = 0);
    
    void addChildNode(Node * childNode);

    Node * getParentNode();
    QMap<unsigned long long int, Node *> * getIds();
    QMap<unsigned long long int, Node *> * getLevels();
    QMap<unsigned long long int, Node *> * getTypes();
    QMultiMap<unsigned long long int, Node *> * getEvents();

    NodeType getNodeType();
    void * getValue();

signals:
    
public slots:
    
};

#endif // NODE_H
