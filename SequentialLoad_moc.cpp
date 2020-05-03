/****************************************************************************
** Meta object code from reading C++ file 'SequentialLoad.h'
**
** Created: Mon Apr 27 00:39:20 2020
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SequentialLoad.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SequentialLoad.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SequentialLoadProcessing[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x0a,
      37,   25,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SequentialLoadProcessing[] = {
    "SequentialLoadProcessing\0\0previous()\0"
    "next()\0"
};

void SequentialLoadProcessing::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SequentialLoadProcessing *_t = static_cast<SequentialLoadProcessing *>(_o);
        switch (_id) {
        case 0: _t->previous(); break;
        case 1: _t->next(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SequentialLoadProcessing::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SequentialLoadProcessing::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SequentialLoadProcessing,
      qt_meta_data_SequentialLoadProcessing, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SequentialLoadProcessing::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SequentialLoadProcessing::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SequentialLoadProcessing::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SequentialLoadProcessing))
        return static_cast<void*>(const_cast< SequentialLoadProcessing*>(this));
    return QObject::qt_metacast(_clname);
}

int SequentialLoadProcessing::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_SequentialLoadActionNext[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_SequentialLoadActionNext[] = {
    "SequentialLoadActionNext\0"
};

void SequentialLoadActionNext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SequentialLoadActionNext::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SequentialLoadActionNext::staticMetaObject = {
    { &DzAction::staticMetaObject, qt_meta_stringdata_SequentialLoadActionNext,
      qt_meta_data_SequentialLoadActionNext, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SequentialLoadActionNext::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SequentialLoadActionNext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SequentialLoadActionNext::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SequentialLoadActionNext))
        return static_cast<void*>(const_cast< SequentialLoadActionNext*>(this));
    return DzAction::qt_metacast(_clname);
}

int SequentialLoadActionNext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DzAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SequentialLoadActionPrevious[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_SequentialLoadActionPrevious[] = {
    "SequentialLoadActionPrevious\0"
};

void SequentialLoadActionPrevious::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SequentialLoadActionPrevious::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SequentialLoadActionPrevious::staticMetaObject = {
    { &DzAction::staticMetaObject, qt_meta_stringdata_SequentialLoadActionPrevious,
      qt_meta_data_SequentialLoadActionPrevious, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SequentialLoadActionPrevious::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SequentialLoadActionPrevious::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SequentialLoadActionPrevious::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SequentialLoadActionPrevious))
        return static_cast<void*>(const_cast< SequentialLoadActionPrevious*>(this));
    return DzAction::qt_metacast(_clname);
}

int SequentialLoadActionPrevious::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DzAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SequentialLoadPaneAction[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_SequentialLoadPaneAction[] = {
    "SequentialLoadPaneAction\0"
};

void SequentialLoadPaneAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SequentialLoadPaneAction::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SequentialLoadPaneAction::staticMetaObject = {
    { &DzPaneAction::staticMetaObject, qt_meta_stringdata_SequentialLoadPaneAction,
      qt_meta_data_SequentialLoadPaneAction, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SequentialLoadPaneAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SequentialLoadPaneAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SequentialLoadPaneAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SequentialLoadPaneAction))
        return static_cast<void*>(const_cast< SequentialLoadPaneAction*>(this));
    return DzPaneAction::qt_metacast(_clname);
}

int SequentialLoadPaneAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DzPaneAction::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_SequentialLoadPane[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      35,   19,   19,   19, 0x0a,
      52,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SequentialLoadPane[] = {
    "SequentialLoadPane\0\0selectFolder()\0"
    "listBoxClicked()\0listFigure()\0"
};

void SequentialLoadPane::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SequentialLoadPane *_t = static_cast<SequentialLoadPane *>(_o);
        switch (_id) {
        case 0: _t->selectFolder(); break;
        case 1: _t->listBoxClicked(); break;
        case 2: _t->listFigure(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SequentialLoadPane::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SequentialLoadPane::staticMetaObject = {
    { &DzPane::staticMetaObject, qt_meta_stringdata_SequentialLoadPane,
      qt_meta_data_SequentialLoadPane, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SequentialLoadPane::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SequentialLoadPane::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SequentialLoadPane::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SequentialLoadPane))
        return static_cast<void*>(const_cast< SequentialLoadPane*>(this));
    return DzPane::qt_metacast(_clname);
}

int SequentialLoadPane::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DzPane::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
