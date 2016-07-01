#ifndef POSICION_H
#define POSICION_H

#include <iostream>

using namespace std;

class Posicion
{
    public:
        Posicion();
        //virtual ~Posicion();

        //bool iguales(Posicion a, Posicion b) { return a==b; }
        void operator= (Posicion pos);
        bool operator==(Posicion &pos);

        int filaIni;
        int columnaIni;
        int filaFin;
        int columnaFin;
        int cantidad;
        int direccion;
        bool valida;
};

#endif // POSICION_H
