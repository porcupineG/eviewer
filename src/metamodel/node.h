#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QList>

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
    QList<Node * > childNodes;
    void * value;
    NodeType nodeType;

public:
    explicit Node(Node * parentNode, NodeType nodeType, void * value, QObject * parent = 0);
    
    void addChildNode(Node * childNode);
    Node * getParentNode();
    QList<Node * > * getChildNodes();
    NodeType getNodeType();
    void * getValue();

    Node * findChildByValue(void * value, NodeType nodeType);

signals:
    
public slots:
    
};

#endif // NODE_H
