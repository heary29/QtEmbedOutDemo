/****************************************************************************
** Meta object code from reading C++ file 'QtEmbedOutDemo1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QtEmbedOutDemo1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtEmbedOutDemo1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtEmbedOutDemo1_t {
    QByteArrayData data[11];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtEmbedOutDemo1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtEmbedOutDemo1_t qt_meta_stringdata_QtEmbedOutDemo1 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QtEmbedOutDemo1"
QT_MOC_LITERAL(1, 16, 17), // "updateEmbedThread"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 17), // "updateFusionError"
QT_MOC_LITERAL(4, 53, 18), // "updateFusionError2"
QT_MOC_LITERAL(5, 72, 10), // "startEmbed"
QT_MOC_LITERAL(6, 83, 15), // "_chlidProcessid"
QT_MOC_LITERAL(7, 99, 17), // "on_processStarted"
QT_MOC_LITERAL(8, 117, 14), // "on_sendClicked"
QT_MOC_LITERAL(9, 132, 14), // "on_revDataFunc"
QT_MOC_LITERAL(10, 147, 3) // "msg"

    },
    "QtEmbedOutDemo1\0updateEmbedThread\0\0"
    "updateFusionError\0updateFusionError2\0"
    "startEmbed\0_chlidProcessid\0on_processStarted\0"
    "on_sendClicked\0on_revDataFunc\0msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtEmbedOutDemo1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   55,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x0a /* Public */,
       9,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void QtEmbedOutDemo1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtEmbedOutDemo1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateEmbedThread(); break;
        case 1: _t->updateFusionError(); break;
        case 2: _t->updateFusionError2(); break;
        case 3: _t->startEmbed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->on_processStarted((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->on_sendClicked(); break;
        case 6: _t->on_revDataFunc((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtEmbedOutDemo1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtEmbedOutDemo1::updateEmbedThread)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtEmbedOutDemo1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtEmbedOutDemo1::updateFusionError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtEmbedOutDemo1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtEmbedOutDemo1::updateFusionError2)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QtEmbedOutDemo1::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtEmbedOutDemo1::startEmbed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtEmbedOutDemo1::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_QtEmbedOutDemo1.data,
    qt_meta_data_QtEmbedOutDemo1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtEmbedOutDemo1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtEmbedOutDemo1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtEmbedOutDemo1.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtEmbedOutDemo1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QtEmbedOutDemo1::updateEmbedThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtEmbedOutDemo1::updateFusionError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtEmbedOutDemo1::updateFusionError2()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QtEmbedOutDemo1::startEmbed(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
