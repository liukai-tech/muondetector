/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../muondetector-gui/src/main/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[127];
    char stringdata0[1921];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "addUbxMsgRates"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 18), // "QMap<uint16_t,int>"
QT_MOC_LITERAL(4, 46, 11), // "ubxMsgRates"
QT_MOC_LITERAL(5, 58, 14), // "sendTcpMessage"
QT_MOC_LITERAL(6, 73, 10), // "TcpMessage"
QT_MOC_LITERAL(7, 84, 10), // "tcpMessage"
QT_MOC_LITERAL(8, 95, 15), // "closeConnection"
QT_MOC_LITERAL(9, 111, 9), // "gpioRates"
QT_MOC_LITERAL(10, 121, 9), // "whichrate"
QT_MOC_LITERAL(11, 131, 16), // "QVector<QPointF>"
QT_MOC_LITERAL(12, 148, 4), // "rate"
QT_MOC_LITERAL(13, 153, 15), // "tcpDisconnected"
QT_MOC_LITERAL(14, 169, 18), // "setUiEnabledStates"
QT_MOC_LITERAL(15, 188, 7), // "enabled"
QT_MOC_LITERAL(16, 196, 11), // "geodeticPos"
QT_MOC_LITERAL(17, 208, 11), // "GeodeticPos"
QT_MOC_LITERAL(18, 220, 3), // "pos"
QT_MOC_LITERAL(19, 224, 17), // "adcSampleReceived"
QT_MOC_LITERAL(20, 242, 7), // "uint8_t"
QT_MOC_LITERAL(21, 250, 7), // "channel"
QT_MOC_LITERAL(22, 258, 5), // "value"
QT_MOC_LITERAL(23, 264, 19), // "inputSwitchReceived"
QT_MOC_LITERAL(24, 284, 19), // "dacReadbackReceived"
QT_MOC_LITERAL(25, 304, 18), // "biasSwitchReceived"
QT_MOC_LITERAL(26, 323, 5), // "state"
QT_MOC_LITERAL(27, 329, 20), // "preampSwitchReceived"
QT_MOC_LITERAL(28, 350, 18), // "gainSwitchReceived"
QT_MOC_LITERAL(29, 369, 19), // "temperatureReceived"
QT_MOC_LITERAL(30, 389, 4), // "temp"
QT_MOC_LITERAL(31, 394, 16), // "i2cStatsReceived"
QT_MOC_LITERAL(32, 411, 9), // "bytesRead"
QT_MOC_LITERAL(33, 421, 12), // "bytesWritten"
QT_MOC_LITERAL(34, 434, 23), // "QVector<I2cDeviceEntry>"
QT_MOC_LITERAL(35, 458, 10), // "deviceList"
QT_MOC_LITERAL(36, 469, 13), // "calibReceived"
QT_MOC_LITERAL(37, 483, 5), // "valid"
QT_MOC_LITERAL(38, 489, 11), // "eepromValid"
QT_MOC_LITERAL(39, 501, 2), // "id"
QT_MOC_LITERAL(40, 504, 20), // "QVector<CalibStruct>"
QT_MOC_LITERAL(41, 525, 9), // "calibList"
QT_MOC_LITERAL(42, 535, 12), // "satsReceived"
QT_MOC_LITERAL(43, 548, 22), // "QVector<GnssSatellite>"
QT_MOC_LITERAL(44, 571, 7), // "satList"
QT_MOC_LITERAL(45, 579, 19), // "gnssConfigsReceived"
QT_MOC_LITERAL(46, 599, 8), // "numTrkCh"
QT_MOC_LITERAL(47, 608, 25), // "QVector<GnssConfigStruct>"
QT_MOC_LITERAL(48, 634, 10), // "configList"
QT_MOC_LITERAL(49, 645, 15), // "timeAccReceived"
QT_MOC_LITERAL(50, 661, 3), // "acc"
QT_MOC_LITERAL(51, 665, 15), // "freqAccReceived"
QT_MOC_LITERAL(52, 681, 18), // "intCounterReceived"
QT_MOC_LITERAL(53, 700, 3), // "cnt"
QT_MOC_LITERAL(54, 704, 13), // "txBufReceived"
QT_MOC_LITERAL(55, 718, 3), // "val"
QT_MOC_LITERAL(56, 722, 17), // "txBufPeakReceived"
QT_MOC_LITERAL(57, 740, 13), // "rxBufReceived"
QT_MOC_LITERAL(58, 754, 17), // "rxBufPeakReceived"
QT_MOC_LITERAL(59, 772, 16), // "gpsMonHWReceived"
QT_MOC_LITERAL(60, 789, 5), // "noise"
QT_MOC_LITERAL(61, 795, 3), // "agc"
QT_MOC_LITERAL(62, 799, 9), // "antStatus"
QT_MOC_LITERAL(63, 809, 8), // "antPower"
QT_MOC_LITERAL(64, 818, 6), // "jamInd"
QT_MOC_LITERAL(65, 825, 5), // "flags"
QT_MOC_LITERAL(66, 831, 17), // "gpsMonHW2Received"
QT_MOC_LITERAL(67, 849, 4), // "ofsI"
QT_MOC_LITERAL(68, 854, 4), // "magI"
QT_MOC_LITERAL(69, 859, 4), // "ofsQ"
QT_MOC_LITERAL(70, 864, 4), // "magQ"
QT_MOC_LITERAL(71, 869, 6), // "cfgSrc"
QT_MOC_LITERAL(72, 876, 18), // "gpsVersionReceived"
QT_MOC_LITERAL(73, 895, 8), // "swString"
QT_MOC_LITERAL(74, 904, 8), // "hwString"
QT_MOC_LITERAL(75, 913, 10), // "protString"
QT_MOC_LITERAL(76, 924, 14), // "gpsFixReceived"
QT_MOC_LITERAL(77, 939, 17), // "ubxUptimeReceived"
QT_MOC_LITERAL(78, 957, 14), // "gpsTP5Received"
QT_MOC_LITERAL(79, 972, 18), // "UbxTimePulseStruct"
QT_MOC_LITERAL(80, 991, 2), // "tp"
QT_MOC_LITERAL(81, 994, 17), // "histogramReceived"
QT_MOC_LITERAL(82, 1012, 9), // "Histogram"
QT_MOC_LITERAL(83, 1022, 1), // "h"
QT_MOC_LITERAL(84, 1024, 24), // "triggerSelectionReceived"
QT_MOC_LITERAL(85, 1049, 8), // "GPIO_PIN"
QT_MOC_LITERAL(86, 1058, 6), // "signal"
QT_MOC_LITERAL(87, 1065, 17), // "timepulseReceived"
QT_MOC_LITERAL(88, 1083, 18), // "receivedTcpMessage"
QT_MOC_LITERAL(89, 1102, 22), // "receivedGpioRisingEdge"
QT_MOC_LITERAL(90, 1125, 3), // "pin"
QT_MOC_LITERAL(91, 1129, 22), // "sendRequestUbxMsgRates"
QT_MOC_LITERAL(92, 1152, 24), // "sendSetUbxMsgRateChanges"
QT_MOC_LITERAL(93, 1177, 7), // "changes"
QT_MOC_LITERAL(94, 1185, 14), // "onSendUbxReset"
QT_MOC_LITERAL(95, 1200, 14), // "makeConnection"
QT_MOC_LITERAL(96, 1215, 9), // "ipAddress"
QT_MOC_LITERAL(97, 1225, 4), // "port"
QT_MOC_LITERAL(98, 1230, 25), // "onTriggerSelectionChanged"
QT_MOC_LITERAL(99, 1256, 11), // "resetAndHit"
QT_MOC_LITERAL(100, 1268, 11), // "resetXorHit"
QT_MOC_LITERAL(101, 1280, 20), // "sendRequestGpioRates"
QT_MOC_LITERAL(102, 1301, 25), // "sendRequestGpioRateBuffer"
QT_MOC_LITERAL(103, 1327, 23), // "sendValueUpdateRequests"
QT_MOC_LITERAL(104, 1351, 19), // "on_ipButton_clicked"
QT_MOC_LITERAL(105, 1371, 9), // "connected"
QT_MOC_LITERAL(106, 1381, 15), // "sendInputSwitch"
QT_MOC_LITERAL(107, 1397, 29), // "on_discr1Edit_editingFinished"
QT_MOC_LITERAL(108, 1427, 30), // "on_discr1Slider_sliderReleased"
QT_MOC_LITERAL(109, 1458, 28), // "on_discr1Slider_valueChanged"
QT_MOC_LITERAL(110, 1487, 29), // "on_discr1Slider_sliderPressed"
QT_MOC_LITERAL(111, 1517, 30), // "on_discr2Slider_sliderReleased"
QT_MOC_LITERAL(112, 1548, 28), // "on_discr2Slider_valueChanged"
QT_MOC_LITERAL(113, 1577, 29), // "on_discr2Slider_sliderPressed"
QT_MOC_LITERAL(114, 1607, 26), // "on_biasPowerButton_clicked"
QT_MOC_LITERAL(115, 1634, 29), // "on_discr2Edit_editingFinished"
QT_MOC_LITERAL(116, 1664, 35), // "on_biasVoltageSlider_sliderRe..."
QT_MOC_LITERAL(117, 1700, 33), // "on_biasVoltageSlider_valueCha..."
QT_MOC_LITERAL(118, 1734, 34), // "on_biasVoltageSlider_sliderPr..."
QT_MOC_LITERAL(119, 1769, 14), // "onCalibUpdated"
QT_MOC_LITERAL(120, 1784, 5), // "items"
QT_MOC_LITERAL(121, 1790, 46), // "on_biasControlTypeComboBox_cu..."
QT_MOC_LITERAL(122, 1837, 5), // "index"
QT_MOC_LITERAL(123, 1843, 16), // "onSetGnssConfigs"
QT_MOC_LITERAL(124, 1860, 14), // "onSetTP5Config"
QT_MOC_LITERAL(125, 1875, 40), // "on_biasVoltageDoubleSpinBox_v..."
QT_MOC_LITERAL(126, 1916, 4) // "arg1"

    },
    "MainWindow\0addUbxMsgRates\0\0"
    "QMap<uint16_t,int>\0ubxMsgRates\0"
    "sendTcpMessage\0TcpMessage\0tcpMessage\0"
    "closeConnection\0gpioRates\0whichrate\0"
    "QVector<QPointF>\0rate\0tcpDisconnected\0"
    "setUiEnabledStates\0enabled\0geodeticPos\0"
    "GeodeticPos\0pos\0adcSampleReceived\0"
    "uint8_t\0channel\0value\0inputSwitchReceived\0"
    "dacReadbackReceived\0biasSwitchReceived\0"
    "state\0preampSwitchReceived\0"
    "gainSwitchReceived\0temperatureReceived\0"
    "temp\0i2cStatsReceived\0bytesRead\0"
    "bytesWritten\0QVector<I2cDeviceEntry>\0"
    "deviceList\0calibReceived\0valid\0"
    "eepromValid\0id\0QVector<CalibStruct>\0"
    "calibList\0satsReceived\0QVector<GnssSatellite>\0"
    "satList\0gnssConfigsReceived\0numTrkCh\0"
    "QVector<GnssConfigStruct>\0configList\0"
    "timeAccReceived\0acc\0freqAccReceived\0"
    "intCounterReceived\0cnt\0txBufReceived\0"
    "val\0txBufPeakReceived\0rxBufReceived\0"
    "rxBufPeakReceived\0gpsMonHWReceived\0"
    "noise\0agc\0antStatus\0antPower\0jamInd\0"
    "flags\0gpsMonHW2Received\0ofsI\0magI\0"
    "ofsQ\0magQ\0cfgSrc\0gpsVersionReceived\0"
    "swString\0hwString\0protString\0"
    "gpsFixReceived\0ubxUptimeReceived\0"
    "gpsTP5Received\0UbxTimePulseStruct\0tp\0"
    "histogramReceived\0Histogram\0h\0"
    "triggerSelectionReceived\0GPIO_PIN\0"
    "signal\0timepulseReceived\0receivedTcpMessage\0"
    "receivedGpioRisingEdge\0pin\0"
    "sendRequestUbxMsgRates\0sendSetUbxMsgRateChanges\0"
    "changes\0onSendUbxReset\0makeConnection\0"
    "ipAddress\0port\0onTriggerSelectionChanged\0"
    "resetAndHit\0resetXorHit\0sendRequestGpioRates\0"
    "sendRequestGpioRateBuffer\0"
    "sendValueUpdateRequests\0on_ipButton_clicked\0"
    "connected\0sendInputSwitch\0"
    "on_discr1Edit_editingFinished\0"
    "on_discr1Slider_sliderReleased\0"
    "on_discr1Slider_valueChanged\0"
    "on_discr1Slider_sliderPressed\0"
    "on_discr2Slider_sliderReleased\0"
    "on_discr2Slider_valueChanged\0"
    "on_discr2Slider_sliderPressed\0"
    "on_biasPowerButton_clicked\0"
    "on_discr2Edit_editingFinished\0"
    "on_biasVoltageSlider_sliderReleased\0"
    "on_biasVoltageSlider_valueChanged\0"
    "on_biasVoltageSlider_sliderPressed\0"
    "onCalibUpdated\0items\0"
    "on_biasControlTypeComboBox_currentIndexChanged\0"
    "index\0onSetGnssConfigs\0onSetTP5Config\0"
    "on_biasVoltageDoubleSpinBox_valueChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      66,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      34,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  344,    2, 0x06 /* Public */,
       5,    1,  347,    2, 0x06 /* Public */,
       8,    0,  350,    2, 0x06 /* Public */,
       9,    2,  351,    2, 0x06 /* Public */,
      13,    0,  356,    2, 0x06 /* Public */,
      14,    1,  357,    2, 0x06 /* Public */,
      16,    1,  360,    2, 0x06 /* Public */,
      19,    2,  363,    2, 0x06 /* Public */,
      23,    1,  368,    2, 0x06 /* Public */,
      24,    2,  371,    2, 0x06 /* Public */,
      25,    1,  376,    2, 0x06 /* Public */,
      27,    2,  379,    2, 0x06 /* Public */,
      28,    1,  384,    2, 0x06 /* Public */,
      29,    1,  387,    2, 0x06 /* Public */,
      31,    3,  390,    2, 0x06 /* Public */,
      36,    4,  397,    2, 0x06 /* Public */,
      42,    1,  406,    2, 0x06 /* Public */,
      45,    2,  409,    2, 0x06 /* Public */,
      49,    1,  414,    2, 0x06 /* Public */,
      51,    1,  417,    2, 0x06 /* Public */,
      52,    1,  420,    2, 0x06 /* Public */,
      54,    1,  423,    2, 0x06 /* Public */,
      56,    1,  426,    2, 0x06 /* Public */,
      57,    1,  429,    2, 0x06 /* Public */,
      58,    1,  432,    2, 0x06 /* Public */,
      59,    6,  435,    2, 0x06 /* Public */,
      66,    5,  448,    2, 0x06 /* Public */,
      72,    3,  459,    2, 0x06 /* Public */,
      76,    1,  466,    2, 0x06 /* Public */,
      77,    1,  469,    2, 0x06 /* Public */,
      78,    1,  472,    2, 0x06 /* Public */,
      81,    1,  475,    2, 0x06 /* Public */,
      84,    1,  478,    2, 0x06 /* Public */,
      87,    0,  481,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      88,    1,  482,    2, 0x0a /* Public */,
      89,    1,  485,    2, 0x0a /* Public */,
      91,    0,  488,    2, 0x0a /* Public */,
      92,    1,  489,    2, 0x0a /* Public */,
      94,    0,  492,    2, 0x0a /* Public */,
      95,    2,  493,    2, 0x0a /* Public */,
      98,    1,  498,    2, 0x0a /* Public */,
      99,    0,  501,    2, 0x08 /* Private */,
     100,    0,  502,    2, 0x08 /* Private */,
     101,    0,  503,    2, 0x08 /* Private */,
     102,    0,  504,    2, 0x08 /* Private */,
     103,    0,  505,    2, 0x08 /* Private */,
     104,    0,  506,    2, 0x08 /* Private */,
     105,    0,  507,    2, 0x08 /* Private */,
     106,    1,  508,    2, 0x08 /* Private */,
     107,    0,  511,    2, 0x08 /* Private */,
     108,    0,  512,    2, 0x08 /* Private */,
     109,    1,  513,    2, 0x08 /* Private */,
     110,    0,  516,    2, 0x08 /* Private */,
     111,    0,  517,    2, 0x08 /* Private */,
     112,    1,  518,    2, 0x08 /* Private */,
     113,    0,  521,    2, 0x08 /* Private */,
     114,    0,  522,    2, 0x08 /* Private */,
     115,    0,  523,    2, 0x08 /* Private */,
     116,    0,  524,    2, 0x08 /* Private */,
     117,    1,  525,    2, 0x08 /* Private */,
     118,    0,  528,    2, 0x08 /* Private */,
     119,    1,  529,    2, 0x08 /* Private */,
     121,    1,  532,    2, 0x08 /* Private */,
     123,    1,  535,    2, 0x08 /* Private */,
     124,    1,  538,    2, 0x08 /* Private */,
     125,    1,  541,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 11,   10,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Float,   21,   22,
    QMetaType::Void, 0x80000000 | 20,    2,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Float,   21,   22,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Bool,   21,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Float,   30,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, 0x80000000 | 34,   32,   33,   35,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::ULongLong, 0x80000000 | 40,   37,   38,   39,   41,
    QMetaType::Void, 0x80000000 | 43,   44,
    QMetaType::Void, QMetaType::UChar, 0x80000000 | 47,   46,   48,
    QMetaType::Void, QMetaType::UInt,   50,
    QMetaType::Void, QMetaType::UInt,   50,
    QMetaType::Void, QMetaType::UInt,   53,
    QMetaType::Void, QMetaType::UChar,   55,
    QMetaType::Void, QMetaType::UChar,   55,
    QMetaType::Void, QMetaType::UChar,   55,
    QMetaType::Void, QMetaType::UChar,   55,
    QMetaType::Void, QMetaType::UShort, QMetaType::UShort, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   60,   61,   62,   63,   64,   65,
    QMetaType::Void, QMetaType::SChar, QMetaType::UChar, QMetaType::SChar, QMetaType::UChar, QMetaType::UChar,   67,   68,   69,   70,   71,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   73,   74,   75,
    QMetaType::Void, QMetaType::UChar,   55,
    QMetaType::Void, QMetaType::UInt,   55,
    QMetaType::Void, 0x80000000 | 79,   80,
    QMetaType::Void, 0x80000000 | 82,   83,
    QMetaType::Void, 0x80000000 | 85,   86,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 85,   90,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   93,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,   96,   97,
    QMetaType::Void, 0x80000000 | 85,   86,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 40,  120,
    QMetaType::Void, QMetaType::Int,  122,
    QMetaType::Void, 0x80000000 | 47,   48,
    QMetaType::Void, 0x80000000 | 79,   80,
    QMetaType::Void, QMetaType::Double,  126,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addUbxMsgRates((*reinterpret_cast< QMap<uint16_t,int>(*)>(_a[1]))); break;
        case 1: _t->sendTcpMessage((*reinterpret_cast< TcpMessage(*)>(_a[1]))); break;
        case 2: _t->closeConnection(); break;
        case 3: _t->gpioRates((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< QVector<QPointF>(*)>(_a[2]))); break;
        case 4: _t->tcpDisconnected(); break;
        case 5: _t->setUiEnabledStates((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->geodeticPos((*reinterpret_cast< GeodeticPos(*)>(_a[1]))); break;
        case 7: _t->adcSampleReceived((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 8: _t->inputSwitchReceived((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 9: _t->dacReadbackReceived((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 10: _t->biasSwitchReceived((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->preampSwitchReceived((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: _t->gainSwitchReceived((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->temperatureReceived((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 14: _t->i2cStatsReceived((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< const QVector<I2cDeviceEntry>(*)>(_a[3]))); break;
        case 15: _t->calibReceived((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< quint64(*)>(_a[3])),(*reinterpret_cast< const QVector<CalibStruct>(*)>(_a[4]))); break;
        case 16: _t->satsReceived((*reinterpret_cast< const QVector<GnssSatellite>(*)>(_a[1]))); break;
        case 17: _t->gnssConfigsReceived((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< const QVector<GnssConfigStruct>(*)>(_a[2]))); break;
        case 18: _t->timeAccReceived((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 19: _t->freqAccReceived((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 20: _t->intCounterReceived((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 21: _t->txBufReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 22: _t->txBufPeakReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 23: _t->rxBufReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 24: _t->rxBufPeakReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 25: _t->gpsMonHWReceived((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5])),(*reinterpret_cast< quint8(*)>(_a[6]))); break;
        case 26: _t->gpsMonHW2Received((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< qint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 27: _t->gpsVersionReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 28: _t->gpsFixReceived((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 29: _t->ubxUptimeReceived((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 30: _t->gpsTP5Received((*reinterpret_cast< const UbxTimePulseStruct(*)>(_a[1]))); break;
        case 31: _t->histogramReceived((*reinterpret_cast< const Histogram(*)>(_a[1]))); break;
        case 32: _t->triggerSelectionReceived((*reinterpret_cast< GPIO_PIN(*)>(_a[1]))); break;
        case 33: _t->timepulseReceived(); break;
        case 34: _t->receivedTcpMessage((*reinterpret_cast< TcpMessage(*)>(_a[1]))); break;
        case 35: _t->receivedGpioRisingEdge((*reinterpret_cast< GPIO_PIN(*)>(_a[1]))); break;
        case 36: _t->sendRequestUbxMsgRates(); break;
        case 37: _t->sendSetUbxMsgRateChanges((*reinterpret_cast< QMap<uint16_t,int>(*)>(_a[1]))); break;
        case 38: _t->onSendUbxReset(); break;
        case 39: _t->makeConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 40: _t->onTriggerSelectionChanged((*reinterpret_cast< GPIO_PIN(*)>(_a[1]))); break;
        case 41: _t->resetAndHit(); break;
        case 42: _t->resetXorHit(); break;
        case 43: _t->sendRequestGpioRates(); break;
        case 44: _t->sendRequestGpioRateBuffer(); break;
        case 45: _t->sendValueUpdateRequests(); break;
        case 46: _t->on_ipButton_clicked(); break;
        case 47: _t->connected(); break;
        case 48: _t->sendInputSwitch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->on_discr1Edit_editingFinished(); break;
        case 50: _t->on_discr1Slider_sliderReleased(); break;
        case 51: _t->on_discr1Slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->on_discr1Slider_sliderPressed(); break;
        case 53: _t->on_discr2Slider_sliderReleased(); break;
        case 54: _t->on_discr2Slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->on_discr2Slider_sliderPressed(); break;
        case 56: _t->on_biasPowerButton_clicked(); break;
        case 57: _t->on_discr2Edit_editingFinished(); break;
        case 58: _t->on_biasVoltageSlider_sliderReleased(); break;
        case 59: _t->on_biasVoltageSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->on_biasVoltageSlider_sliderPressed(); break;
        case 61: _t->onCalibUpdated((*reinterpret_cast< const QVector<CalibStruct>(*)>(_a[1]))); break;
        case 62: _t->on_biasControlTypeComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 63: _t->onSetGnssConfigs((*reinterpret_cast< const QVector<GnssConfigStruct>(*)>(_a[1]))); break;
        case 64: _t->onSetTP5Config((*reinterpret_cast< const UbxTimePulseStruct(*)>(_a[1]))); break;
        case 65: _t->on_biasVoltageDoubleSpinBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QPointF> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QMap<uint16_t,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::addUbxMsgRates)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(TcpMessage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendTcpMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::closeConnection)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint8 , QVector<QPointF> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::gpioRates)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::tcpDisconnected)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::setUiEnabledStates)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(GeodeticPos );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::geodeticPos)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(uint8_t , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::adcSampleReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::inputSwitchReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(uint8_t , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::dacReadbackReceived)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::biasSwitchReceived)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(uint8_t , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::preampSwitchReceived)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::gainSwitchReceived)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::temperatureReceived)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint32 , quint32 , const QVector<I2cDeviceEntry> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::i2cStatsReceived)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool , bool , quint64 , const QVector<CalibStruct> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::calibReceived)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QVector<GnssSatellite> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::satsReceived)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint8 , const QVector<GnssConfigStruct> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::gnssConfigsReceived)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::timeAccReceived)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::freqAccReceived)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::intCounterReceived)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::txBufReceived)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::txBufPeakReceived)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::rxBufReceived)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::rxBufPeakReceived)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint16 , quint16 , quint8 , quint8 , quint8 , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::gpsMonHWReceived)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(qint8 , quint8 , qint8 , quint8 , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::gpsMonHW2Received)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::gpsVersionReceived)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::gpsFixReceived)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::ubxUptimeReceived)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const UbxTimePulseStruct & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::gpsTP5Received)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const Histogram & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::histogramReceived)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(GPIO_PIN );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::triggerSelectionReceived)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::timepulseReceived)) {
                *result = 33;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 66)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 66;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 66)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 66;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::addUbxMsgRates(QMap<uint16_t,int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sendTcpMessage(TcpMessage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::closeConnection()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::gpioRates(quint8 _t1, QVector<QPointF> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::tcpDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::setUiEnabledStates(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::geodeticPos(GeodeticPos _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::adcSampleReceived(uint8_t _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::inputSwitchReceived(uint8_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::dacReadbackReceived(uint8_t _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::biasSwitchReceived(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MainWindow::preampSwitchReceived(uint8_t _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MainWindow::gainSwitchReceived(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MainWindow::temperatureReceived(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::i2cStatsReceived(quint32 _t1, quint32 _t2, const QVector<I2cDeviceEntry> & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MainWindow::calibReceived(bool _t1, bool _t2, quint64 _t3, const QVector<CalibStruct> & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void MainWindow::satsReceived(const QVector<GnssSatellite> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void MainWindow::gnssConfigsReceived(quint8 _t1, const QVector<GnssConfigStruct> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainWindow::timeAccReceived(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MainWindow::freqAccReceived(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MainWindow::intCounterReceived(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void MainWindow::txBufReceived(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void MainWindow::txBufPeakReceived(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void MainWindow::rxBufReceived(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void MainWindow::rxBufPeakReceived(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void MainWindow::gpsMonHWReceived(quint16 _t1, quint16 _t2, quint8 _t3, quint8 _t4, quint8 _t5, quint8 _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void MainWindow::gpsMonHW2Received(qint8 _t1, quint8 _t2, qint8 _t3, quint8 _t4, quint8 _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void MainWindow::gpsVersionReceived(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void MainWindow::gpsFixReceived(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void MainWindow::ubxUptimeReceived(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void MainWindow::gpsTP5Received(const UbxTimePulseStruct & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void MainWindow::histogramReceived(const Histogram & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void MainWindow::triggerSelectionReceived(GPIO_PIN _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void MainWindow::timepulseReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 33, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
