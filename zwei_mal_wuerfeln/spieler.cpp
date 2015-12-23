#include "spieler.h"
#include <cstdlib>
#include <ctime>

/**
 * Konstruktor **************************************************
 */
Spieler::Spieler(QObject *parent)
                : QObject(parent) // Autom. Speicherfreigabe
{
    // Generator initialisieren
    time_t mytime;
    srand( (unsigned) time(&mytime) );
}


/**
 * Ganzzahl generieren ******************************************
 */
int Spieler::generiereZufallszahl(){
     int zufallszahl = 0;

     for (int i = 0; i < 2; i++){           // generiere zwei Mal
        zufallszahl += ( rand() % 6) + 1;   // addiere Zufallszahl
     }
    return zufallszahl;
}


/**
 * Slot Implementierungen ***************************************
 */
void Spieler::buttonErster(){
    // Generiere Ganzzahl und wandle es in ein String um
    QString output_str = QString::number(generiereZufallszahl());

    // sende Signal "zahlErster" mit dem Parameter "output_str"
    zahlErster(output_str);
}


void Spieler::buttonZweiter(){
    // Generiere Ganzzahl und wandle es in ein String um
    QString output_str = QString::number(generiereZufallszahl());

    // sende Signal "zahlZweiter" mit dem Parameter "output_str"
    zahlZweiter(output_str);
}
