#include <iostream>
#include "Ronda.h"

using namespace std;

int main() {

    Condicion condicion("Azul", TipoOrden::MENOR);

    Ronda ronda(1, condicion);

    ronda.registrarCarta(Carta("Azul", 8));
    ronda.registrarCarta(Carta("Rojo", 5));
    ronda.registrarCarta(Carta("Azul", 4));
    ronda.registrarCarta(Carta("Azul", 2));

    cout << "Informacion de la ronda:" << endl;
    ronda.mostrar();

    cout << endl;

    Carta ganadora = ronda.determinarGanadora();

    cout << "Ganadora de la ronda: ";
    ganadora.mostrar();

    return 0;
}