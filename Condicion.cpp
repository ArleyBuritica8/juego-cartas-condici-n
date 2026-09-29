#include "Condicion.h"
#include <iostream>

using namespace std;

Condicion::Condicion() {
    color = "";
    orden = TipoOrden::MAYOR;
}

Condicion::Condicion(string color, TipoOrden orden) {
    this->color = color;
    this->orden = orden;
}

string Condicion::getColor() {
    return color;
}

TipoOrden Condicion::getOrden() {
    return orden;
}

void Condicion::setColor(string color) {
    this->color = color;
}

void Condicion::setOrden(TipoOrden orden) {
    this->orden = orden;
}

bool Condicion::cumple(Carta carta) {

    return carta.getColor() == color;
}

Carta Condicion::determinarGanadora(vector<Carta> cartas) {

    Carta ganadora;

    bool encontrada = false;

    for (Carta carta : cartas) {

        if (!cumple(carta)) {
            continue;
        }

        if (!encontrada) {
            ganadora = carta;
            encontrada = true;
        }
        else if (orden == TipoOrden::MAYOR &&
                 carta.getNumero() > ganadora.getNumero()) {

            ganadora = carta;
        }
        else if (orden == TipoOrden::MENOR &&
                 carta.getNumero() < ganadora.getNumero()) {

            ganadora = carta;
        }
    }

    return ganadora;
}

void Condicion::mostrar() {

    cout << "Color: " << color << endl;

    cout << "Orden: ";

    if (orden == TipoOrden::MAYOR) {
        cout << "MAYOR";
    }
    else {
        cout << "MENOR";
    }

    cout << endl;
}