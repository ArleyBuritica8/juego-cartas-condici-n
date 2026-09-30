#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <string>
#include "Baraja.h"
#include "Jugador.h"
#include "Ronda.h"

using namespace std;

class Serializacion;

class Juego {
    friend class Serializacion;

private:
    Baraja baraja;
    vector<Jugador> jugadores;
    vector<Ronda> rondas;

    int rondaActual;
    int cantidadJugadores;
    int cartasPorJugador;
    bool iniciado;

public:
    Juego();

    void configurar();
    void iniciarJuego();
    void jugarRonda();
    void mostrarEstado();

    void agregarJugador(int id, string nombre);
    void repartirCartas();

    void guardarPartida();
    void cargarPartida();

    void mostrarMenu();

    bool estaIniciado();
    int getRondaActual();
    int getCantidadJugadores();
};

#endif