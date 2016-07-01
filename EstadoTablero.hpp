#ifndef ESTADOTABLERO_H
#define ESTADOTABLERO_H
#include "Globals.hpp"
#include "Posicion.hpp"
#include "ListaEnlazada.hpp"
#include "Arbol.hpp"
#include "TableroLogico.hpp"

typedef char** Tab;
//typedef Arbol<DataTab> Arbol<DataTab>;

class EstadoTablero
{
    public:

        //Métodos / Methods
        EstadoTablero(char **matTablero = NULL, unsigned short int size = 8, char miFicha = NULL, char fichaContraria = NULL);
        virtual ~EstadoTablero();

        unsigned short int contarFichas();

        void calcularMovimientosValidos(int fila, int columna);
        void cambiarFichas();
        void buscarPosicionesPosibles();
        bool procesarJugada(int fila, int columna);
        void EstadoTablero::cambiarFichasIA(Posicion pos);
        Arbol<DataTab> EstadoTablero::procesarJugadaPC(DataTab datoA, EstadoTablero *estadoActual, TableroLogico tab);
        int heuristica(DataTab dat, bool max);
        void calcularMinMaxValue(Arbol<DataTab>* arb, bool max);



        bool isJugadaValida()                     { return (EstadoTablero::jugadaValida = EstadoTablero::cJ > 0);   }
        char** getMatTablero()                    { return  EstadoTablero::matTablero;                              }
        unsigned short int getFichasCapturadas()  { return  EstadoTablero::cFichasCapturadas;                       }
        void setMatTablero(char** matTablero)     { EstadoTablero::matTablero = matTablero; }

        bool operator== (EstadoTablero& estadoTablero);
        bool lleno();
        char miFicha;
        char fichaContraria;

    //protected:
    //private:
        int limite, ic;
        bool jugadaValida;
        ListaEnlazada<Posicion> listaPosValidas;
        ListaEnlazada<Posicion> listaPosPosibles;
        ListaEnlazada<Posicion> listaPosFichasContrarias;
        unsigned short int cJ;
        short int valorMinMax;
        //Arbol<EstadoTablero> *siguienteEstado;
        char **matTablero;
        unsigned short int size;
        unsigned short int cMisFichas;
        unsigned short int cFichasContrarias;
        unsigned short int cFichas;
        unsigned short int cFichasCapturadas;
        unsigned short int fila;
        unsigned short int columna;
        //bool hDer, hIzq, vSub, vBaj, dSubIzq, dSubDer, dBajIzq, dBajDer;

        //Métodos / Methods
        Posicion obtenerJugadaValida    (int fila, int columna, const short int DIRECCION);
        Posicion contarFichasDeagonal   (int fila, int columna, const short int DIRECCION);
        Posicion contarFichasHorizontal (int fila, int columna, const short int DIRECCION);
        Posicion contarFichasVertical   (int fila, int columna, const short int DIRECCION);
        void buscarPosFichasContraria();

        //unsigned short int fichasContrarias();
        //unsigned short int fichasPropias();
};


#endif // ESTADOTABLERO_H
