/****************************************************************************
** Meta object code from reading C++ file 'MessageDialog.hh'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MessageDialog.hh"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MessageDialog_t {
    QByteArrayData data[8];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageDialog_t qt_meta_stringdata_MessageDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MessageDialog"
QT_MOC_LITERAL(1, 14, 12), // "showQuestion"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "showMessage"
QT_MOC_LITERAL(4, 40, 11), // "showWarning"
QT_MOC_LITERAL(5, 52, 9), // "showAbout"
QT_MOC_LITERAL(6, 62, 11), // "showAboutQt"
QT_MOC_LITERAL(7, 74, 12) // "showCritical"

    },
    "MessageDialog\0showQuestion\0\0showMessage\0"
    "showWarning\0showAbout\0showAboutQt\0"
    "showCritical"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MessageDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageDialog *_t = static_cast<MessageDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showQuestion(); break;
        case 1: _t->showMessage(); break;
        case 2: _t->showWarning(); break;
        case 3: _t->showAbout(); break;
        case 4: _t->showAboutQt(); break;
        case 5: _t->showCritical(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MessageDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MessageDialog.data,
      qt_meta_data_MessageDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MessageDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MessageDialog.stringdata0))
        return static_cast<void*>(const_cast< MessageDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MessageDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
