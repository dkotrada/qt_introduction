import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow { // rootContext ist das Programm-Fenster
    visible: true
    width: 300
    height: 380
    maximumHeight: height
    maximumWidth: width
    title: "Zwei mal würfeln"
    property int schrift_groesse: 40

    // Connections Objekt erstellt eine Verbindung zu QML Signal
    Connections{
        target: spielerData                 // öffentlicher Name

        // on<Signal> Syntax. Reagiert wenn ein Signal empfangen
        onZahlErster:{                      // signalName -> onSignalName
            ersterLabel.text = zahl_str     // aktualisiert 'ersterLabel'
        }

        onZahlZweiter:{                     // Reagiert beim Eintreffen des Signals
            zweiterLabel.text = zahl_str    // aktualisiert 'zweiterLabel'
        }
    }

    Button {
        id: wuerfeln1
        x: 30
        y: 290
        width: 100
        height: 30

        // Slot is verfügbar über die Verbindung "spielerData"
        onClicked: spielerData.buttonErster()
        Label{
            text: "Spieler Nr.1"
            font.pixelSize: 14
            anchors.centerIn: parent
        }
    }

    Button {
        id: wuerfeln2
        x: 170
        y: 290
        width: 100
        height: 30

        // Über Verbindung "fensterObj" einfach den Slot aufrufen
        onClicked: spielerData.buttonZweiter()
        Label{
            text: "Spieler Nr.2"
            font.pixelSize: 14
            anchors.centerIn: parent

        }
    }

    Label {
        id: ersterLabel
        x: 62
        y: 215
        text: "00"
        font.pixelSize: schrift_groesse
    }

    Label {
        id: zweiterLabel
        x: 201
        y: 215
        text: "00"
        font.pixelSize: schrift_groesse
    }

    Image {
        id: image1
        x: 100
        y: 64
        width: 89
        height: 100
        source: "dice.png"
    }
}























