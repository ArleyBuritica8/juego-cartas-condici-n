#ifndef RONDA_H
#define RONDA_H

#include <vector>
#include "Carta.h"
#include "Condicion.h"

using namespace std;

class Ronda {
    friend class Serializacion;

private:
    int numero;
    Condicion condicion;
    vector<Carta> cartasJugadas;
    Carta cartaGanadora;
    bool terminada;

public:
    Ronda();
    Ronda(int numero, Condicion condicion);

    int getNumero();
    Condicion getCondicion();
    vector<Carta> getCartasJugadas();
    Carta getCartaGanadora();
    bool estaTerminada();

    void registrarCarta(Carta carta);
    Carta determinarGanadora();
    void mostrar();
};

#endif