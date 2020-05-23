#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDateTime>
#include <QDebug>
#include <QMetaObject>

#include "timeupdate.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TimeUpdate objTime;
    // Passing cpp class object to QML
    engine.rootContext()->setContextProperty("TimeUpdate", &objTime);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // Get the root object, Window
    auto rootObj = engine.rootObjects().first();

    if(rootObj) {
        // Connect QML Signal to C++ Slot
        QObject::connect(rootObj->findChild<QObject*>("ButtonStart"), SIGNAL(startTimer()), &objTime, SLOT(startTimer()));
        QObject::connect(rootObj->findChild<QObject*>("ButtonStop"), SIGNAL(stopTimer()), &objTime, SLOT(stopTimer()));
    } else {
        qDebug() << "Root Object is Null!" << endl;
    }

    // Calling QML function from C++
    QMetaObject::invokeMethod(rootObj, "myQmlFunction",
                              Q_ARG(QVariant, QDateTime::currentDateTime()));


    return app.exec();
}
