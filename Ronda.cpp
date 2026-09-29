#include "Ronda.h"
#include <iostream>

using namespace std;

Ronda::Ronda() {
    numero = 0;
    condicion = Condicion();
    terminada = false;
}

Ronda::Ronda(int numero, Condicion condicion) {
    this->numero = numero;
    this->condicion = condicion;
    terminada = false;
}

int Ronda::getNumero() {
    return numero;
}

Condicion Ronda::getCondicion() {
    return condicion;
}

vector<Carta> Ronda::getCartasJugadas() {
    return cartasJugadas;
}

Carta Ronda::getCartaGanadora() {
    return cartaGanadora;
}

bool Ronda::estaTerminada() {
    return terminada;
}

void Ronda::registrarCarta(Carta carta) {
    cartasJugadas.push_back(carta);
}

Carta Ronda::determinarGanadora() {

    cartaGanadora = condicion.determinarGanadora(cartasJugadas);

    terminada = true;

    return cartaGanadora;
}

void Ronda::mostrar() {

    cout << "Ronda: " << numero << endl;

    cout << "Condicion:" << endl;
    condicion.mostrar();

    cout << "Cartas jugadas:" << endl;

    for (Carta carta : cartasJugadas) {
        carta.mostrar();
    }

    if (terminada) {
        cout << "Carta ganadora: ";
        cartaGanadora.mostrar();
    }
}