#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Carta.h"

using namespace std;

class Jugador {
private:
    int id;
    string nombre;
    vector<Carta> mano;
    int puntos;

public:
    Jugador();
    Jugador(int id, string nombre);

    int getId();
    string getNombre();
    int getPuntos();

    void setNombre(string nombre);

    void recibirCarta(Carta carta);
    Carta jugarCarta(int posicion);

    void mostrarMano();
    void mostrarInformacion();

    bool tieneColor(string color);

    void sumarPunto();
    int cantidadCartas();
};

#endif