/****************************************************************************
** Meta object code from reading C++ file 'histogramdataform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../muondetector-gui/src/main/histogramdataform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'histogramdataform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_histogramDataForm_t {
    QByteArrayData data[11];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_histogramDataForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_histogramDataForm_t qt_meta_stringdata_histogramDataForm = {
    {
QT_MOC_LITERAL(0, 0, 17), // "histogramDataForm"
QT_MOC_LITERAL(1, 18, 19), // "onHistogramReceived"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 9), // "Histogram"
QT_MOC_LITERAL(4, 49, 1), // "h"
QT_MOC_LITERAL(5, 51, 22), // "onUiEnabledStateChange"
QT_MOC_LITERAL(6, 74, 9), // "connected"
QT_MOC_LITERAL(7, 84, 16), // "updateHistoTable"
QT_MOC_LITERAL(8, 101, 26), // "on_tableWidget_cellClicked"
QT_MOC_LITERAL(9, 128, 3), // "row"
QT_MOC_LITERAL(10, 132, 6) // "column"

    },
    "histogramDataForm\0onHistogramReceived\0"
    "\0Histogram\0h\0onUiEnabledStateChange\0"
    "connected\0updateHistoTable\0"
    "on_tableWidget_cellClicked\0row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_histogramDataForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,
       7,    0,   40,    2, 0x08 /* Private */,
       8,    2,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

       0        // eod
};

void histogramDataForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<histogramDataForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onHistogramReceived((*reinterpret_cast< const Histogram(*)>(_a[1]))); break;
        case 1: _t->onUiEnabledStateChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->updateHistoTable(); break;
        case 3: _t->on_tableWidget_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject histogramDataForm::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_histogramDataForm.data,
    qt_meta_data_histogramDataForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *histogramDataForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *histogramDataForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_histogramDataForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int histogramDataForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
