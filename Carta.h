#ifndef CARTA_H
#define CARTA_H

#include <string>

using namespace std;

class Carta {
private:
    string color;
    int numero;

public:
    Carta();
    Carta(string color, int numero);

    string getColor();
    int getNumero();

    void setColor(string color);
    void setNumero(int numero);

    void mostrar();
};

#endif