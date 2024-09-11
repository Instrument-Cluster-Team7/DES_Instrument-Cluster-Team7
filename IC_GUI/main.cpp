#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QDebug>
#include <QElapsedTimer>
#include <QQmlContext>
#include <QCoreApplication>
#include <QPropertyAnimation>

#include "Clock.h"
#include "speedProvider.h"
#include "rpm_gauge.h"
#include "receiver.h"

qreal calculateSpeed(qreal rpm, qreal tire_circumference){
    return rpm * tire_circumference * 0.06;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<rpm_gauge>("com.DESInstrumentClusterTeam7.speedometer", 1, 0, "Speedometer");

    QQmlApplicationEngine engine;

    /*///////////////////////////////////////////////////////// set running rate */
    QElapsedTimer runTime;
    runTime.start(); // record time

    QTimer timer_run;
    QObject::connect(&timer_run, &QTimer::timeout, [&engine, &runTime]() {
            qint64 elapsedTime = runTime.elapsed() / 1000;
            engine.rootContext()->setContextProperty("elapsedTime", elapsedTime);
    });
    timer_run.start(500); // update time periodical : per 0.5 sec

    /*///////////////////////////////////////////////////////// clock */
    Clock clock;
    SpeedProvider speedProvider;

    speedProvider.setMinSpeed(-200);
    speedProvider.setMaxSpeed(200);

    engine.rootContext()->setContextProperty("Clock", &clock);
    engine.rootContext()->setContextProperty("speedProvider", &speedProvider);

    /*///////////////////////////////////////////////////////// connect & load engine */
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    // find root object
    QObject *object = engine.rootObjects().isEmpty() ? nullptr : engine.rootObjects().first();
    if (!object) {
        qCritical() << "No root objects found!";
        return -1;
    }

    // find RPM speedometer object
    QObject *speedometerObj = object->findChild<QObject*>("RPM_Gauge");
    if (!speedometerObj) {
        qCritical() << "Speedometer object not found in QML!";
        return -1;
    }
    // engine.rootObjects() : bring root object from QML file
    // findChild : find QML object which is named 'speedoMeter'

    // casting to speedometer object
    rpm_gauge *ptrSpeedometer = qobject_cast<rpm_gauge*>(speedometerObj);
    if (!ptrSpeedometer) {
        qCritical() << "Failed to cast Speedometer object!";
        return -1;
    }


    /*///////////////////////////////////////////////////////// test RPM gauge with random speed */
    qreal tire_circumference = 0.214;
    qreal gear_ratio = 2.0;
    qreal speed = 0.0;
    qreal rpm = 0.0;
    Receiver rcv;


    std::srand(std::time(nullptr));
    QTimer *timer_test_rpm = new QTimer(&app);

    QPropertyAnimation animation(speedometerObj, "speed");
    animation.setDuration(1000);
    animation.setEasingCurve(QEasingCurve::OutCubic);

    if (rcv.initialize() == Receiver::SUCCEDED){
        QObject::connect(&rcv, &Receiver::speedReceived, [&](int rpm){

            animation.setStartValue(speedometerObj->property("speed"));
            animation.setEndValue(rpm);
            animation.start();

            float speed_kmh = calculateSpeed(rpm, tire_circumference);
            speedProvider.setSpeed(speed_kmh);
            engine.rootContext()->setContextProperty("rpm_value", static_cast<int>(rpm));

            qDebug() << "Random Speed: " << speed_kmh << " km/h, RPM: " << rpm;
        });
    }
    else{
        qDebug() << "CAN connection failed";
    }

    return app.exec();
}
