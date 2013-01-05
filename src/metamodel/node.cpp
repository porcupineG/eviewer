#include "node.h"

#include "sublevel.h"
#include "id.h"
#include "logtype.h"

Node::Node(Node * parentNode, NodeType nodeType, void * value, QObject * parent) :
    QObject(parent)
{
    this->parentNode = parentNode;
    this->value = value;
    this->nodeType = nodeType;
}

void Node::addChildNode(Node * child)
{
    childNodes.append(child);

}


Node * Node::getParentNode()
{
    return this->parentNode;
}

QList<Node *> * Node::getChildNodes()
{
    return &childNodes;
}

Node::NodeType Node::getNodeType()
{
    return nodeType;
}

void * Node::getValue()
{
    return value;
}

Node * Node::findChildByValue(void * value, Node::NodeType type)
{

    bool a = (type != Node::ID);

    if ((type == ROOT) ||
       ((type != ID) &&
        (type != LEVEL) &&
        (type != TYPE)) ||
        (type == EVENT))
    {
        return 0;
    }

    foreach (Node * child, childNodes) {

        if (child->getNodeType() == type) {
            Id * id0, * id1;
            SubLevel * l0, * l1;
            LogType * t0, * t1;

            switch (type) {
            case ID:

                id0 = (Id *) child->getValue();
                id1 = (Id *) value;

                if (id0->getValue() == id1->getValue()) {
                    return child;
                }

                break;
            case LEVEL:

                l0 = (SubLevel *) child->getValue();
                l1 = (SubLevel *) value;

                if (l0->getName() == l1->getName()) {
                    return child;
                }

                break;
            case TYPE:

                t0 = (LogType *) child->getValue();
                t1 = (LogType *) value;

                if (t0->getValue() == t1->getValue()) {
                    return child;
                }

                break;
            }
        }
    }

    return 0;

}
