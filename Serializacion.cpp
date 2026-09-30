#include "Serializacion.h"
#include "Juego.h"

#include <iostream>
#include <cstdint>

using namespace std;

// --------------------------------------------------
// FUNCIONES PARA STRINGS
// --------------------------------------------------

void Serializacion::guardarString(ofstream& archivo, const string& texto) {

    uint32_t longitud = static_cast<uint32_t>(texto.size());

    archivo.write(
        reinterpret_cast<const char*>(&longitud),
        sizeof(longitud)
    );

    if (longitud > 0) {
        archivo.write(texto.data(), longitud);
    }
}

string Serializacion::cargarString(ifstream& archivo) {

    uint32_t longitud = 0;

    archivo.read(
        reinterpret_cast<char*>(&longitud),
        sizeof(longitud)
    );

    if (!archivo) {
        return "";
    }

    string texto(longitud, '\0');

    if (longitud > 0) {
        archivo.read(&texto[0], longitud);
    }

    return texto;
}

// --------------------------------------------------
// CARTA
// --------------------------------------------------

void Serializacion::guardarCarta(
    ofstream& archivo,
    const Carta& carta
) {

    guardarString(archivo, carta.color);

    archivo.write(
        reinterpret_cast<const char*>(&carta.numero),
        sizeof(carta.numero)
    );
}

Carta Serializacion::cargarCarta(ifstream& archivo) {

    Carta carta;

    carta.color = cargarString(archivo);

    archivo.read(
        reinterpret_cast<char*>(&carta.numero),
        sizeof(carta.numero)
    );

    return carta;
}

// --------------------------------------------------
// JUGADOR
// --------------------------------------------------

void Serializacion::guardarJugador(
    ofstream& archivo,
    const Jugador& jugador
) {

    archivo.write(
        reinterpret_cast<const char*>(&jugador.id),
        sizeof(jugador.id)
    );

    guardarString(archivo, jugador.nombre);

    archivo.write(
        reinterpret_cast<const char*>(&jugador.puntos),
        sizeof(jugador.puntos)
    );

    uint32_t cantidadCartas =
        static_cast<uint32_t>(jugador.mano.size());

    archivo.write(
        reinterpret_cast<const char*>(&cantidadCartas),
        sizeof(cantidadCartas)
    );

    for (const Carta& carta : jugador.mano) {
        guardarCarta(archivo, carta);
    }
}

Jugador Serializacion::cargarJugador(ifstream& archivo) {

    Jugador jugador;

    archivo.read(
        reinterpret_cast<char*>(&jugador.id),
        sizeof(jugador.id)
    );

    jugador.nombre = cargarString(archivo);

    archivo.read(
        reinterpret_cast<char*>(&jugador.puntos),
        sizeof(jugador.puntos)
    );

    uint32_t cantidadCartas = 0;

    archivo.read(
        reinterpret_cast<char*>(&cantidadCartas),
        sizeof(cantidadCartas)
    );

    jugador.mano.clear();

    for (uint32_t i = 0; i < cantidadCartas; i++) {

        Carta carta = cargarCarta(archivo);

        jugador.mano.push_back(carta);
    }

    return jugador;
}

// --------------------------------------------------
// CONDICION
// --------------------------------------------------

void Serializacion::guardarCondicion(
    ofstream& archivo,
    const Condicion& condicion
) {

    guardarString(archivo, condicion.color);

    int orden =
        static_cast<int>(condicion.orden);

    archivo.write(
        reinterpret_cast<const char*>(&orden),
        sizeof(orden)
    );
}

Condicion Serializacion::cargarCondicion(ifstream& archivo) {

    Condicion condicion;

    condicion.color = cargarString(archivo);

    int orden = 0;

    archivo.read(
        reinterpret_cast<char*>(&orden),
        sizeof(orden)
    );

    condicion.orden =
        static_cast<TipoOrden>(orden);

    return condicion;
}

// --------------------------------------------------
// RONDA
// --------------------------------------------------

void Serializacion::guardarRonda(
    ofstream& archivo,
    const Ronda& ronda
) {

    archivo.write(
        reinterpret_cast<const char*>(&ronda.numero),
        sizeof(ronda.numero)
    );

    guardarCondicion(
        archivo,
        ronda.condicion
    );

    uint32_t cantidadCartas =
        static_cast<uint32_t>(
            ronda.cartasJugadas.size()
        );

    archivo.write(
        reinterpret_cast<const char*>(&cantidadCartas),
        sizeof(cantidadCartas)
    );

    for (const Carta& carta : ronda.cartasJugadas) {

        guardarCarta(
            archivo,
            carta
        );
    }

    guardarCarta(
        archivo,
        ronda.cartaGanadora
    );

    char terminada =
        ronda.terminada ? 1 : 0;

    archivo.write(
        &terminada,
        sizeof(terminada)
    );
}

Ronda Serializacion::cargarRonda(ifstream& archivo) {

    Ronda ronda;

    archivo.read(
        reinterpret_cast<char*>(&ronda.numero),
        sizeof(ronda.numero)
    );

    ronda.condicion =
        cargarCondicion(archivo);

    uint32_t cantidadCartas = 0;

    archivo.read(
        reinterpret_cast<char*>(&cantidadCartas),
        sizeof(cantidadCartas)
    );

    ronda.cartasJugadas.clear();

    for (uint32_t i = 0; i < cantidadCartas; i++) {

        Carta carta =
            cargarCarta(archivo);

        ronda.cartasJugadas.push_back(carta);
    }

    ronda.cartaGanadora =
        cargarCarta(archivo);

    char terminada = 0;

    archivo.read(
        &terminada,
        sizeof(terminada)
    );

    ronda.terminada =
        (terminada != 0);

    return ronda;
}

// --------------------------------------------------
// GUARDAR JUEGO
// --------------------------------------------------

bool Serializacion::guardar(
    const Juego& juego,
    string nombreArchivo
) {

    ofstream archivo(
        nombreArchivo,
        ios::binary
    );

    if (!archivo.is_open()) {

        cout << "No se pudo abrir el archivo para guardar."
             << endl;

        return false;
    }

    // Firma del archivo
    const char firma[4] = {'C', 'A', 'R', 'T'};

    archivo.write(
        firma,
        sizeof(firma)
    );

    // Version
    int version = 1;

    archivo.write(
        reinterpret_cast<const char*>(&version),
        sizeof(version)
    );

    // Datos generales del juego

    archivo.write(
        reinterpret_cast<const char*>(&juego.rondaActual),
        sizeof(juego.rondaActual)
    );

    archivo.write(
        reinterpret_cast<const char*>(&juego.cantidadJugadores),
        sizeof(juego.cantidadJugadores)
    );

    archivo.write(
        reinterpret_cast<const char*>(&juego.cartasPorJugador),
        sizeof(juego.cartasPorJugador)
    );

    char iniciado =
        juego.iniciado ? 1 : 0;

    archivo.write(
        &iniciado,
        sizeof(iniciado)
    );

    // --------------------------------------------------
    // BARAJA
    // --------------------------------------------------

    uint32_t cantidadCartasBaraja =
        static_cast<uint32_t>(
            juego.baraja.cartas.size()
        );

    archivo.write(
        reinterpret_cast<const char*>(&cantidadCartasBaraja),
        sizeof(cantidadCartasBaraja)
    );

    for (const Carta& carta : juego.baraja.cartas) {

        guardarCarta(
            archivo,
            carta
        );
    }

    // --------------------------------------------------
    // JUGADORES
    // --------------------------------------------------

    uint32_t cantidadJugadores =
        static_cast<uint32_t>(
            juego.jugadores.size()
        );

    archivo.write(
        reinterpret_cast<const char*>(&cantidadJugadores),
        sizeof(cantidadJugadores)
    );

    for (const Jugador& jugador : juego.jugadores) {

        guardarJugador(
            archivo,
            jugador
        );
    }

    // --------------------------------------------------
    // RONDAS
    // --------------------------------------------------

    uint32_t cantidadRondas =
        static_cast<uint32_t>(
            juego.rondas.size()
        );

    archivo.write(
        reinterpret_cast<const char*>(&cantidadRondas),
        sizeof(cantidadRondas)
    );

    for (const Ronda& ronda : juego.rondas) {

        guardarRonda(
            archivo,
            ronda
        );
    }

    archivo.close();

    if (!archivo) {

        cout << "Ocurrio un error al guardar la partida."
             << endl;

        return false;
    }

    cout << "Partida guardada correctamente en: "
         << nombreArchivo
         << endl;

    return true;
}

// --------------------------------------------------
// CARGAR JUEGO
// --------------------------------------------------

bool Serializacion::cargar(
    Juego& juego,
    string nombreArchivo
) {

    ifstream archivo(
        nombreArchivo,
        ios::binary
    );

    if (!archivo.is_open()) {

        cout << "No se pudo abrir el archivo de partida."
             << endl;

        return false;
    }

    // --------------------------------------------------
    // VALIDAR FIRMA
    // --------------------------------------------------

    char firma[4];

    archivo.read(
        firma,
        sizeof(firma)
    );

    if (!archivo ||
        firma[0] != 'C' ||
        firma[1] != 'A' ||
        firma[2] != 'R' ||
        firma[3] != 'T') {

        cout << "El archivo no es una partida valida."
             << endl;

        return false;
    }

    // --------------------------------------------------
    // VERSION
    // --------------------------------------------------

    int version = 0;

    archivo.read(
        reinterpret_cast<char*>(&version),
        sizeof(version)
    );

    if (!archivo || version != 1) {

        cout << "Version de partida no compatible."
             << endl;

        return false;
    }

    // --------------------------------------------------
    // DATOS GENERALES
    // --------------------------------------------------

    archivo.read(
        reinterpret_cast<char*>(&juego.rondaActual),
        sizeof(juego.rondaActual)
    );

    archivo.read(
        reinterpret_cast<char*>(&juego.cantidadJugadores),
        sizeof(juego.cantidadJugadores)
    );

    archivo.read(
        reinterpret_cast<char*>(&juego.cartasPorJugador),
        sizeof(juego.cartasPorJugador)
    );

    char iniciado = 0;

    archivo.read(
        &iniciado,
        sizeof(iniciado)
    );

    juego.iniciado =
        (iniciado != 0);

    // --------------------------------------------------
    // BARAJA
    // --------------------------------------------------

    uint32_t cantidadCartasBaraja = 0;

    archivo.read(
        reinterpret_cast<char*>(&cantidadCartasBaraja),
        sizeof(cantidadCartasBaraja)
    );

    juego.baraja.cartas.clear();

    for (uint32_t i = 0;
         i < cantidadCartasBaraja;
         i++) {

        Carta carta =
            cargarCarta(archivo);

        juego.baraja.cartas.push_back(carta);
    }

    // --------------------------------------------------
    // JUGADORES
    // --------------------------------------------------

    uint32_t cantidadJugadores = 0;

    archivo.read(
        reinterpret_cast<char*>(&cantidadJugadores),
        sizeof(cantidadJugadores)
    );

    juego.jugadores.clear();

    for (uint32_t i = 0;
         i < cantidadJugadores;
         i++) {

        Jugador jugador =
            cargarJugador(archivo);

        juego.jugadores.push_back(jugador);
    }

    // --------------------------------------------------
    // RONDAS
    // --------------------------------------------------

    uint32_t cantidadRondas = 0;

    archivo.read(
        reinterpret_cast<char*>(&cantidadRondas),
        sizeof(cantidadRondas)
    );

    juego.rondas.clear();

    for (uint32_t i = 0;
         i < cantidadRondas;
         i++) {

        Ronda ronda =
            cargarRonda(archivo);

        juego.rondas.push_back(ronda);
    }

    archivo.close();

    if (!archivo.eof() && archivo.fail()) {

        cout << "Ocurrio un error al cargar la partida."
             << endl;

        return false;
    }

    cout << "Partida cargada correctamente desde: "
         << nombreArchivo
         << endl;

    return true;
}