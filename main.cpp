#include <iostream>
#include "Baraja.h"

using namespace std;

int main() {

    Baraja baraja;

    cout << "Cantidad inicial de cartas: "
         << baraja.cantidadCartas() << endl;

    baraja.mezclar();

    cout << "\nSacando 3 cartas:\n";

    for (int i = 0; i < 3; i++) {

        Carta carta = baraja.sacarCarta();

        cout << "Carta " << i + 1 << ": ";
        carta.mostrar();
    }

    cout << "\nCartas restantes: "
         << baraja.cantidadCartas() << endl;

    return 0;
}