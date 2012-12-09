#include "groupfilter.h"

GroupFilter::GroupFilter(MetaModel * metaModel, QObject *parent) :
    QObject(parent)
{
    this->metaModel = metaModel;
}
