#ifndef SERIALIZACION_H
#define SERIALIZACION_H

#include <string>
#include <fstream>

#include "Carta.h"
#include "Baraja.h"
#include "Jugador.h"
#include "Condicion.h"
#include "Ronda.h"

using namespace std;

class Juego;

class Serializacion {
private:
    static void guardarString(ofstream& archivo, const string& texto);
    static string cargarString(ifstream& archivo);

    static void guardarCarta(ofstream& archivo, const Carta& carta);
    static Carta cargarCarta(ifstream& archivo);

    static void guardarJugador(ofstream& archivo, const Jugador& jugador);
    static Jugador cargarJugador(ifstream& archivo);

    static void guardarCondicion(ofstream& archivo, const Condicion& condicion);
    static Condicion cargarCondicion(ifstream& archivo);

    static void guardarRonda(ofstream& archivo, const Ronda& ronda);
    static Ronda cargarRonda(ifstream& archivo);

public:
    static bool guardar(const Juego& juego, string nombreArchivo);
    static bool cargar(Juego& juego, string nombreArchivo);
};

#endif