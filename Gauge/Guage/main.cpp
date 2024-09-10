#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer> // timer for periodic task
#include <QDebug>
#include "receiver.h"
#include "speedometer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv); // initialize GUI & manage event loop

    qmlRegisterType<speedometer>("com.ulasdikme.speedometer", 1, 0, "Speedometer");
    // register class to enable using name 'Speedometer' on QML
    /* <speedometer> : template argument to create object on QML : definitely inheritanced Qobject
     * com.ulasdikme.speedometer : QML module name : can use on QML with import : similar concept with namespace
     * Speedometer : class name : create 'speedometer' class's object
     */

    QQmlApplicationEngine engine; // load QML file
    const QUrl url(QStringLiteral("qrc:/main.qml")); // root to load QML file
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) {
            qCritical() << "Failed to load QML file: " << url;
            QCoreApplication::exit(-1);
        }
    }, Qt::QueuedConnection);
    // check if QML loaded successfuly
    engine.load(url); // load specified url's QML file

    // find root object
    QObject *object = engine.rootObjects().isEmpty() ? nullptr : engine.rootObjects().first();
    if (!object) {
        qCritical() << "No root objects found!";
        return -1;
    }

    // find speedometer object
    QObject *speedometerObj = object->findChild<QObject*>("speedoMeter");
    if (!speedometerObj) {
        qCritical() << "Speedometer object not found in QML!";
        return -1;
    }

    // engine.rootObjects() : bring root object from QML file
    // findChild : find QML object which is named 'speedoMeter'

    // casting to speedometer object
    speedometer *ptrSpeedometer = qobject_cast<speedometer*>(speedometerObj);
    if (!ptrSpeedometer) {
        qCritical() << "Failed to cast Speedometer object!";
        return -1;
    }

    // using timer to check variation of Guage
    qreal val = 0;
    ptrSpeedometer->setSpeed(0);

    Receiver * rcv = new Receiver(&val);
    if (rcv->initialize() == Receiver::SUCCEDED){
        QObject::connect(rcv, &Receiver::speedReceived, ptrSpeedometer, &speedometer::setSpeed);
        rcv->start();
    }
    else{
        qDebug() << "CAN Communication finally failed!";
    }


    return app.exec();
}
