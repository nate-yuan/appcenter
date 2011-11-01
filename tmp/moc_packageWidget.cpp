/****************************************************************************
** Meta object code from reading C++ file 'packageWidget.h'
**
** Created: Tue Nov 1 14:40:24 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/client/packageWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packageWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PackageWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      34,   29,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PackageWidget[] = {
    "PackageWidget\0\0clearSearch()\0text\0"
    "searchChanged(QString)\0setCurrentButton(int)\0"
};

const QMetaObject PackageWidget::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_PackageWidget,
      qt_meta_data_PackageWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PackageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PackageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PackageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PackageWidget))
        return static_cast<void*>(const_cast< PackageWidget*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int PackageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clearSearch(); break;
        case 1: searchChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: setCurrentButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PackageWidget::clearSearch()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PackageWidget::searchChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
