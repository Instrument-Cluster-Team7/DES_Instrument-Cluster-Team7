#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QDebug>
#include <QElapsedTimer>
#include <QQmlContext>

#include "rpm_gauge.h"

qreal calculateRPM(qreal speed, qreal tire_circumference, qreal gear_ratio){
    return (speed * 1000) / (tire_circumference * gear_ratio);
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

//    engine.rootContext()->setContextProperty("Run_time", &runTime);
//    engine.rootContext()->setContextProperty("Update_time", &timer_run);

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
    qreal tire_circumference = 0.1741;
    qreal gear_ratio = 2.0;
    qreal speed = 0.0;
    qreal rpm = 0.0;

    std::srand(std::time(nullptr));
    QTimer *timer_test_rpm = new QTimer(&app);
    QObject::connect(timer_test_rpm, &QTimer::timeout, [&](){
        speed = static_cast<qreal>(std::rand()) / RAND_MAX;
        rpm = calculateRPM(speed, tire_circumference, gear_ratio);
        ptrSpeedometer->setSpeed(rpm);

        qDebug() << "Random Speed: " << speed << " km/h, RPM: " << rpm;
    });
    timer_test_rpm->start(500);


    // check variation of Gauge [just increase speed value sequentially]
//    qreal val = 0;
//    ptrSpeedometer->setSpeed(val);

//    QTimer *timer1 = new QTimer(&app);
//    bool direction;
//    QObject::connect(timer1, &QTimer::timeout, [&]() {
//        // val += 1;

//        if(val >= 4000)
//            direction = false;
//        else if (val <= 0.1)
//            direction = true;

//        if(direction)
//            val = val + 10;
//        else
//            val = val - 10;

//        ptrSpeedometer->setSpeed(val);
//    });
//    timer1->start(10);

    return app.exec();
}
