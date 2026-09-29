#include "Juego.h"
#include <iostream>

using namespace std;

Juego::Juego() {
    rondaActual = 0;
    cantidadJugadores = 0;
    cartasPorJugador = 0;
    iniciado = false;
}

void Juego::configurar() {

    cout << endl;
    cout << "============================" << endl;
    cout << "     CONFIGURAR JUEGO" << endl;
    cout << "============================" << endl;

    cout << "Cantidad de jugadores: ";
    cin >> cantidadJugadores;

    if (cantidadJugadores < 2) {
        cout << "Debe haber al menos 2 jugadores." << endl;
        cantidadJugadores = 0;
        return;
    }

    if (cantidadJugadores > 4) {
        cout << "El maximo es 4 jugadores." << endl;
        cantidadJugadores = 0;
        return;
    }

    cout << "Cartas por jugador: ";
    cin >> cartasPorJugador;

    if (cartasPorJugador < 1) {
        cout << "Debe haber al menos 1 carta." << endl;
        cartasPorJugador = 0;
        return;
    }

    jugadores.clear();
    rondas.clear();

    for (int i = 0; i < cantidadJugadores; i++) {

        string nombre;

        cout << "Nombre del jugador "
             << i + 1
             << ": ";

        cin >> nombre;

        agregarJugador(i + 1, nombre);
    }

    iniciado = false;
    rondaActual = 0;

    cout << endl;
    cout << "Configuracion completada." << endl;
}

void Juego::agregarJugador(int id, string nombre) {

    Jugador jugador(id, nombre);

    jugadores.push_back(jugador);
}

void Juego::repartirCartas() {

    cout << "Repartiendo cartas..." << endl;

    baraja.crearBaraja();
    baraja.mezclar();

    for (int i = 0; i < jugadores.size(); i++) {

        for (int j = 0; j < cartasPorJugador; j++) {

            if (!baraja.estaVacia()) {

                Carta carta = baraja.sacarCarta();

                jugadores[i].recibirCarta(carta);
            }
        }
    }

    cout << "Cartas repartidas." << endl;
}

void Juego::iniciarJuego() {

    cout << endl;
    cout << "============================" << endl;
    cout << "       INICIAR JUEGO" << endl;
    cout << "============================" << endl;

    if (jugadores.empty()) {

        cout << "No hay jugadores configurados." << endl;
        cout << "Primero seleccione la opcion 1." << endl;

        return;
    }

    cout << "Jugadores encontrados: "
         << jugadores.size()
         << endl;

    /*
        Primero comprobamos que la opcion 2
        funcione correctamente.
    */

    rondaActual = 1;
    iniciado = true;

    cout << endl;
    cout << "EL JUEGO SE INICIO CORRECTAMENTE." << endl;
    cout << "Ronda actual: "
         << rondaActual
         << endl;

    cout << endl;
    cout << "Ahora vamos a repartir las cartas." << endl;

    repartirCartas();

    cout << endl;
    cout << "Juego listo para jugar." << endl;
}

void Juego::jugarRonda() {

    if (!iniciado) {
        cout << endl;
        cout << "El juego no ha iniciado." << endl;
        cout << "Primero seleccione la opcion 1 y luego la opcion 2." << endl;
        return;
    }

    cout << endl;
    cout << "============================" << endl;
    cout << "         JUGAR RONDA" << endl;
    cout << "============================" << endl;

    cout << "Ronda: " << rondaActual << endl;

    // Seleccionar color
    cout << endl;
    cout << "Seleccione el color de la condicion:" << endl;
    cout << "1. Rojo" << endl;
    cout << "2. Azul" << endl;
    cout << "3. Verde" << endl;
    cout << "4. Amarillo" << endl;

    int opcionColor;
    cin >> opcionColor;

    string color;

    switch (opcionColor) {

        case 1:
            color = "Rojo";
            break;

        case 2:
            color = "Azul";
            break;

        case 3:
            color = "Verde";
            break;

        case 4:
            color = "Amarillo";
            break;

        default:
            cout << "Color invalido." << endl;
            return;
    }

    // Seleccionar tipo de orden
    cout << endl;
    cout << "Seleccione la condicion:" << endl;
    cout << "1. Mayor" << endl;
    cout << "2. Menor" << endl;

    int opcionOrden;
    cin >> opcionOrden;

    TipoOrden orden;

    if (opcionOrden == 1) {
        orden = TipoOrden::MAYOR;
    }
    else if (opcionOrden == 2) {
        orden = TipoOrden::MENOR;
    }
    else {
        cout << "Condicion invalida." << endl;
        return;
    }

    // Crear la condicion
    Condicion condicion(color, orden);

    // Crear la ronda
    Ronda ronda(rondaActual, condicion);

    vector<Carta> cartasJugadas;

    // Turno de cada jugador
    for (int i = 0; i < jugadores.size(); i++) {

        cout << endl;
        cout << "----------------------------" << endl;
        cout << "Turno de: "
             << jugadores[i].getNombre()
             << endl;

        jugadores[i].mostrarMano();

        int posicion;

        cout << "Seleccione la posicion de la carta: ";
        cin >> posicion;

        Carta carta = jugadores[i].jugarCarta(posicion);

        // Verificar carta valida
        if (carta.getColor() == "") {
            cout << "Posicion invalida." << endl;
            cout << "Se usara una carta vacia." << endl;
        }

        cout << "Carta jugada: ";
        carta.mostrar();

        ronda.registrarCarta(carta);

        cartasJugadas.push_back(carta);
    }

    // Determinar ganador
    Carta ganadora = ronda.determinarGanadora();

    cout << endl;
    cout << "============================" << endl;
    cout << "       RESULTADO RONDA" << endl;
    cout << "============================" << endl;

    cout << "Condicion: ";

    if (orden == TipoOrden::MAYOR) {
        cout << color << " - MAYOR" << endl;
    }
    else {
        cout << color << " - MENOR" << endl;
    }

    // Comprobar si hubo ganador
    if (ganadora.getColor() == "") {

        cout << endl;
        cout << "Ninguna carta cumplio la condicion." << endl;

    }
    else {

        cout << endl;
        cout << "Carta ganadora: ";
        ganadora.mostrar();

        // Buscar jugador ganador
        for (int i = 0; i < jugadores.size(); i++) {

            if (cartasJugadas[i].getColor() == ganadora.getColor() &&
                cartasJugadas[i].getNumero() == ganadora.getNumero()) {

                jugadores[i].sumarPunto();

                cout << "Ganador: "
                     << jugadores[i].getNombre()
                     << endl;

                break;
            }
        }
    }

    // Guardar la ronda
    rondas.push_back(ronda);

    // Pasar a la siguiente ronda
    rondaActual++;

    cout << endl;
    cout << "Ronda finalizada." << endl;
}

void Juego::mostrarEstado() {

    cout << endl;
    cout << "============================" << endl;
    cout << "       ESTADO DEL JUEGO" << endl;
    cout << "============================" << endl;

    cout << "Jugadores: "
         << jugadores.size()
         << endl;

    cout << "Ronda actual: "
         << rondaActual
         << endl;

    cout << "Juego iniciado: ";

    if (iniciado) {
        cout << "SI";
    }
    else {
        cout << "NO";
    }

    cout << endl;

    cout << "Cartas en la baraja: "
         << baraja.cantidadCartas()
         << endl;

    cout << endl;

    for (int i = 0; i < jugadores.size(); i++) {

        jugadores[i].mostrarInformacion();

        cout << endl;
    }
}

bool Juego::estaIniciado() {

    return iniciado;
}

int Juego::getRondaActual() {

    return rondaActual;
}

int Juego::getCantidadJugadores() {

    return cantidadJugadores;
}

void Juego::mostrarMenu() {

    int opcion;

    do {

        cout << endl;
        cout << "============================" << endl;
        cout << "       JUEGO DE CARTAS" << endl;
        cout << "============================" << endl;

        cout << "1. Configurar juego" << endl;
        cout << "2. Iniciar juego" << endl;
        cout << "3. Jugar ronda" << endl;
        cout << "4. Mostrar estado" << endl;
        cout << "5. Salir" << endl;

        cout << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        cout << endl;

        if (cin.fail()) {

            cin.clear();

            cin.ignore(1000, '\n');

            cout << "Debe escribir un numero." << endl;

            continue;
        }

        switch (opcion) {

            case 1:

                configurar();

                break;

            case 2:

                iniciarJuego();

                break;

            case 3:

                jugarRonda();

                break;

            case 4:

                mostrarEstado();

                break;

            case 5:

                cout << "Saliendo del juego..." << endl;

                break;

            default:

                cout << "Opcion invalida." << endl;

                break;
        }

    } while (opcion != 5);
}