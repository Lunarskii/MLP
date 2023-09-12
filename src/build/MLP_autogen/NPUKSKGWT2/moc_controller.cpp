/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../controller/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__Controller_t {
    QByteArrayData data[19];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_s21__Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_s21__Controller_t qt_meta_stringdata_s21__Controller = {
    {
QT_MOC_LITERAL(0, 0, 15), // "s21::Controller"
QT_MOC_LITERAL(1, 16, 22), // "ModelNotFoundException"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 11), // "std::string"
QT_MOC_LITERAL(4, 52, 3), // "msg"
QT_MOC_LITERAL(5, 56, 15), // "AddErrorToGraph"
QT_MOC_LITERAL(6, 72, 7), // "fp_type"
QT_MOC_LITERAL(7, 80, 5), // "error"
QT_MOC_LITERAL(8, 86, 5), // "epoch"
QT_MOC_LITERAL(9, 92, 9), // "SetModel_"
QT_MOC_LITERAL(10, 102, 18), // "PerceptronSettings"
QT_MOC_LITERAL(11, 121, 8), // "settings"
QT_MOC_LITERAL(12, 130, 9), // "ModelType"
QT_MOC_LITERAL(13, 140, 4), // "type"
QT_MOC_LITERAL(14, 145, 14), // "StartTraining_"
QT_MOC_LITERAL(15, 160, 9), // "file_path"
QT_MOC_LITERAL(16, 170, 11), // "std::size_t"
QT_MOC_LITERAL(17, 182, 16), // "number_of_epochs"
QT_MOC_LITERAL(18, 199, 13) // "StartTesting_"

    },
    "s21::Controller\0ModelNotFoundException\0"
    "\0std::string\0msg\0AddErrorToGraph\0"
    "fp_type\0error\0epoch\0SetModel_\0"
    "PerceptronSettings\0settings\0ModelType\0"
    "type\0StartTraining_\0file_path\0std::size_t\0"
    "number_of_epochs\0StartTesting_"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    2,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   47,    2, 0x08 /* Private */,
      14,    2,   52,    2, 0x08 /* Private */,
      18,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::UInt,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 16,   15,   17,
    QMetaType::Void, 0x80000000 | 3,   15,

       0        // eod
};

void s21::Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ModelNotFoundException((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->AddErrorToGraph((*reinterpret_cast< fp_type(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 2: _t->SetModel_((*reinterpret_cast< PerceptronSettings(*)>(_a[1])),(*reinterpret_cast< ModelType(*)>(_a[2]))); break;
        case 3: _t->StartTraining_((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::size_t(*)>(_a[2]))); break;
        case 4: _t->StartTesting_((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::ModelNotFoundException)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)(fp_type , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::AddErrorToGraph)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject s21::Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_s21__Controller.data,
    qt_meta_data_s21__Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *s21::Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int s21::Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void s21::Controller::ModelNotFoundException(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void s21::Controller::AddErrorToGraph(fp_type _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
