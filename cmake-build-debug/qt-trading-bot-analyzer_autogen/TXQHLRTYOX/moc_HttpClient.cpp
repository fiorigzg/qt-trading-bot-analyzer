/****************************************************************************
** Meta object code from reading C++ file 'HttpClient.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../accsys/HttpClient.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HttpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpClient_t {
    const uint offsetsAndSize[22];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_HttpClient_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_HttpClient_t qt_meta_stringdata_HttpClient = {
    {
QT_MOC_LITERAL(0, 10), // "HttpClient"
QT_MOC_LITERAL(11, 12), // "loginSuccess"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 12), // "loginFailure"
QT_MOC_LITERAL(38, 7), // "message"
QT_MOC_LITERAL(46, 19), // "registrationSuccess"
QT_MOC_LITERAL(66, 19), // "registrationFailure"
QT_MOC_LITERAL(86, 15), // "onLoginFinished"
QT_MOC_LITERAL(102, 14), // "QNetworkReply*"
QT_MOC_LITERAL(117, 5), // "reply"
QT_MOC_LITERAL(123, 22) // "onRegistrationFinished"

    },
    "HttpClient\0loginSuccess\0\0loginFailure\0"
    "message\0registrationSuccess\0"
    "registrationFailure\0onLoginFinished\0"
    "QNetworkReply*\0reply\0onRegistrationFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpClient[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    1,   51,    2, 0x06,    2 /* Public */,
       5,    0,   54,    2, 0x06,    4 /* Public */,
       6,    1,   55,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   58,    2, 0x08,    7 /* Private */,
      10,    1,   61,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void HttpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HttpClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loginSuccess(); break;
        case 1: _t->loginFailure((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->registrationSuccess(); break;
        case 3: _t->registrationFailure((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->onLoginFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 5: _t->onRegistrationFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpClient::loginSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HttpClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpClient::loginFailure)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HttpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpClient::registrationSuccess)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (HttpClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpClient::registrationFailure)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject HttpClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_HttpClient.offsetsAndSize,
    qt_meta_data_HttpClient,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_HttpClient_t
, QtPrivate::TypeAndForceComplete<HttpClient, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>


>,
    nullptr
} };


const QMetaObject *HttpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void HttpClient::loginSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HttpClient::loginFailure(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HttpClient::registrationSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void HttpClient::registrationFailure(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
