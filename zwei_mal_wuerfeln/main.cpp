#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "spieler.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);   // Programm Objekt
    QQmlApplicationEngine engine;   // Laden von QML Dateien

    Spieler spieler;                // Programmlogik

    // Zeiger auf das Fensterobjekt // GUI
    QQmlContext * ctx = engine.rootContext();

    // Daten von 'spieler' den QML Komponenten freigeben
    ctx->setContextProperty("spielerData", &spieler);

    // Design Laden und Programm starten
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
