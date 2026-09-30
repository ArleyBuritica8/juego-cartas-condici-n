#ifndef CONDICION_H
#define CONDICION_H

#include <string>
#include <vector>
#include "Carta.h"
#include "TipoOrden.h"

using namespace std;

class Condicion {
    friend class Serializacion;

private:
    string color;
    TipoOrden orden;

public:
    Condicion();
    Condicion(string color, TipoOrden orden);

    string getColor();
    TipoOrden getOrden();

    void setColor(string color);
    void setOrden(TipoOrden orden);

    bool cumple(Carta carta);
    Carta determinarGanadora(vector<Carta> cartas);
    void mostrar();
};

#endif