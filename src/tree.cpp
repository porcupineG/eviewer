#include "tree.h"

Tree::Tree()
{
    root = new IdValue(0);
}

IdName * Tree::getRoot()
{
    return root->getChild();
}

void Tree::insert(LogEvent * event)
{
    IdName * parentIdName;
    IdValue * parentIdValue;
    LevelName * parentLevelName;

    parentIdValue = root;

    foreach (Id * id, *(event->getIds())) {
        if (parentIdValue->getChild() == 0) {
            parentIdValue->setChild(new IdName(*id->getName()));
        }
        parentIdName = parentIdValue->getChild();

        IdValue * child = new IdValue(id->getValue());
        parentIdValue = parentIdName->insertChild(child);
        if (child != parentIdValue) {
            delete child;
        }

    }

    LevelName * level = new LevelName(*(event->getSubLevel()->getName()));
    parentLevelName = parentIdValue->insertChild(level);

    TypeName * typeName = parentLevelName->insertChild(new TypeName(*(event->getType()->getName())));

    TypeValue * type = typeName->insertChild(new TypeValue(event->getType()->getValue()));

    type->insertChild(event);

}

