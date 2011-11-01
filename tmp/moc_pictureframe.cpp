/****************************************************************************
** Meta object code from reading C++ file 'pictureframe.h'
**
** Created: Tue Nov 1 14:40:25 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/client/pictureframe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pictureframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PictureFrame[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PictureFrame[] = {
    "PictureFrame\0\0text\0searchChanged(QString)\0"
    "switchPic(QString)\0"
};

const QMetaObject PictureFrame::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PictureFrame,
      qt_meta_data_PictureFrame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PictureFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PictureFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PictureFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PictureFrame))
        return static_cast<void*>(const_cast< PictureFrame*>(this));
    return QWidget::qt_metacast(_clname);
}

int PictureFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: searchChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: switchPic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PictureFrame::searchChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_PicLabel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_PicLabel[] = {
    "PicLabel\0\0mouseRelease()\0"
};

const QMetaObject PicLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_PicLabel,
      qt_meta_data_PicLabel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PicLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PicLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PicLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PicLabel))
        return static_cast<void*>(const_cast< PicLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int PicLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mouseRelease(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void PicLabel::mouseRelease()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
