#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>

#include "classgps.h"
#include "classcompass.h"
#include "classanemometer.h"
#include "classgyro.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<ClassGPS>("ce.classgps",1,0,"ClassGPS");
    qmlRegisterType<ClassCOMPASS>("ce.classcompass",1,0,"ClassCOMPASS");
    qmlRegisterType<ClassANEMOMETER>("ce.classanemometer",1,0,"ClassANEMOMETER");
    qmlRegisterType<ClassGYRO>("ce.classgyro",1,0,"ClassGYRO");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);  

    return app.exec();
}
