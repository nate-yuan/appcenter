/****************************************************************************
** Meta object code from reading C++ file 'appnode.h'
**
** Created: Tue Nov 1 14:40:24 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/client/appnode.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appnode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Node[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Node[] = {
    "Node\0"
};

const QMetaObject Node::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Node,
      qt_meta_data_Node, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Node::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Node::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Node::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Node))
        return static_cast<void*>(const_cast< Node*>(this));
    return QObject::qt_metacast(_clname);
}

int Node::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_NodeList[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_NodeList[] = {
    "NodeList\0"
};

const QMetaObject NodeList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NodeList,
      qt_meta_data_NodeList, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NodeList::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NodeList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NodeList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NodeList))
        return static_cast<void*>(const_cast< NodeList*>(this));
    return QObject::qt_metacast(_clname);
}

int NodeList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
