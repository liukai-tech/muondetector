/****************************************************************************
** Meta object code from reading C++ file 'gpssatsform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../muondetector-gui/src/main/gpssatsform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gpssatsform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GpsSatsForm_t {
    QByteArrayData data[35];
    char stringdata0[394];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GpsSatsForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GpsSatsForm_t qt_meta_stringdata_GpsSatsForm = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GpsSatsForm"
QT_MOC_LITERAL(1, 12, 14), // "onSatsReceived"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 22), // "QVector<GnssSatellite>"
QT_MOC_LITERAL(4, 51, 7), // "satlist"
QT_MOC_LITERAL(5, 59, 17), // "onTimeAccReceived"
QT_MOC_LITERAL(6, 77, 3), // "acc"
QT_MOC_LITERAL(7, 81, 17), // "onFreqAccReceived"
QT_MOC_LITERAL(8, 99, 20), // "onIntCounterReceived"
QT_MOC_LITERAL(9, 120, 3), // "cnt"
QT_MOC_LITERAL(10, 124, 18), // "onGpsMonHWReceived"
QT_MOC_LITERAL(11, 143, 5), // "noise"
QT_MOC_LITERAL(12, 149, 3), // "agc"
QT_MOC_LITERAL(13, 153, 9), // "antStatus"
QT_MOC_LITERAL(14, 163, 8), // "antPower"
QT_MOC_LITERAL(15, 172, 6), // "jamInd"
QT_MOC_LITERAL(16, 179, 5), // "flags"
QT_MOC_LITERAL(17, 185, 19), // "onGpsMonHW2Received"
QT_MOC_LITERAL(18, 205, 4), // "ofsI"
QT_MOC_LITERAL(19, 210, 4), // "magI"
QT_MOC_LITERAL(20, 215, 4), // "ofsQ"
QT_MOC_LITERAL(21, 220, 4), // "magQ"
QT_MOC_LITERAL(22, 225, 6), // "cfgSrc"
QT_MOC_LITERAL(23, 232, 20), // "onGpsVersionReceived"
QT_MOC_LITERAL(24, 253, 8), // "swString"
QT_MOC_LITERAL(25, 262, 8), // "hwString"
QT_MOC_LITERAL(26, 271, 10), // "protString"
QT_MOC_LITERAL(27, 282, 16), // "onGpsFixReceived"
QT_MOC_LITERAL(28, 299, 3), // "val"
QT_MOC_LITERAL(29, 303, 21), // "onGeodeticPosReceived"
QT_MOC_LITERAL(30, 325, 11), // "GeodeticPos"
QT_MOC_LITERAL(31, 337, 3), // "pos"
QT_MOC_LITERAL(32, 341, 22), // "onUiEnabledStateChange"
QT_MOC_LITERAL(33, 364, 9), // "connected"
QT_MOC_LITERAL(34, 374, 19) // "onUbxUptimeReceived"

    },
    "GpsSatsForm\0onSatsReceived\0\0"
    "QVector<GnssSatellite>\0satlist\0"
    "onTimeAccReceived\0acc\0onFreqAccReceived\0"
    "onIntCounterReceived\0cnt\0onGpsMonHWReceived\0"
    "noise\0agc\0antStatus\0antPower\0jamInd\0"
    "flags\0onGpsMonHW2Received\0ofsI\0magI\0"
    "ofsQ\0magQ\0cfgSrc\0onGpsVersionReceived\0"
    "swString\0hwString\0protString\0"
    "onGpsFixReceived\0val\0onGeodeticPosReceived\0"
    "GeodeticPos\0pos\0onUiEnabledStateChange\0"
    "connected\0onUbxUptimeReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GpsSatsForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       5,    1,   72,    2, 0x0a /* Public */,
       7,    1,   75,    2, 0x0a /* Public */,
       8,    1,   78,    2, 0x0a /* Public */,
      10,    6,   81,    2, 0x0a /* Public */,
      17,    5,   94,    2, 0x0a /* Public */,
      23,    3,  105,    2, 0x0a /* Public */,
      27,    1,  112,    2, 0x0a /* Public */,
      29,    1,  115,    2, 0x0a /* Public */,
      32,    1,  118,    2, 0x0a /* Public */,
      34,    1,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void, QMetaType::UShort, QMetaType::UShort, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   11,   12,   13,   14,   15,   16,
    QMetaType::Void, QMetaType::SChar, QMetaType::UChar, QMetaType::SChar, QMetaType::UChar, QMetaType::UChar,   18,   19,   20,   21,   22,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   24,   25,   26,
    QMetaType::Void, QMetaType::UChar,   28,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::UInt,   28,

       0        // eod
};

void GpsSatsForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GpsSatsForm *_t = static_cast<GpsSatsForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onSatsReceived((*reinterpret_cast< const QVector<GnssSatellite>(*)>(_a[1]))); break;
        case 1: _t->onTimeAccReceived((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: _t->onFreqAccReceived((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 3: _t->onIntCounterReceived((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 4: _t->onGpsMonHWReceived((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5])),(*reinterpret_cast< quint8(*)>(_a[6]))); break;
        case 5: _t->onGpsMonHW2Received((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 6: _t->onGpsVersionReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 7: _t->onGpsFixReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 8: _t->onGeodeticPosReceived((*reinterpret_cast< GeodeticPos(*)>(_a[1]))); break;
        case 9: _t->onUiEnabledStateChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->onUbxUptimeReceived((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GpsSatsForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GpsSatsForm.data,
      qt_meta_data_GpsSatsForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GpsSatsForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GpsSatsForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GpsSatsForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GpsSatsForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
