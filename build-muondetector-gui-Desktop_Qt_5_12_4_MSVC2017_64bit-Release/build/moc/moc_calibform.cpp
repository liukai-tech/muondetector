/****************************************************************************
** Meta object code from reading C++ file 'calibform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../muondetector-gui/src/main/calibform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calibform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalibForm_t {
    QByteArrayData data[34];
    char stringdata0[503];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalibForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalibForm_t qt_meta_stringdata_CalibForm = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CalibForm"
QT_MOC_LITERAL(1, 10, 12), // "calibRequest"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 18), // "writeCalibToEeprom"
QT_MOC_LITERAL(4, 43, 17), // "setBiasDacVoltage"
QT_MOC_LITERAL(5, 61, 3), // "val"
QT_MOC_LITERAL(6, 65, 12), // "updatedCalib"
QT_MOC_LITERAL(7, 78, 20), // "QVector<CalibStruct>"
QT_MOC_LITERAL(8, 99, 5), // "items"
QT_MOC_LITERAL(9, 105, 15), // "onCalibReceived"
QT_MOC_LITERAL(10, 121, 5), // "valid"
QT_MOC_LITERAL(11, 127, 11), // "eepromValid"
QT_MOC_LITERAL(12, 139, 2), // "id"
QT_MOC_LITERAL(13, 142, 9), // "calibList"
QT_MOC_LITERAL(14, 152, 19), // "onAdcSampleReceived"
QT_MOC_LITERAL(15, 172, 7), // "uint8_t"
QT_MOC_LITERAL(16, 180, 7), // "channel"
QT_MOC_LITERAL(17, 188, 5), // "value"
QT_MOC_LITERAL(18, 194, 17), // "getCalibParameter"
QT_MOC_LITERAL(19, 212, 4), // "name"
QT_MOC_LITERAL(20, 217, 12), // "getCalibItem"
QT_MOC_LITERAL(21, 230, 14), // "biasCalibValid"
QT_MOC_LITERAL(22, 245, 22), // "onUiEnabledStateChange"
QT_MOC_LITERAL(23, 268, 9), // "connected"
QT_MOC_LITERAL(24, 278, 30), // "on_readCalibPushButton_clicked"
QT_MOC_LITERAL(25, 309, 32), // "on_writeEepromPushButton_clicked"
QT_MOC_LITERAL(26, 342, 32), // "on_doBiasCalibPushButton_clicked"
QT_MOC_LITERAL(27, 375, 5), // "doFit"
QT_MOC_LITERAL(28, 381, 39), // "on_transferBiasCoeffsPushButt..."
QT_MOC_LITERAL(29, 421, 17), // "setCalibParameter"
QT_MOC_LITERAL(30, 439, 16), // "updateCalibTable"
QT_MOC_LITERAL(31, 456, 35), // "on_calibItemTableWidget_cellC..."
QT_MOC_LITERAL(32, 492, 3), // "row"
QT_MOC_LITERAL(33, 496, 6) // "column"

    },
    "CalibForm\0calibRequest\0\0writeCalibToEeprom\0"
    "setBiasDacVoltage\0val\0updatedCalib\0"
    "QVector<CalibStruct>\0items\0onCalibReceived\0"
    "valid\0eepromValid\0id\0calibList\0"
    "onAdcSampleReceived\0uint8_t\0channel\0"
    "value\0getCalibParameter\0name\0getCalibItem\0"
    "biasCalibValid\0onUiEnabledStateChange\0"
    "connected\0on_readCalibPushButton_clicked\0"
    "on_writeEepromPushButton_clicked\0"
    "on_doBiasCalibPushButton_clicked\0doFit\0"
    "on_transferBiasCoeffsPushButton_clicked\0"
    "setCalibParameter\0updateCalibTable\0"
    "on_calibItemTableWidget_cellChanged\0"
    "row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalibForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    1,  106,    2, 0x06 /* Public */,
       6,    1,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    4,  112,    2, 0x0a /* Public */,
      14,    2,  121,    2, 0x0a /* Public */,
      18,    1,  126,    2, 0x0a /* Public */,
      20,    1,  129,    2, 0x0a /* Public */,
      21,    0,  132,    2, 0x0a /* Public */,
      22,    1,  133,    2, 0x0a /* Public */,
      24,    0,  136,    2, 0x08 /* Private */,
      25,    0,  137,    2, 0x08 /* Private */,
      26,    0,  138,    2, 0x08 /* Private */,
      27,    0,  139,    2, 0x08 /* Private */,
      28,    0,  140,    2, 0x08 /* Private */,
      29,    2,  141,    2, 0x08 /* Private */,
      30,    0,  146,    2, 0x08 /* Private */,
      31,    2,  147,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::ULongLong, 0x80000000 | 7,   10,   11,   12,   13,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Float,   16,   17,
    QMetaType::QString, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   32,   33,

       0        // eod
};

void CalibForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalibForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->calibRequest(); break;
        case 1: _t->writeCalibToEeprom(); break;
        case 2: _t->setBiasDacVoltage((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->updatedCalib((*reinterpret_cast< const QVector<CalibStruct>(*)>(_a[1]))); break;
        case 4: _t->onCalibReceived((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< quint64(*)>(_a[3])),(*reinterpret_cast< const QVector<CalibStruct>(*)>(_a[4]))); break;
        case 5: _t->onAdcSampleReceived((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 6: { QString _r = _t->getCalibParameter((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->getCalibItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: { bool _r = _t->biasCalibValid();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->onUiEnabledStateChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_readCalibPushButton_clicked(); break;
        case 11: _t->on_writeEepromPushButton_clicked(); break;
        case 12: _t->on_doBiasCalibPushButton_clicked(); break;
        case 13: _t->doFit(); break;
        case 14: _t->on_transferBiasCoeffsPushButton_clicked(); break;
        case 15: _t->setCalibParameter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 16: _t->updateCalibTable(); break;
        case 17: _t->on_calibItemTableWidget_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CalibForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibForm::calibRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CalibForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibForm::writeCalibToEeprom)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CalibForm::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibForm::setBiasDacVoltage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CalibForm::*)(const QVector<CalibStruct> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibForm::updatedCalib)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CalibForm::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CalibForm.data,
    qt_meta_data_CalibForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalibForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalibForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalibForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CalibForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void CalibForm::calibRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CalibForm::writeCalibToEeprom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CalibForm::setBiasDacVoltage(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CalibForm::updatedCalib(const QVector<CalibStruct> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
