#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador() {
    id = 0;
    nombre = "";
    puntos = 0;
}

Jugador::Jugador(int id, string nombre) {
    this->id = id;
    this->nombre = nombre;
    puntos = 0;
}

int Jugador::getId() {
    return id;
}

string Jugador::getNombre() {
    return nombre;
}

int Jugador::getPuntos() {
    return puntos;
}

void Jugador::setNombre(string nombre) {
    this->nombre = nombre;
}

void Jugador::recibirCarta(Carta carta) {
    mano.push_back(carta);
}

Carta Jugador::jugarCarta(int posicion) {

    if (posicion < 0 || posicion >= mano.size()) {
        return Carta();
    }

    Carta carta = mano[posicion];

    mano.erase(mano.begin() + posicion);

    return carta;
}

void Jugador::mostrarMano() {

    if (mano.empty()) {
        cout << nombre << " no tiene cartas." << endl;
        return;
    }

    cout << "Mano de " << nombre << ":" << endl;

    for (int i = 0; i < mano.size(); i++) {

        cout << i << ". ";
        mano[i].mostrar();
    }
}

void Jugador::mostrarInformacion() {

    cout << "Jugador: " << nombre << endl;
    cout << "ID: " << id << endl;
    cout << "Puntos: " << puntos << endl;
    cout << "Cartas: " << mano.size() << endl;
}

bool Jugador::tieneColor(string color) {

    for (Carta carta : mano) {

        if (carta.getColor() == color) {
            return true;
        }
    }

    return false;
}

void Jugador::sumarPunto() {
    puntos++;
}

int Jugador::cantidadCartas() {
    return mano.size();
}