/****************************************************************************
** Meta object code from reading C++ file 'MessageDialog.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MessageDialog.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MessageDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      30,   14,   14,   14, 0x08,
      44,   14,   14,   14, 0x08,
      58,   14,   14,   14, 0x08,
      70,   14,   14,   14, 0x08,
      84,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MessageDialog[] = {
    "MessageDialog\0\0showQuestion()\0"
    "showMessage()\0showWarning()\0showAbout()\0"
    "showAboutQt()\0showCritical()\0"
};

void MessageDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MessageDialog *_t = static_cast<MessageDialog *>(_o);
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

const QMetaObjectExtraData MessageDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MessageDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MessageDialog,
      qt_meta_data_MessageDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MessageDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MessageDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MessageDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MessageDialog))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
