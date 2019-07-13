/****************************************************************************
** Meta object code from reading C++ file 'i2cform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../muondetector-gui/src/main/i2cform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'i2cform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_I2cForm_t {
    QByteArrayData data[13];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_I2cForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_I2cForm_t qt_meta_stringdata_I2cForm = {
    {
QT_MOC_LITERAL(0, 0, 7), // "I2cForm"
QT_MOC_LITERAL(1, 8, 15), // "i2cStatsRequest"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 17), // "scanI2cBusRequest"
QT_MOC_LITERAL(4, 43, 18), // "onI2cStatsReceived"
QT_MOC_LITERAL(5, 62, 9), // "bytesRead"
QT_MOC_LITERAL(6, 72, 12), // "bytesWritten"
QT_MOC_LITERAL(7, 85, 23), // "QVector<I2cDeviceEntry>"
QT_MOC_LITERAL(8, 109, 10), // "deviceList"
QT_MOC_LITERAL(9, 120, 22), // "onUiEnabledStateChange"
QT_MOC_LITERAL(10, 143, 9), // "connected"
QT_MOC_LITERAL(11, 153, 31), // "on_statsQueryPushButton_clicked"
QT_MOC_LITERAL(12, 185, 28) // "on_scanBusPushButton_clicked"

    },
    "I2cForm\0i2cStatsRequest\0\0scanI2cBusRequest\0"
    "onI2cStatsReceived\0bytesRead\0bytesWritten\0"
    "QVector<I2cDeviceEntry>\0deviceList\0"
    "onUiEnabledStateChange\0connected\0"
    "on_statsQueryPushButton_clicked\0"
    "on_scanBusPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_I2cForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   46,    2, 0x0a /* Public */,
       9,    1,   53,    2, 0x0a /* Public */,
      11,    0,   56,    2, 0x08 /* Private */,
      12,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, 0x80000000 | 7,    5,    6,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void I2cForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        I2cForm *_t = static_cast<I2cForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->i2cStatsRequest(); break;
        case 1: _t->scanI2cBusRequest(); break;
        case 2: _t->onI2cStatsReceived((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< const QVector<I2cDeviceEntry>(*)>(_a[3]))); break;
        case 3: _t->onUiEnabledStateChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_statsQueryPushButton_clicked(); break;
        case 5: _t->on_scanBusPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (I2cForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&I2cForm::i2cStatsRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (I2cForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&I2cForm::scanI2cBusRequest)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject I2cForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_I2cForm.data,
      qt_meta_data_I2cForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *I2cForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *I2cForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_I2cForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int I2cForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void I2cForm::i2cStatsRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void I2cForm::scanI2cBusRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
