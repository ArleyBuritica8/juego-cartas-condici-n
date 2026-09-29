#include "Baraja.h"
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

Baraja::Baraja() {
    crearBaraja();
}

void Baraja::crearBaraja() {

    cartas.clear();

    vector<string> colores = {
        "Rojo",
        "Azul",
        "Verde",
        "Amarillo"
    };

    for (string color : colores) {

        for (int numero = 1; numero <= 10; numero++) {

            cartas.push_back(Carta(color, numero));
        }
    }
}

void Baraja::mezclar() {

    random_device rd;
    mt19937 generador(rd());

    shuffle(cartas.begin(), cartas.end(), generador);
}

Carta Baraja::sacarCarta() {

    if (cartas.empty()) {
        return Carta();
    }

    Carta carta = cartas.back();

    cartas.pop_back();

    return carta;
}

bool Baraja::estaVacia() {

    return cartas.empty();
}

int Baraja::cantidadCartas() {

    return cartas.size();
}

void Baraja::mostrar() {

    for (Carta carta : cartas) {

        carta.mostrar();
    }
}