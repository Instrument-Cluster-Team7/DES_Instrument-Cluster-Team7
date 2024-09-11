#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCoreApplication>
#include "Clock.h"
#include "speedProvider.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Clock clock;
    //SpeedProvider speedProvider;
    Receiver receiver;
    receiver.initialize();
    receiver.start();

    //speedProvider.setMinSpeed(-200);
    //speedProvider.setMaxSpeed(200);

    engine.rootContext()->setContextProperty("Clock", &clock);
    //engine.rootContext()->setContextProperty("speedProvider", &speedProvider);
    engine.rootContext()->setContextProperty("Receiver", &receiver);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
