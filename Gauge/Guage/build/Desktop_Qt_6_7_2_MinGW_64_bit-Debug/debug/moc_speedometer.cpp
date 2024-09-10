/****************************************************************************
** Meta object code from reading C++ file 'speedometer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../speedometer.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'speedometer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSspeedometerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSspeedometerENDCLASS = QtMocHelpers::stringData(
    "speedometer",
    "speedometerSizeChanged",
    "",
    "startAngleChanged",
    "alignAngleChanged",
    "lowestRangeChanged",
    "highestRangeChanged",
    "speedChanged",
    "arcWidthChanged",
    "outerColorChanged",
    "innerColorChanged",
    "textColorChanged",
    "backgroundColorChanged",
    "speedometerSize",
    "startAngle",
    "alignAngle",
    "lowestRange",
    "highestRange",
    "speed",
    "arcWidth",
    "outerColor",
    "innerColor",
    "textColor",
    "backgroundColor"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSspeedometerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
      11,   91, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,   12 /* Public */,
       3,    0,   81,    2, 0x06,   13 /* Public */,
       4,    0,   82,    2, 0x06,   14 /* Public */,
       5,    0,   83,    2, 0x06,   15 /* Public */,
       6,    0,   84,    2, 0x06,   16 /* Public */,
       7,    0,   85,    2, 0x06,   17 /* Public */,
       8,    0,   86,    2, 0x06,   18 /* Public */,
       9,    0,   87,    2, 0x06,   19 /* Public */,
      10,    0,   88,    2, 0x06,   20 /* Public */,
      11,    0,   89,    2, 0x06,   21 /* Public */,
      12,    0,   90,    2, 0x06,   22 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      13, QMetaType::QReal, 0x00015103, uint(0), 0,
      14, QMetaType::QReal, 0x00015103, uint(1), 0,
      15, QMetaType::QReal, 0x00015103, uint(2), 0,
      16, QMetaType::QReal, 0x00015103, uint(3), 0,
      17, QMetaType::QReal, 0x00015103, uint(4), 0,
      18, QMetaType::QReal, 0x00015103, uint(5), 0,
      19, QMetaType::Int, 0x00015103, uint(6), 0,
      20, QMetaType::QColor, 0x00015103, uint(7), 0,
      21, QMetaType::QColor, 0x00015103, uint(8), 0,
      22, QMetaType::QColor, 0x00015103, uint(9), 0,
      23, QMetaType::QColor, 0x00015103, uint(10), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject speedometer::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_CLASSspeedometerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSspeedometerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSspeedometerENDCLASS_t,
        // property 'speedometerSize'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'startAngle'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'alignAngle'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'lowestRange'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'highestRange'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'speed'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'arcWidth'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'outerColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'innerColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'textColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // property 'backgroundColor'
        QtPrivate::TypeAndForceComplete<QColor, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<speedometer, std::true_type>,
        // method 'speedometerSizeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startAngleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'alignAngleChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lowestRangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'highestRangeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'speedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'arcWidthChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'outerColorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'innerColorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'textColorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'backgroundColorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void speedometer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<speedometer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->speedometerSizeChanged(); break;
        case 1: _t->startAngleChanged(); break;
        case 2: _t->alignAngleChanged(); break;
        case 3: _t->lowestRangeChanged(); break;
        case 4: _t->highestRangeChanged(); break;
        case 5: _t->speedChanged(); break;
        case 6: _t->arcWidthChanged(); break;
        case 7: _t->outerColorChanged(); break;
        case 8: _t->innerColorChanged(); break;
        case 9: _t->textColorChanged(); break;
        case 10: _t->backgroundColorChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::speedometerSizeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::startAngleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::alignAngleChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::lowestRangeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::highestRangeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::speedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::arcWidthChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::outerColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::innerColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::textColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (speedometer::*)();
            if (_t _q_method = &speedometer::backgroundColorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<speedometer *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = _t->getspeedometerSize(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = _t->getStartAngle(); break;
        case 2: *reinterpret_cast< qreal*>(_v) = _t->getAlignAngle(); break;
        case 3: *reinterpret_cast< qreal*>(_v) = _t->getLowestRange(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = _t->getHighestRange(); break;
        case 5: *reinterpret_cast< qreal*>(_v) = _t->getSpeed(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getArcWidth(); break;
        case 7: *reinterpret_cast< QColor*>(_v) = _t->getOuterColor(); break;
        case 8: *reinterpret_cast< QColor*>(_v) = _t->getInnerColor(); break;
        case 9: *reinterpret_cast< QColor*>(_v) = _t->getTextColor(); break;
        case 10: *reinterpret_cast< QColor*>(_v) = _t->getBackgroundColor(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<speedometer *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpeedometerSize(*reinterpret_cast< qreal*>(_v)); break;
        case 1: _t->setStartAngle(*reinterpret_cast< qreal*>(_v)); break;
        case 2: _t->setAlignAngle(*reinterpret_cast< qreal*>(_v)); break;
        case 3: _t->setLowestRange(*reinterpret_cast< qreal*>(_v)); break;
        case 4: _t->setHighestRange(*reinterpret_cast< qreal*>(_v)); break;
        case 5: _t->setSpeed(*reinterpret_cast< qreal*>(_v)); break;
        case 6: _t->setArcWidth(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setOuterColor(*reinterpret_cast< QColor*>(_v)); break;
        case 8: _t->setInnerColor(*reinterpret_cast< QColor*>(_v)); break;
        case 9: _t->setTextColor(*reinterpret_cast< QColor*>(_v)); break;
        case 10: _t->setBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *speedometer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *speedometer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSspeedometerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int speedometer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void speedometer::speedometerSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void speedometer::startAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void speedometer::alignAngleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void speedometer::lowestRangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void speedometer::highestRangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void speedometer::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void speedometer::arcWidthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void speedometer::outerColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void speedometer::innerColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void speedometer::textColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void speedometer::backgroundColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
