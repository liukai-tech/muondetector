/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../muondetector-gui/src/main/settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    QByteArrayData data[46];
    char stringdata0[905];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Settings_t qt_meta_stringdata_Settings = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Settings"
QT_MOC_LITERAL(1, 9, 24), // "sendSetUbxMsgRateChanges"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 18), // "QMap<uint16_t,int>"
QT_MOC_LITERAL(4, 54, 17), // "ubxMsgRateChanges"
QT_MOC_LITERAL(5, 72, 22), // "sendRequestUbxMsgRates"
QT_MOC_LITERAL(6, 95, 12), // "sendUbxReset"
QT_MOC_LITERAL(7, 108, 20), // "sendUbxConfigDefault"
QT_MOC_LITERAL(8, 129, 14), // "setGnssConfigs"
QT_MOC_LITERAL(9, 144, 25), // "QVector<GnssConfigStruct>"
QT_MOC_LITERAL(10, 170, 10), // "configList"
QT_MOC_LITERAL(11, 181, 12), // "setTP5Config"
QT_MOC_LITERAL(12, 194, 18), // "UbxTimePulseStruct"
QT_MOC_LITERAL(13, 213, 2), // "tp"
QT_MOC_LITERAL(14, 216, 14), // "sendUbxSaveCfg"
QT_MOC_LITERAL(15, 231, 14), // "addUbxMsgRates"
QT_MOC_LITERAL(16, 246, 11), // "ubxMsgRates"
QT_MOC_LITERAL(17, 258, 13), // "onItemChanged"
QT_MOC_LITERAL(18, 272, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(19, 290, 4), // "item"
QT_MOC_LITERAL(20, 295, 22), // "onUiEnabledStateChange"
QT_MOC_LITERAL(21, 318, 9), // "connected"
QT_MOC_LITERAL(22, 328, 15), // "onTxBufReceived"
QT_MOC_LITERAL(23, 344, 3), // "val"
QT_MOC_LITERAL(24, 348, 19), // "onTxBufPeakReceived"
QT_MOC_LITERAL(25, 368, 15), // "onRxBufReceived"
QT_MOC_LITERAL(26, 384, 19), // "onRxBufPeakReceived"
QT_MOC_LITERAL(27, 404, 21), // "onGnssConfigsReceived"
QT_MOC_LITERAL(28, 426, 8), // "numTrkCh"
QT_MOC_LITERAL(29, 435, 13), // "onTP5Received"
QT_MOC_LITERAL(30, 449, 26), // "onSettingsButtonBoxClicked"
QT_MOC_LITERAL(31, 476, 16), // "QAbstractButton*"
QT_MOC_LITERAL(32, 493, 6), // "button"
QT_MOC_LITERAL(33, 500, 29), // "on_ubxResetPushButton_clicked"
QT_MOC_LITERAL(34, 530, 15), // "writeGnssConfig"
QT_MOC_LITERAL(35, 546, 13), // "writeTpConfig"
QT_MOC_LITERAL(36, 560, 39), // "on_timeGridComboBox_currentIn..."
QT_MOC_LITERAL(37, 600, 5), // "index"
QT_MOC_LITERAL(38, 606, 37), // "on_freqPeriodLineEdit_editing..."
QT_MOC_LITERAL(39, 644, 41), // "on_freqPeriodLockLineEdit_edi..."
QT_MOC_LITERAL(40, 686, 35), // "on_pulseLenLineEdit_editingFi..."
QT_MOC_LITERAL(41, 722, 39), // "on_pulseLenLockLineEdit_editi..."
QT_MOC_LITERAL(42, 762, 35), // "on_antDelayLineEdit_editingFi..."
QT_MOC_LITERAL(43, 798, 37), // "on_groupDelayLineEdit_editing..."
QT_MOC_LITERAL(44, 836, 36), // "on_userDelayLineEdit_editingF..."
QT_MOC_LITERAL(45, 873, 31) // "on_saveConfigPushButton_clicked"

    },
    "Settings\0sendSetUbxMsgRateChanges\0\0"
    "QMap<uint16_t,int>\0ubxMsgRateChanges\0"
    "sendRequestUbxMsgRates\0sendUbxReset\0"
    "sendUbxConfigDefault\0setGnssConfigs\0"
    "QVector<GnssConfigStruct>\0configList\0"
    "setTP5Config\0UbxTimePulseStruct\0tp\0"
    "sendUbxSaveCfg\0addUbxMsgRates\0ubxMsgRates\0"
    "onItemChanged\0QTableWidgetItem*\0item\0"
    "onUiEnabledStateChange\0connected\0"
    "onTxBufReceived\0val\0onTxBufPeakReceived\0"
    "onRxBufReceived\0onRxBufPeakReceived\0"
    "onGnssConfigsReceived\0numTrkCh\0"
    "onTP5Received\0onSettingsButtonBoxClicked\0"
    "QAbstractButton*\0button\0"
    "on_ubxResetPushButton_clicked\0"
    "writeGnssConfig\0writeTpConfig\0"
    "on_timeGridComboBox_currentIndexChanged\0"
    "index\0on_freqPeriodLineEdit_editingFinished\0"
    "on_freqPeriodLockLineEdit_editingFinished\0"
    "on_pulseLenLineEdit_editingFinished\0"
    "on_pulseLenLockLineEdit_editingFinished\0"
    "on_antDelayLineEdit_editingFinished\0"
    "on_groupDelayLineEdit_editingFinished\0"
    "on_userDelayLineEdit_editingFinished\0"
    "on_saveConfigPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  159,    2, 0x06 /* Public */,
       5,    0,  162,    2, 0x06 /* Public */,
       6,    0,  163,    2, 0x06 /* Public */,
       7,    0,  164,    2, 0x06 /* Public */,
       8,    1,  165,    2, 0x06 /* Public */,
      11,    1,  168,    2, 0x06 /* Public */,
      14,    0,  171,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  172,    2, 0x0a /* Public */,
      17,    1,  175,    2, 0x0a /* Public */,
      20,    1,  178,    2, 0x0a /* Public */,
      22,    1,  181,    2, 0x0a /* Public */,
      24,    1,  184,    2, 0x0a /* Public */,
      25,    1,  187,    2, 0x0a /* Public */,
      26,    1,  190,    2, 0x0a /* Public */,
      27,    2,  193,    2, 0x0a /* Public */,
      29,    1,  198,    2, 0x0a /* Public */,
      30,    1,  201,    2, 0x08 /* Private */,
      33,    0,  204,    2, 0x08 /* Private */,
      34,    0,  205,    2, 0x08 /* Private */,
      35,    0,  206,    2, 0x08 /* Private */,
      36,    1,  207,    2, 0x08 /* Private */,
      38,    0,  210,    2, 0x08 /* Private */,
      39,    0,  211,    2, 0x08 /* Private */,
      40,    0,  212,    2, 0x08 /* Private */,
      41,    0,  213,    2, 0x08 /* Private */,
      42,    0,  214,    2, 0x08 /* Private */,
      43,    0,  215,    2, 0x08 /* Private */,
      44,    0,  216,    2, 0x08 /* Private */,
      45,    0,  217,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::UChar,   23,
    QMetaType::Void, QMetaType::UChar,   23,
    QMetaType::Void, QMetaType::UChar,   23,
    QMetaType::Void, QMetaType::UChar,   23,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 9,   28,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Settings *_t = static_cast<Settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSetUbxMsgRateChanges((*reinterpret_cast< QMap<uint16_t,int>(*)>(_a[1]))); break;
        case 1: _t->sendRequestUbxMsgRates(); break;
        case 2: _t->sendUbxReset(); break;
        case 3: _t->sendUbxConfigDefault(); break;
        case 4: _t->setGnssConfigs((*reinterpret_cast< const QVector<GnssConfigStruct>(*)>(_a[1]))); break;
        case 5: _t->setTP5Config((*reinterpret_cast< const UbxTimePulseStruct(*)>(_a[1]))); break;
        case 6: _t->sendUbxSaveCfg(); break;
        case 7: _t->addUbxMsgRates((*reinterpret_cast< QMap<uint16_t,int>(*)>(_a[1]))); break;
        case 8: _t->onItemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->onUiEnabledStateChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->onTxBufReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 11: _t->onTxBufPeakReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 12: _t->onRxBufReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 13: _t->onRxBufPeakReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 14: _t->onGnssConfigsReceived((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< const QVector<GnssConfigStruct>(*)>(_a[2]))); break;
        case 15: _t->onTP5Received((*reinterpret_cast< const UbxTimePulseStruct(*)>(_a[1]))); break;
        case 16: _t->onSettingsButtonBoxClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 17: _t->on_ubxResetPushButton_clicked(); break;
        case 18: _t->writeGnssConfig(); break;
        case 19: _t->writeTpConfig(); break;
        case 20: _t->on_timeGridComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_freqPeriodLineEdit_editingFinished(); break;
        case 22: _t->on_freqPeriodLockLineEdit_editingFinished(); break;
        case 23: _t->on_pulseLenLineEdit_editingFinished(); break;
        case 24: _t->on_pulseLenLockLineEdit_editingFinished(); break;
        case 25: _t->on_antDelayLineEdit_editingFinished(); break;
        case 26: _t->on_groupDelayLineEdit_editingFinished(); break;
        case 27: _t->on_userDelayLineEdit_editingFinished(); break;
        case 28: _t->on_saveConfigPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Settings::*)(QMap<uint16_t,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::sendSetUbxMsgRateChanges)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::sendRequestUbxMsgRates)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::sendUbxReset)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::sendUbxConfigDefault)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const QVector<GnssConfigStruct> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::setGnssConfigs)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const UbxTimePulseStruct & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::setTP5Config)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::sendUbxSaveCfg)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Settings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Settings.data,
      qt_meta_data_Settings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void Settings::sendSetUbxMsgRateChanges(QMap<uint16_t,int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Settings::sendRequestUbxMsgRates()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Settings::sendUbxReset()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Settings::sendUbxConfigDefault()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Settings::setGnssConfigs(const QVector<GnssConfigStruct> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Settings::setTP5Config(const UbxTimePulseStruct & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Settings::sendUbxSaveCfg()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
