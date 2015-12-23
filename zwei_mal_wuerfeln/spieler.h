#ifndef SPIELER_H
#define SPIELER_H
#include <QObject>

class Spieler : public QObject
{
    Q_OBJECT

public:
    // Nur Pointer vom Typ QObject erlauben
    explicit Spieler(QObject * parent_p = 0);
    int generiereZufallszahl();

signals:
    void zahlErster(QString zahl_str);
    void zahlZweiter(QString zahl_str);

public slots:
    void buttonErster();
    void buttonZweiter();

};
#endif // SPIELER_H
