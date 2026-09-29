#include <iostream>
#include "Jugador.h"

using namespace std;

int main() {

    Jugador jugador1(1, "Arley");

    jugador1.recibirCarta(Carta("Azul", 8));
    jugador1.recibirCarta(Carta("Rojo", 3));
    jugador1.recibirCarta(Carta("Verde", 6));

    jugador1.mostrarInformacion();

    cout << endl;

    jugador1.mostrarMano();

    cout << endl;

    if (jugador1.tieneColor("Azul")) {
        cout << "El jugador tiene una carta Azul." << endl;
    }

    jugador1.sumarPunto();

    cout << endl;
    cout << "Puntos despues de ganar una ronda: "
         << jugador1.getPuntos() << endl;

    return 0;
}