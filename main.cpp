#include <iostream>
#include <vector>
#include "Condicion.h"

using namespace std;

int main() {

    vector<Carta> cartas;

    cartas.push_back(Carta("Azul", 8));
    cartas.push_back(Carta("Rojo", 1));
    cartas.push_back(Carta("Azul", 4));
    cartas.push_back(Carta("Verde", 10));
    cartas.push_back(Carta("Azul", 2));

    Condicion condicion("Azul", TipoOrden::MENOR);

    cout << "Condicion:" << endl;
    condicion.mostrar();

    cout << endl;

    Carta ganadora = condicion.determinarGanadora(cartas);

    cout << "Carta ganadora: ";
    ganadora.mostrar();

    return 0;
}