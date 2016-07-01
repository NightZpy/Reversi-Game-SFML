#ifndef GLOBALS_HPP_INCLUDED
#define GLOBALS_HPP_INCLUDED

#include <SFML\Graphics.hpp>
#include "Arbol.hpp"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;


/*Arbol<EstadoTablero> *arbolJuego;
EstadoTablero estadoInicial;
Arbol<EstadoTablero> *nodoEstadoActual = 0;*/

const short int D_BAJ_IZQ  =  1;
const short int D_SUB_IZQ  =  2;
const short int D_BAJ_DER  =  3;
const short int D_SUB_DER  =  4;
const short int V_BAJ      =  5;
const short int V_SUB      =  6;
const short int H_DER      =  7;
const short int H_IZQ      =  8;
const char VACIO      =  '/';

/*bool jugando = false;
bool pistas  = false;
bool turno   = true;
bool fin     = false;
*/

class DataTab
{
    public:
        DataTab() { siguienteDato = NULL; cantidad = 0; matTab = NULL;}

        int cantidad;
        char** matTab;
        Arbol<DataTab> *siguienteDato;

        bool operator== (DataTab &data)
        {
            return ((DataTab::cantidad == data.cantidad) && (DataTab::matTab == data.matTab));
        }

};


#endif // GLOBALS_HPP_INCLUDED
