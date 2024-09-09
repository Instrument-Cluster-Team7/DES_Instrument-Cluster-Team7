#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QDebug>

#include "rpm_gauge.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<rpm_gauge>("com.DESInstrumentClusterTeam7.speedometer", 1, 0, "Speedometer");

    QQmlApplicationEngine engine;
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

    // find speedometer object
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

    // using timer to check variation of Guage
    qreal val = 0;
    ptrSpeedometer->setSpeed(val);

    QTimer *timer1 = new QTimer(&app);
    bool direction;

    QObject::connect(timer1, &QTimer::timeout, [&]() {
//        // just increase the speed value [infinitely]
//        val += 1;

        if(val >= 4000)
            direction = false;
        else if (val <= 0.1)
            direction = true;

        if(direction)
            val = val + 10;
        else
            val = val - 10;

        ptrSpeedometer->setSpeed(val);
    });

    timer1->start(10);

    return app.exec();
}
