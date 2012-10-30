/****************************************************************************
** Meta object code from reading C++ file 'timeline.h'
**
** Created: Sun Oct 28 20:37:30 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "timeline.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timeline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Timeline[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   10,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Timeline[] = {
    "Timeline\0\0start,stop\0setTimeRange(qreal,qreal)\0"
};

void Timeline::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Timeline *_t = static_cast<Timeline *>(_o);
        switch (_id) {
        case 0: _t->setTimeRange((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Timeline::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Timeline::staticMetaObject = {
    { &QScrollBar::staticMetaObject, qt_meta_stringdata_Timeline,
      qt_meta_data_Timeline, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Timeline::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Timeline::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Timeline::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Timeline))
        return static_cast<void*>(const_cast< Timeline*>(this));
    return QScrollBar::qt_metacast(_clname);
}

int Timeline::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
