#include "Carta.h"
#include <iostream>

using namespace std;

Carta::Carta() {
    color = "";
    numero = 0;
}

Carta::Carta(string color, int numero) {
    this->color = color;
    this->numero = numero;
}

string Carta::getColor() {
    return color;
}

int Carta::getNumero() {
    return numero;
}

void Carta::setColor(string color) {
    this->color = color;
}

void Carta::setNumero(int numero) {
    this->numero = numero;
}

void Carta::mostrar() {
    cout << color << " " << numero << endl;
}