/****************************************************************************
** Meta object code from reading C++ file 'custom_histogram_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../muondetector-gui/src/main/custom_histogram_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'custom_histogram_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustomHistogram_t {
    QByteArrayData data[22];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustomHistogram_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustomHistogram_t qt_meta_stringdata_CustomHistogram = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CustomHistogram"
QT_MOC_LITERAL(1, 16, 6), // "update"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "clear"
QT_MOC_LITERAL(4, 30, 16), // "setStatusEnabled"
QT_MOC_LITERAL(5, 47, 6), // "status"
QT_MOC_LITERAL(6, 54, 7), // "setXMin"
QT_MOC_LITERAL(7, 62, 3), // "val"
QT_MOC_LITERAL(8, 66, 7), // "setXMax"
QT_MOC_LITERAL(9, 74, 7), // "getLogX"
QT_MOC_LITERAL(10, 82, 7), // "setLogY"
QT_MOC_LITERAL(11, 90, 7), // "getLogY"
QT_MOC_LITERAL(12, 98, 11), // "rescalePlot"
QT_MOC_LITERAL(13, 110, 16), // "getHistogramPlot"
QT_MOC_LITERAL(14, 127, 17), // "QwtPlotHistogram*"
QT_MOC_LITERAL(15, 145, 7), // "setData"
QT_MOC_LITERAL(16, 153, 16), // "QVector<QPointF>"
QT_MOC_LITERAL(17, 170, 9), // "Histogram"
QT_MOC_LITERAL(18, 180, 4), // "hist"
QT_MOC_LITERAL(19, 185, 9), // "popUpMenu"
QT_MOC_LITERAL(20, 195, 3), // "pos"
QT_MOC_LITERAL(21, 199, 12) // "exportToFile"

    },
    "CustomHistogram\0update\0\0clear\0"
    "setStatusEnabled\0status\0setXMin\0val\0"
    "setXMax\0getLogX\0setLogY\0getLogY\0"
    "rescalePlot\0getHistogramPlot\0"
    "QwtPlotHistogram*\0setData\0QVector<QPointF>\0"
    "Histogram\0hist\0popUpMenu\0pos\0exportToFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustomHistogram[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    1,   86,    2, 0x0a /* Public */,
       6,    1,   89,    2, 0x0a /* Public */,
       8,    1,   92,    2, 0x0a /* Public */,
       9,    0,   95,    2, 0x0a /* Public */,
      10,    1,   96,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x0a /* Public */,
      13,    0,  101,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      15,    1,  105,    2, 0x0a /* Public */,
      19,    1,  108,    2, 0x08 /* Private */,
      21,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Bool,
    QMetaType::Void,
    0x80000000 | 14,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::QPoint,   20,
    QMetaType::Void,

       0        // eod
};

void CustomHistogram::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CustomHistogram *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->clear(); break;
        case 2: _t->setStatusEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setXMin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setXMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: { bool _r = _t->getLogX();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setLogY((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: { bool _r = _t->getLogY();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->rescalePlot(); break;
        case 9: { QwtPlotHistogram* _r = _t->getHistogramPlot();
            if (_a[0]) *reinterpret_cast< QwtPlotHistogram**>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setData((*reinterpret_cast< const QVector<QPointF>(*)>(_a[1]))); break;
        case 11: _t->setData((*reinterpret_cast< const Histogram(*)>(_a[1]))); break;
        case 12: _t->popUpMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 13: _t->exportToFile(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QPointF> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CustomHistogram::staticMetaObject = { {
    &QwtPlot::staticMetaObject,
    qt_meta_stringdata_CustomHistogram.data,
    qt_meta_data_CustomHistogram,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustomHistogram::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustomHistogram::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustomHistogram.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Histogram"))
        return static_cast< Histogram*>(this);
    return QwtPlot::qt_metacast(_clname);
}

int CustomHistogram::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
