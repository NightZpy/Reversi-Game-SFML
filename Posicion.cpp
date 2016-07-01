#include "Posicion.hpp"

Posicion::Posicion()
{
    Posicion::filaIni    = 0;
    Posicion::filaFin    = 0;
    Posicion::columnaIni = 0;
    Posicion::columnaFin = 0;
    Posicion::cantidad   = 0;
    Posicion::direccion  = 0;
    Posicion::valida     = false;
}

void Posicion::operator=(Posicion pos)
{
    Posicion::filaIni    = pos.filaIni;
    Posicion::filaFin    = pos.filaFin;
    Posicion::columnaIni = pos.columnaIni;
    Posicion::columnaFin = pos.columnaFin;
    Posicion::cantidad   = pos.cantidad;
    Posicion::direccion  = pos.direccion;
    Posicion::valida     = pos.valida;
}

bool Posicion::operator==(Posicion &pos)
{
    /*cout<<endl<<"EN OPERADOR==...";
    cout<<endl<<"Posicion this inicio: ("<<Posicion::filaIni<<", "<<Posicion::columnaIni<<")";
    cout<<endl<<"Posicion this  final: ("<<Posicion::filaFin<<", "<<Posicion::columnaFin<<")";
    cout<<endl<<"Posicion pos inicio: ("<<pos.filaIni<<", "<<pos.columnaIni<<")";
    cout<<endl<<"Posicion pos  final: ("<<pos.filaFin<<", "<<pos.columnaFin<<")";
    cout<<endl;*/
    return
    (
        (Posicion::filaIni    == pos.filaIni)      &&
        /*(Posicion::filaFin    == pos.filaFin)      &&*/
        (Posicion::columnaIni == pos.columnaIni)
        /*(Posicion::columnaFin == pos.columnaFin)   &&
        (Posicion::cantidad   == pos.cantidad)     &&
        (Posicion::direccion  == pos.direccion)    &&
        (Posicion::valida     == pos.valida)*/
    );
}

/*bool Posicion::iguales(Posicion &pos1, Posicion &pos2)
{
    /*cout<<endl<<"EN OPERADOR==...";
    cout<<endl<<"Posicion this inicio: ("<<Posicion::filaIni<<", "<<Posicion::columnaIni<<")";
    cout<<endl<<"Posicion this  final: ("<<Posicion::filaFin<<", "<<Posicion::columnaFin<<")";
    cout<<endl<<"Posicion pos inicio: ("<<pos.filaIni<<", "<<pos.columnaIni<<")";
    cout<<endl<<"Posicion pos  final: ("<<pos.filaFin<<", "<<pos.columnaFin<<")";
    cout<<endl;
    return
    (
        (pos1.filaIni    == pos2.filaIni)      &&
        (pos1.filaFin    == pos2.filaFin)      &&
        (pos1.columnaIni == pos2.columnaIni)   &&
        (pos1.columnaFin == pos2.columnaFin)
        /*(Posicion::cantidad   == pos.cantidad)     &&
        (Posicion::direccion  == pos.direccion)    &&
        (Posicion::valida     == pos.valida)
    );
}*/
