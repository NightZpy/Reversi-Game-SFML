#ifndef ARBOL_H
#define ARBOL_H

#include "ListaEnlazada.hpp"

template<class TIPO>
class IteradorArbol;

template<class TIPO>
class Arbol
{
    public:
        typedef Arbol<TIPO> Nodo;
        Arbol(TIPO info);
        Arbol() { padre = 0; }

        ~Arbol() { destroy(); }

        void destroy();
        int contar();
        void operator= (ListaEnlazada<Nodo*> listaNodo) { Arbol::hijos = listaNodo; }

        TIPO getInfo()                   { return Nodo::info;       }
        int  getNivel()                  { return Nodo::nivel;      }
        int  getCHijos()                 { return Nodo::cHijos;     }
        Nodo *getPadre()                 { return Nodo::padre;      }
        ListaEnlazada<Nodo*> getHijos()  { return Nodo::hijos;      }

        void setInfo(TIPO info)          { Arbol::info = info;      }

    private:

        int cHijos;
        int nivel;
        TIPO info;
        Nodo *padre;
        ListaEnlazada<Nodo*> hijos;

    friend class IteradorArbol<TIPO>;
};

template<class TIPO>
class IteradorArbol
{
    typedef Arbol<TIPO> Nodo;
    public:

        IteradorArbol(Nodo *pNodo = NULL) { *this = pNodo; }

        void reiniciarIterador();
        void irRaiz();
        void subir();
        void bajar();
        void agregarHijoInicio(Nodo *nodo) { IteradorArbol::pNodo->getHijos().agregarInicio(nodo);      }
        void agregarHijoFin(Nodo *nodo)    { IteradorArbol::pNodo->getHijos().agregarFin(nodo);         }
        void removerHijoInicio(Nodo *nodo) { IteradorArbol::pNodo->getHijos().removerInicio();          }
        void removerHijoFin(Nodo *nodo)    { IteradorArbol::pNodo->getHijos().removerFin();             }
        TIPO info()                        { IteradorArbol::pNodo->getInfo();                           }
        void siguienteHijo()               { IteradorArbol::itrApuntatHijosNodoActual.siguiente();      }
        void anteriorHijo()                { IteradorArbol::itrApuntatHijosNodoActual.anterior();       }
        void irHijoInicio()                { IteradorArbol::itrApuntatHijosNodoActual.irInicio();       }
        void irHijoFin()                   { IteradorArbol::itrApuntatHijosNodoActual.irFin();          }
        bool hijoValido()                  { return IteradorArbol::itrApuntatHijosNodoActual.valido();  }


        void preOrden(Nodo* pNodo, void(*funcion)(TIPO a));
        void postOrden(Nodo* pNodo, void(*funcion)(TIPO a));

        void operator= (Nodo *pNodo);

        Nodo *getNodo() { return IteradorArbol::pNodo; }

    //private:
        Nodo *pNodo;
        IteradorLista<Nodo*> itrApuntatHijosNodoActual;
        int cNivel;
};

template<class TIPO>
Arbol<TIPO>::Arbol(TIPO info)
{
    Arbol::info     = info;
    Arbol::padre    = 0;
    Arbol::nivel    = 0;
    Arbol::cHijos   = 0;
    //Arbol<TIPO>::hijos    = new ListaEnlazada<Nodo*>;
}

template<class TIPO>
void Arbol<TIPO>::destroy()
{
    IteradorLista<Nodo*> itr = Arbol::hijos.getIterador();
    Nodo* nodo = 0;
    itr.irInicio();
    while(itr.valido())
    {
        nodo = itr.info();
        Arbol::hijos.remover(itr);
        delete nodo;
    }
}

template<class TIPO>
int Arbol<TIPO>::contar()
{
    int cN = 0;
    IteradorLista<Nodo*> itr = Arbol::hijos.getIterador();
    for(itr.irInicio(); itr.valido(); itr.siguiente())
        cN += itr.getPLista()->getCNodos();
    return cN;
}

template<class TIPO>
void IteradorArbol<TIPO>::operator= (Nodo *pNodo)
{
    IteradorArbol::pNodo = pNodo;
    reiniciarIterador();
}

template<class TIPO>
void IteradorArbol<TIPO>::reiniciarIterador()
{
    if(!IteradorArbol::pNodo)
    {
         IteradorArbol::itrApuntatHijosNodoActual = IteradorArbol::pNodo->getHijos().getIterador();
    }
    else
    {
        IteradorArbol::itrApuntatHijosNodoActual.setPLista(NULL);
        IteradorArbol::itrApuntatHijosNodoActual.setPNodo(NULL);
    }
}

template<class TIPO>
void IteradorArbol<TIPO>::irRaiz()
{
    while(IteradorArbol::pNodo->getPadre())
    {
        IteradorArbol::subir();
        IteradorArbol::info();
    }
}

template<class TIPO>
void IteradorArbol<TIPO>::subir()
{
    if(!IteradorArbol::pNodo)
    {
        IteradorArbol::pNodo = IteradorArbol::pNodo->getPadre();
    }
    IteradorArbol::reiniciarIterador();
}

template<class TIPO>
void IteradorArbol<TIPO>::bajar()
{
    if(IteradorArbol::itrApuntatHijosNodoActual.valido())
    {
        IteradorArbol::pNodo = IteradorArbol::itrApuntatHijosNodoActual.info();
        IteradorArbol::reiniciarIterador();
    }
}

template<class TIPO>
void IteradorArbol<TIPO>::preOrden(Nodo* pNodo, void(*funcion)(TIPO a))
{
    funcion(pNodo->getInfo());
    IteradorLista<Nodo*> itr = pNodo->getHijos().getIterador();
    for(itr.irInicio(); itr.valido(); itr.siguiente())
        IteradorArbol::preOrden(itr.info(), funcion);
}

template<class TIPO>
void IteradorArbol<TIPO>::postOrden(Nodo* pNodo, void(*funcion)(TIPO a))
{
    IteradorLista<Nodo*> itr = pNodo->getHijos().getIterador();
    for(itr.irInicio(); itr.valido(); itr.siguiente())
        IteradorArbol::postOrden(itr.info(), funcion);
    funcion(pNodo->getInfo());
}
#endif // ARBOL_H

