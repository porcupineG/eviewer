#include "node.h"

#include "sublevel.h"
#include "id.h"
#include "logtype.h"
#include "event.h"

Node::Node(NodeType nodeType, void * value, QObject * parent) :
    QObject(parent)
{
    this->value = value;
    this->nodeType = nodeType;
}

void Node::addChildNode(Node * child)
{
    switch (child->getNodeType()) {
    case ID:
        ids.insert(getKey(child), child);
        break;
    case LEVEL:
        levels.insert(getKey(child), child);
        break;
    case TYPE:
        types.insert(getKey(child), child);
        break;
    case EVENT:
        events.insert(getKey(child), child);
        break;
    default:
        break;
    }
}

void Node::setParent(Node * parent)
{
    this->parentNode = parent;
}


Node * Node::getParentNode()
{
    return this->parentNode;
}

QMap<unsigned long long, Node *> * Node::getIds()
{
    return &ids;
}

QMap<unsigned long long, Node *> * Node::getLevels()
{
    return &levels;
}

QMap<unsigned long long, Node *> *Node::getTypes()
{
    return &types;
}

QMultiMap<unsigned long long, Node *> * Node::getEvents()
{
    return &events;
}

Node::NodeType Node::getNodeType()
{
    return nodeType;
}

void * Node::getValue()
{
    return value;
}

Node * Node::insertToNode(Node * root, Node * node)
{
    switch(node->getNodeType()) {
        case ID:
            id = (Id *) node->getValue();

            break;
        case LEVEL:

            break;
        case TYPE:

            break;
        case EVENT:

            break;
        default:
            break;
    }

    return 0;
}

unsigned long long int Node::getKey(Node * node)
{
    unsigned long long int key = 0;

    Id * id;
    SubLevel * subLevel;
    LogType * logType;
    LogEvent * logEvent;

    switch(node->getNodeType()) {
        case ID:
            id = (Id *) node->getValue();
            key = id->getValue();
            break;
        case LEVEL:
            subLevel = (SubLevel *) node->getValue();
            key = subLevel->getOrdinal();
            break;
        case TYPE:
            logType = (LogType *) node->getValue();
            key = logType->getValue();
            break;
        case EVENT:
            logEvent = (LogEvent *) node->getValue();
            key = logEvent->getTimestamp();
            break;
        default:
            break;
    }

    return key;
}
