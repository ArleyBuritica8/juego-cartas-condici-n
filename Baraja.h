#ifndef BARAJA_H
#define BARAJA_H

#include <vector>
#include "Carta.h"

using namespace std;

class Baraja {
private:
    vector<Carta> cartas;

public:
    Baraja();

    void crearBaraja();
    void mezclar();
    Carta sacarCarta();

    bool estaVacia();
    int cantidadCartas();

    void mostrar();
};

#endif