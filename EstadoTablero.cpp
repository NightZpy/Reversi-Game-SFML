#include "EstadoTablero.hpp"

EstadoTablero::EstadoTablero(char **matTablero, unsigned short int size, char miFicha, char fichaContraria)
{
    EstadoTablero::matTablero       = matTablero;
    EstadoTablero::miFicha          = miFicha;
    EstadoTablero::fichaContraria   = fichaContraria;
    EstadoTablero::limite = 5;
    EstadoTablero::ic=0;

    cout<<endl<<"Ficha propia: "<<EstadoTablero::miFicha;
    cout<<endl<<"Ficha contraria: "<<EstadoTablero::fichaContraria;

    //EstadoTablero::siguienteEstado  = 0;
    EstadoTablero::size             =  size;
    cout<<endl<<"Dimension del tablero: "<<EstadoTablero::size;
    EstadoTablero::cMisFichas       =  0;
    EstadoTablero::cFichasContrarias=  0;
    EstadoTablero::cFichas          =  0;
    EstadoTablero::valorMinMax      = -1;
    EstadoTablero::cJ               =  0;
    EstadoTablero::cFichasCapturadas=  0;
    EstadoTablero::jugadaValida     = false;
}

EstadoTablero::~EstadoTablero()
{
    //dtor
}

bool EstadoTablero::operator== (EstadoTablero& estadoTablero)
{
    for(unsigned short int i=0; i<EstadoTablero::size; i++)
    {
        for(unsigned short int j=0; j<EstadoTablero::size; j++)
        {
            if(EstadoTablero::matTablero[i][j] != estadoTablero.matTablero[i][j])
                return false;
        }
    }
    return true;
}

bool EstadoTablero::lleno()
{
    for(unsigned short int i=0; i<EstadoTablero::size; i++)
    {
        for(unsigned short int j=0; j<EstadoTablero::size; j++)
        {
            if(EstadoTablero::matTablero[i][j] == VACIO)
                return false;
        }
    }
    return true;
}

void EstadoTablero::cambiarFichas()
{
    if(EstadoTablero::jugadaValida)
    {
        IteradorLista<Posicion> itr = EstadoTablero::listaPosValidas.getIterador();
        for(itr.irInicio(); itr.valido(); itr.siguiente())
        {
            cout<<endl<<"DIRECCION: "<<itr.info().direccion;
            switch(itr.info().direccion)
            {
                {case D_BAJ_IZQ:
                    int i=itr.info().filaIni;
                    int j=itr.info().columnaIni;
                    while(i <= itr.info().filaFin && j >= itr.info().columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i++;
                        j--;
                    }
                break;
                }
                {case D_SUB_IZQ:
                    int i=itr.info().filaIni;
                    int j=itr.info().columnaIni;
                    while(i >= itr.info().filaFin && j >= itr.info().columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i--;
                        j--;
                    }
                break;
                }
                {case D_BAJ_DER:
                    int i=itr.info().filaIni;
                    int j=itr.info().columnaIni;
                    while(i <= itr.info().filaFin && j <= itr.info().columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i++;
                        j++;
                    }
                break;
                }
                {case D_SUB_DER:
                    int i=itr.info().filaIni;
                    int j=itr.info().columnaIni;
                    while(i >= itr.info().filaFin && j <= itr.info().columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i--;
                        j++;
                    }
                break;
                }
                {case V_BAJ:
                    int i=itr.info().filaIni;
                    int j=itr.info().columnaIni;
                    while(i <= itr.info().filaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i++;
                    }
                break;
                }
                {case V_SUB:
                    int i=itr.info().filaIni;
                    int j=itr.info().columnaIni;
                    while(i >= itr.info().filaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i--;
                    }
                break;
                }
                {case H_DER:
                    int i=itr.info().filaIni;
                    int j=itr.info().columnaIni;
                    while(j <= itr.info().columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        j++;
                    }
                break;
                }
                {case H_IZQ:
                    int i=itr.info().filaIni;
                    int j=itr.info().columnaIni;
                    while(j >= itr.info().columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        j--;
                    }
                break;
                }
                {default:
                    cout<<endl<<"DIRECCION INCORRECTA.";
                break;
                }
            }
        }
    }
}

void EstadoTablero::buscarPosicionesPosibles()
{
    //cout<<endl<<"Buscando pos posibles...";
    //EstadoTablero::contarFichas();
    EstadoTablero::buscarPosFichasContraria();
    //cout<<endl<<"Cantidad de Posiciones Fichas Contrarias: "<<listaPosFichasContrarias.getCNodos();
    IteradorLista<Posicion> itr = listaPosFichasContrarias.getIterador();
    //cout<<endl<<"Fichas contrarias: "<<EstadoTablero::cFichasContrarias;

    int fila=0, columna = 0;

    for(itr.irInicio(); itr.valido(); itr.siguiente())
    {
        fila    = itr.info().filaIni-1;
        columna = itr.info().columnaIni-1;
        if(EstadoTablero::matTablero[fila][columna]==VACIO)
        {
            Posicion pos;
            pos.filaIni     = fila;
            pos.columnaIni  = columna;
            EstadoTablero::listaPosPosibles.agregarFin(pos);
        }

        fila    = itr.info().filaIni+1;
        columna = itr.info().columnaIni+1;
        if(EstadoTablero::matTablero[fila][columna]==VACIO)
        {
            Posicion pos;
            pos.filaIni     = fila;
            pos.columnaIni  = columna;
            EstadoTablero::listaPosPosibles.agregarFin(pos);
        }

        fila    = itr.info().filaIni-1;
        columna = itr.info().columnaIni+1;
        if(EstadoTablero::matTablero[fila][columna]==VACIO)
        {
            Posicion pos;
            pos.filaIni     = fila;
            pos.columnaIni  = columna;
            EstadoTablero::listaPosPosibles.agregarFin(pos);
        }

        fila    = itr.info().filaIni+1;
        columna = itr.info().columnaIni-1;
        if(EstadoTablero::matTablero[fila][columna]==VACIO)
        {
            Posicion pos;
            pos.filaIni     = fila;
            pos.columnaIni  = columna;
            EstadoTablero::listaPosPosibles.agregarFin(pos);
        }

        fila    = itr.info().filaIni-1;
        columna = itr.info().columnaIni;
        if(EstadoTablero::matTablero[fila][columna]==VACIO)
        {
            Posicion pos;
            pos.filaIni     = fila;
            pos.columnaIni  = columna;
            EstadoTablero::listaPosPosibles.agregarFin(pos);
        }

        fila    = itr.info().filaIni+1;
        columna = itr.info().columnaIni;
        if(EstadoTablero::matTablero[fila][columna]==VACIO)
        {
            Posicion pos;
            pos.filaIni     = fila;
            pos.columnaIni  = columna;
            EstadoTablero::listaPosPosibles.agregarFin(pos);
        }

        fila    = itr.info().filaIni;
        columna = itr.info().columnaIni+1;
        if(EstadoTablero::matTablero[fila][columna]==VACIO)
        {
            Posicion pos;
            pos.filaIni     = fila;
            pos.columnaIni  = columna;
            EstadoTablero::listaPosPosibles.agregarFin(pos);
        }

        fila    = itr.info().filaIni;
        columna = itr.info().columnaIni-1;
        if(EstadoTablero::matTablero[fila][columna]==VACIO)
        {
            Posicion pos;
            pos.filaIni     = fila;
            pos.columnaIni  = columna;
            EstadoTablero::listaPosPosibles.agregarFin(pos);
        }

        //cout<<endl<<"Lista finalizando vuelva: "<<i<<"; en buscarPosicionesPosibles().";
    }
    //cout<<endl<<"Cantidad de nodos obtenidos: "<<listaPosPosibles.getCNodos();
}

void EstadoTablero::buscarPosFichasContraria()
{
    //cout<<endl<<"buscarPosFichasContraria.size: "<<EstadoTablero::size;
    //cout<<endl<<"Ficha contraria: "<<EstadoTablero::fichaContraria;
    for(int i=0; i<EstadoTablero::size; i++)
    {
        //cout<<endl<<"buscarPosFichasContraria.i: "<<i;
        for(int j=0; j<EstadoTablero::size; j++)
        {
            //cout<<endl<<"buscarPosFichasContraria.j: "<<j;
            if(EstadoTablero::matTablero[i][j]==EstadoTablero::fichaContraria)
            {
                Posicion pos;
                pos.filaIni    = i;
                pos.columnaIni = j;
                EstadoTablero::listaPosFichasContrarias.agregarFin(pos);
            }
        }
    }
    //return pos;
}

void EstadoTablero::calcularMovimientosValidos(int fila, int columna)
{
    cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";
    Posicion pos[8];
    //int cJV=0;
    for(int i=0; i<8; i++)
    {
        pos[i] = EstadoTablero::obtenerJugadaValida(fila, columna, i+1);
        if(pos[i].valida)
        {
            cout<<endl<<"Jugada valida!";
            EstadoTablero::listaPosValidas.agregarFin(pos[i]);
            EstadoTablero::cFichasCapturadas+=pos[i].cantidad;
            EstadoTablero::cJ++;
        }
    }

    /*cout<<endl<<"Total de jugadas validas: "<<EstadoTablero::cJ;
    EstadoTablero::pos = new Posicion[cJ];

    for(int i=0; i<8; i++)
    {
        if(pos[i].valida)
        {
            EstadoTablero::pos[cJV] = pos[i];
            cout<<endl<<"Cantidad: "<<pos[cJV].cantidad;
            EstadoTablero::cFichasCapturadas+=pos[cJV].cantidad;
            cJV++;
        }
    }*/

}

bool EstadoTablero::procesarJugada(int fila, int columna)
{
    Posicion pos;
    pos.filaIni     = fila;
    pos.columnaIni  = columna;

    //cout<<endl<<"Posicion Dato: ("<<pos.filaIni<<", "<<pos.columnaIni<<")";
    EstadoTablero::buscarPosicionesPosibles();
    //cout<<endl<<"Posiciones posibles para jugar: "<<listaPosPosibles.getCNodos();

    IteradorLista<Posicion> itr = listaPosPosibles.getIterador();

    for(itr.irInicio(); itr.valido(); itr.siguiente())
    {
        EstadoTablero::calcularMovimientosValidos(itr.info().filaIni, itr.info().columnaIni);
    }
    itr = listaPosValidas.getIterador();

    /*cout<<endl<<"Posiciones validas: "<<listaPosValidas.getCNodos();
    cout<<endl<<"BUSCANDO LA JUGADA...";*/
    if(listaPosValidas.getCNodos()>0)
        EstadoTablero::jugadaValida = listaPosValidas.buscar(itr, pos);
    else
    {
        cout<<endl<<"No hay jugadas posibles para ti...";
        return false;
    }


    /*if(EstadoTablero::jugadaValida)
        cout<<endl<<"Jugada valida, COÑO!";
    else
        cout<<endl<<"Jugada invalida!";*/

    //itr = NULL;
    //cout<<endl<<endl<<"POSICIONES DONDE PUEDES JUGAR: ";
    //int cN=listaPosValidas.getCNodos();
    //cout<<endl<<"Cantidad de jugadas posibles: "<<cN;
    /*int i=0;
    itr.irInicio();
    while(i<cN-1)
    {
        int fila = itr.info().filaIni;
        int columna = itr.info().columnaIni;
        //cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";
        itr.siguiente();
        i++;
    }*/

    EstadoTablero::listaPosValidas.~ListaEnlazada();
    return EstadoTablero::jugadaValida;
}

Arbol<DataTab> EstadoTablero::procesarJugadaPC(DataTab datoA, EstadoTablero *estadoActual, TableroLogico tab)//, Arbol<DataTab>* arbolTab)
{
    //cout<<endl<<"Entrando...";
    ListaEnlazada<DataTab> listaTabs;
    Arbol<DataTab> *arbol = new Arbol<DataTab>(datoA);
    Arbol<DataTab> *hijo;
    IteradorArbol<DataTab> itrArbol = arbol;
    //arbol->setInfo(datoA);
    DataTab dat;
    EstadoTablero::setMatTablero(datoA.matTab);
    cout<<endl<<"luego...";

    char max=estadoActual->miFicha;
    char min=estadoActual->fichaContraria;
    //cout<<endl<<"Seguido...";
    EstadoTablero::buscarPosicionesPosibles();
    cout<<endl<<"Posiciones posibles para jugar: "<<listaPosPosibles.getCNodos();

    IteradorLista<Posicion> itrPosPosibles = listaPosPosibles.getIterador();

    for(itrPosPosibles.irInicio(); itrPosPosibles.valido(); itrPosPosibles.siguiente())
    {
        EstadoTablero::calcularMovimientosValidos(itrPosPosibles.info().filaIni, itrPosPosibles.info().columnaIni);
    }
    //cout<<endl<<"Cantidad mov validos: "<<endl<<listaPosValidas.getCNodos();
    IteradorLista<Posicion> itrPosValidas = listaPosValidas.getIterador();
    EstadoTablero::jugadaValida=true;
    estadoActual->fichaContraria = max;
    estadoActual->miFicha = min;
    EstadoTablero::miFicha = max;
    EstadoTablero::fichaContraria = min;

    for(itrPosValidas.irInicio(); itrPosValidas.valido(); itrPosValidas.siguiente())
    {
        EstadoTablero::cambiarFichasIA(itrPosValidas.info());
        tab.setMatrix(EstadoTablero::getMatTablero());
        tab.mostrar();
        dat.matTab = EstadoTablero::getMatTablero();
        dat.cantidad = itrPosValidas.info().cantidad;
        listaTabs.agregarInicio(dat);
    }

    IteradorLista<DataTab> itrListaTabs = listaTabs.getIterador();
    while( EstadoTablero::ic<EstadoTablero::limite)
    {
    for(itrListaTabs.irInicio(); itrListaTabs.valido(); itrListaTabs.siguiente())
    {
        hijo = &EstadoTablero::procesarJugadaPC(itrListaTabs.info(), estadoActual, tab);
        itrArbol.agregarHijoFin(hijo);
        cout<<endl<<"CNodos: "<<arbol->getCHijos();
    }
         EstadoTablero::ic++;
    }

    return (*arbol);//(*(new Arbol<DataTab>));
}

void EstadoTablero::calcularMinMaxValue(Arbol<DataTab>* arb, bool max)
{
    if(arb->getHijos().getCNodos() == 0)
    {
        arb->getInfo().cantidad = EstadoTablero::heuristica(arb->getInfo(), max);
        return;
    }
    int minMax=0;
    IteradorArbol<DataTab> itrArbol = arb;
    itrArbol.irHijoInicio();
    minMax = itrArbol.info().cantidad;
    arb->getInfo().siguienteDato = itrArbol.itrApuntatHijosNodoActual.getPNodo()->getInfo();

    if(max)
    {
        while(itrArbol.hijoValido())
        {
            if(itrArbol.info().cantidad < minMax)
            {
                minMax = itrArbol.info().cantidad;
                arb->getInfo().siguienteDato = itrArbol.itrApuntatHijosNodoActual.getPNodo()->getInfo();
            }
            itrArbol.siguienteHijo();
        }
    }
    else
    {
        while(itrArbol.hijoValido())
        {
            if(itrArbol.info().cantidad > minMax)
            {
                minMax = itrArbol.info().cantidad;
                arb->getInfo().siguienteDato = itrArbol.itrApuntatHijosNodoActual.getPNodo()->getInfo();
            }
            itrArbol.siguienteHijo();
        }

    }
    arb->getInfo().cantidad = minMax;
}

int EstadoTablero::heuristica(DataTab dat, bool max)
{
    if(dat.siguienteDato==NULL && dat.cantidad==0)
        return max;
}

void EstadoTablero::cambiarFichasIA(Posicion pos)
{
    if(EstadoTablero::jugadaValida)
    {
        cout<<endl<<"DIRECCION: "<<pos.direccion;
        switch(pos.direccion)
        {
                {case D_BAJ_IZQ:
                    int i=pos.filaIni;
                    int j=pos.columnaIni;
                    while(i <= pos.filaFin && j >= pos.columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i++;
                        j--;
                    }
                break;
                }
                {case D_SUB_IZQ:
                    int i=pos.filaIni;
                    int j=pos.columnaIni;
                    while(i >= pos.filaFin && j >= pos.columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i--;
                        j--;
                    }
                break;
                }
                {case D_BAJ_DER:
                    int i=pos.filaIni;
                    int j=pos.columnaIni;
                    while(i <= pos.filaFin && j <= pos.columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i++;
                        j++;
                    }
                break;
                }
                {case D_SUB_DER:
                    int i=pos.filaIni;
                    int j=pos.columnaIni;
                    while(i >= pos.filaFin && j <= pos.columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i--;
                        j++;
                    }
                break;
                }
                {case V_BAJ:
                    int i=pos.filaIni;
                    int j=pos.columnaIni;
                    while(i <= pos.filaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i++;
                    }
                break;
                }
                {case V_SUB:
                    int i=pos.filaIni;
                    int j=pos.columnaIni;
                    while(i >= pos.filaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        i--;
                    }
                break;
                }
                {case H_DER:
                    int i=pos.filaIni;
                    int j=pos.columnaIni;
                    while(j <= pos.columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        j++;
                    }
                break;
                }
                {case H_IZQ:
                    int i=pos.filaIni;
                    int j=pos.columnaIni;
                    while(j >= pos.columnaFin)
                    {
                        EstadoTablero::matTablero[i][j] = EstadoTablero::miFicha;
                        j--;
                    }
                break;
                }
                {default:
                    cout<<endl<<"DIRECCION INCORRECTA.";
                break;
                }
            }
        }
}

unsigned short int EstadoTablero::contarFichas()
{
    for(unsigned short int i=0; i<EstadoTablero::size; i++)
    {
        for(unsigned short int j=0; j<EstadoTablero::size; j++)
        {
            if(EstadoTablero::matTablero[i][j] == EstadoTablero::miFicha)
                EstadoTablero::cMisFichas++;
            else
                if(EstadoTablero::matTablero[i][j] == EstadoTablero::fichaContraria)
                    EstadoTablero::cFichasContrarias++;

        }
    }
    EstadoTablero::cFichas = EstadoTablero::cMisFichas + EstadoTablero::cFichasContrarias;
    return EstadoTablero::cFichas;
}

Posicion EstadoTablero::obtenerJugadaValida(int fila, int columna, const short int DIRECCION)
{
    switch(DIRECCION)
    {
        case D_BAJ_IZQ:
            /*cout<<endl<<endl<<endl<<"-------------------------";
            cout<<endl<<"DIRECCION: "<<DIRECCION;
            cout<<endl<<"Comprobando si funciona D_BAJ_IZQ";
            cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";
            cout<<endl<<"-------------------------";*/
            return EstadoTablero::contarFichasDeagonal(fila, columna, D_BAJ_IZQ);
        break;

        case D_SUB_IZQ:
            /*cout<<endl<<"Comprobando si funciona D_SUB_IZQ";
            cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";*/
            return EstadoTablero::contarFichasDeagonal(fila, columna, D_SUB_IZQ);
        break;

        case D_BAJ_DER:
            /*cout<<endl<<endl<<endl<<"-------------------------";
            cout<<endl<<"DIRECCION: "<<DIRECCION;
            cout<<endl<<"Comprobando si funciona D_BAJ_DER";
            cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";
            cout<<endl<<"-------------------------";*/
            return EstadoTablero::contarFichasDeagonal(fila, columna, D_BAJ_DER);
        break;

        case D_SUB_DER:
            /*cout<<endl<<endl<<endl<<"-------------------------";
            cout<<endl<<"DIRECCION: "<<DIRECCION;
            cout<<endl<<"Comprobando si funciona D_SUB_DER";
            cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";
            cout<<endl<<"-------------------------";*/
            return EstadoTablero::contarFichasDeagonal(fila, columna, D_SUB_DER);
        break;

        case V_BAJ:
            /*cout<<endl<<endl<<endl<<"-------------------------";
            cout<<endl<<"DIRECCION: "<<DIRECCION;
            cout<<endl<<"Comprobando si funciona V_BAJ";
            cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";
            cout<<endl<<"-------------------------";*/
            return EstadoTablero::contarFichasVertical(fila, columna, V_BAJ);
        break;

        case V_SUB:
            /*cout<<endl<<"Comprobando si funciona V_SUB";
            cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";*/
            return EstadoTablero::contarFichasVertical(fila, columna, V_SUB);
        break;

        case H_DER:
            /*cout<<endl<<endl<<endl<<"-------------------------";
            cout<<endl<<"DIRECCION: "<<DIRECCION;
            cout<<endl<<"Comprobando si funciona H_DER";
            cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";
            cout<<endl<<"-------------------------";*/
            return  EstadoTablero::contarFichasHorizontal(fila, columna, H_DER);
        break;

        case H_IZQ:
            /*cout<<endl<<endl<<endl<<"-------------------------";
            cout<<endl<<"DIRECCION: "<<DIRECCION;
            cout<<endl<<"Comprobando si funciona H_IZQ";
            cout<<endl<<"Posicion: ( "<<fila<<","<<columna<<" )";
            cout<<endl<<"-------------------------";*/
            return  EstadoTablero::contarFichasHorizontal(fila, columna, H_IZQ);
        break;

        default:
            /*cout<<endl<<endl<<endl<<"-------------------------";
            cout<<endl<<"DIRECCION: "<<DIRECCION;
            cout<<endl<<"ERROR COMPROBANDO POSICION";
            cout<<endl<<"-------------------------";*/
            Posicion *p = new Posicion();
            return (*p);
        break;
    }
}

Posicion EstadoTablero::contarFichasDeagonal(int fila, int columna, const short int DIRECCION)
{
        unsigned short int i=fila, j=columna, c=0;
        Posicion pos;
        bool prim = true, seguir = true;

        if((DIRECCION == D_SUB_IZQ)  && ((j > 1) && (i > 1)))
        {
            //cout<<endl<<"Comprobando si hay cambios en D_SUB_IZQ";
            while(seguir)
            {
                char fichaActual = EstadoTablero::matTablero[i-1][j-1];
                //cout<<endl<<"Ficha actual en la posicion ( "<<i-1<<", "<<j-1<<" ): "<<fichaActual;
                if(prim)
                {
                    //cout<<endl<<"Comprobando Ficha seguida a la posicion escojida con orientacion D_SUB_IZQ.";
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        prim            = false;
                        pos.filaIni     = i;
                        pos.columnaIni  = j;
                        //cout<<endl<<"Ficha contraria en posicion: ( "<<pos.filaIni<<", "<<pos.columnaIni<<" )";
                        //c++;
                    }
                    else
                        if((fichaActual == EstadoTablero::miFicha) || (fichaActual == VACIO))
                        {
                            //cout<<endl<<"Movimiento en D_SUB_IZQ imposible!";
                            pos.valida  = false;
                            seguir      = false;
                            //break;
                        }
                }
                else
                {
                    //cout<<endl<<"Comprobando fichas en orientacion D_SUB_IZQ.";
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        c++;
                        i--;
                        j--;
                        //cout<<endl<<"Ficha contraria encontrada en posicion: ( "<<i<<", "<<j<<" )";
                    }
                    else
                        if(fichaActual == EstadoTablero::miFicha)
                        {
                            pos.valida      = true;
                            pos.filaFin     = i;
                            pos.columnaFin  = j;
                            pos.cantidad    = c;
                            pos.direccion = DIRECCION;
                            seguir = false;
                            //cout<<endl<<"Movimiento terminado en posicion: (( "<<pos.filaFin<<", "<<pos.columnaFin<<" )";
                        }
                        else
                        {
                            if(c==1)
                                pos.valida  = false;
                            seguir      = false;
                        }
                }
                //system("pause");
            }
            //cout<<endl<<"Cantidad: "<<pos.cantidad;
            return pos;
        }
        else
        {
            pos.valida = false;
        }

        if((DIRECCION == D_SUB_DER)  && ((j < 7) && (i > 1)))
        {
            while(seguir)
            {
                char fichaActual = EstadoTablero::matTablero[i-1][j+1];
                if(prim)
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        prim            = false;
                        pos.filaIni     = i;
                        pos.columnaIni  = j;
                        //c++;
                    }
                    else
                        if((fichaActual == EstadoTablero::miFicha) || (fichaActual == VACIO))
                        {
                            pos.valida  = false;
                            seguir      = false;
                        }
                }
                else
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        c++;
                        i--;
                        j++;
                    }
                    else
                        if(fichaActual == EstadoTablero::miFicha)
                        {
                            pos.valida      = true;
                            pos.filaFin     = i;
                            pos.columnaFin  = j;
                            pos.cantidad    = c;
                            //cout<<endl<<"C en D_SUB_DER: "<<c;
                            pos.direccion = DIRECCION;
                            seguir = false;
                        }
                        else
                        {
                            if(c==1)
                                pos.valida  = false;
                            seguir      = false;
                        }
                }
            }
            //cout<<endl<<"Cantidad D_SUB_DER: "<<pos.cantidad;
            return pos;
        }
        else
        {
            pos.valida = false;
        }

        if((DIRECCION == D_BAJ_IZQ)  && ((j > 1) && (i < 7)))
        {
            while(seguir)
            {
                char fichaActual = EstadoTablero::matTablero[i+1][j-1];
                if(prim)
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        prim            = false;
                        pos.filaIni     = i;
                        pos.columnaIni  = j;
                        //c++;
                    }
                    else
                        if((fichaActual == EstadoTablero::miFicha) || (fichaActual == VACIO))
                        {
                            pos.valida  = false;
                            seguir      = false;
                        }
                }
                else
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        c++;
                        i++;
                        j--;
                    }
                    else
                        if(fichaActual == EstadoTablero::miFicha)
                        {
                            pos.valida      = true;
                            pos.filaFin     = i;
                            pos.columnaFin  = j;
                            pos.cantidad    = c;
                            pos.direccion = DIRECCION;
                            seguir = false;
                        }
                        else
                        {
                            if(c==1)
                                pos.valida  = false;
                            seguir = false;
                        }
                }
            }
            //cout<<endl<<"Cantidad: "<<pos.cantidad;
            return pos;
        }
        else
        {
            pos.valida = false;
        }

        if((DIRECCION == D_BAJ_DER)  && ((j < 7) && (i < 7)))
        {
            while(seguir)
            {
                char fichaActual = EstadoTablero::matTablero[i+1][j+1];
                if(prim)
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        prim            = false;
                        pos.filaIni     = i;
                        pos.columnaIni  = j;
                        //c++;
                    }
                    else
                        if((fichaActual == EstadoTablero::miFicha) || (fichaActual == VACIO))
                        {
                            pos.valida  = false;
                            seguir      = false;
                        }
                }
                else
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        c++;
                        i++;
                        j++;
                    }
                    else
                        if(fichaActual == EstadoTablero::miFicha)
                        {
                            pos.valida      = true;
                            pos.filaFin     = i;
                            pos.columnaFin  = j;
                            pos.cantidad    = c;
                            pos.direccion = DIRECCION;
                            seguir = false;
                        }
                        else
                        {
                            if(c==1)
                                pos.valida  = false;
                            seguir      = false;
                        }
                }
            }
            //cout<<endl<<"Cantidad: "<<pos.cantidad;
            return pos;
        }
        else
        {
            pos.valida = false;
        }
        //cout<<endl<<"Cantidad: "<<pos.cantidad;
        return pos;
}

Posicion EstadoTablero::contarFichasHorizontal(int fila, int columna, const short int DIRECCION)
{
        unsigned short int i=fila, j=columna, c=0;
        Posicion pos;
        bool prim = true, seguir = true;

        if((DIRECCION == H_DER) && (j < 7))
        {
            //cout<<endl<<"En H_DER";
            while(seguir)
            {
                char fichaActual = EstadoTablero::matTablero[i][j+1];
                if(prim)
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        prim            = false;
                        pos.filaIni     = i;
                        pos.columnaIni  = j;
                        //c++;
                    }
                    else
                        if((fichaActual == EstadoTablero::miFicha) || (fichaActual == VACIO))
                        {
                            pos.valida  = false;
                            seguir      = false;
                        }
                }
                else
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        c++;
                        j++;
                    }
                    else
                        if(fichaActual == EstadoTablero::miFicha)
                        {
                            pos.valida      = true;
                            pos.filaFin     = i;
                            pos.columnaFin  = j;
                            pos.cantidad    = c;
                            //cout<<endl<<"C en H_DER: "<<c;
                            pos.direccion = DIRECCION;
                            seguir = false;
                        }
                        else
                        {
                            if(c==1)
                                pos.valida  = false;

                            seguir      = false;
                        }
                }
            }
            //cout<<endl<<"Cantidad H_DER: "<<pos.cantidad;
            return pos;
        }
        else
        {
            pos.valida = false;
        }

        if((DIRECCION == H_IZQ)  && (j > 1))
        {
            //cout<<endl<<"Comprobando si hay cambios en H_IZQ";
            while(seguir)
            {
                char fichaActual = EstadoTablero::matTablero[i][j-1];
                //cout<<endl<<"Ficha actual en la posicion ( "<<i<<", "<<j-1<<" ): "<<fichaActual;
                if(prim)
                {
                    //cout<<endl<<"Comprobando Ficha seguida a la posicion escojida con orientacion H_IZQ.";
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        prim            = false;
                        pos.filaIni     = i;
                        pos.columnaIni  = j;
                        //cout<<endl<<"Ficha contraria en posicion: ( "<<pos.filaIni<<", "<<pos.columnaIni<<" )";
                        //c++;
                    }
                    else
                        if((fichaActual == EstadoTablero::miFicha) || (fichaActual == VACIO))
                        {
                            pos.valida  = false;
                            seguir      = false;
                            //cout<<endl<<"Movimiento en H_IZQ imposible!";
                        }
                }
                else
                {
                    //cout<<endl<<"Comprobando fichas en orientacion H_IZQ.";
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        c++;
                        j--;
                        //cout<<endl<<"Ficha contraria encontrada en posicion: ( "<<i<<", "<<j<<" )";
                    }
                    else
                        if(fichaActual == EstadoTablero::miFicha)
                        {
                            pos.valida      = true;
                            pos.filaFin     = i;
                            pos.columnaFin  = j;
                            pos.cantidad    = c;
                            pos.direccion = DIRECCION;
                            seguir = false;
                            //cout<<endl<<"Fichas a cambiar: "<<pos.cantidad;
                            //cout<<endl<<"Movimiento terminado en posicion: (( "<<pos.filaFin<<", "<<pos.columnaFin<<" )";
                        }
                        else
                        {
                            if(c==1)
                                pos.valida  = false;
                            seguir      = false;
                        }
                }
            }
            //cout<<endl<<"Cantidad: "<<pos.cantidad;
            return pos;
        }
        else
        {
            pos.valida = false;
        }
        //cout<<endl<<"Cantidad: "<<pos.cantidad;
        return pos;
}

Posicion EstadoTablero::contarFichasVertical(int fila, int columna, const short int DIRECCION)
{
        unsigned short int i=fila, j=columna, c=0;
        Posicion pos;
        bool prim = true, seguir = true;

        //cout<<endl<<endl<<"COMPROBANDO VERTICALES!";

        if((DIRECCION == V_SUB)  && ((i > 1)))
        {
            //cout<<endl<<endl<<"Comprobando V_SUB!";
            while(seguir)
            {
                char fichaActual = EstadoTablero::matTablero[i-1][j];
                //cout<<endl<<"Ficha actual en la posicion ( "<<i-1<<", "<<j<<" ): "<<fichaActual;
                if(prim)
                {
                    //cout<<endl<<"Comprobando Ficha seguida a la posicion escojida con orientacion V_SUB.";
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        prim            = false;
                        pos.filaIni     = i;
                        pos.columnaIni  = j;
                        //c++;
                        //cout<<endl<<"Ficha contraria en posicion: ( "<<pos.filaIni<<", "<<pos.columnaIni<<" )";
                    }
                    else
                        if((fichaActual == EstadoTablero::miFicha) || (fichaActual == VACIO))
                        {
                            pos.valida  = false;
                            seguir      = false;
                            //cout<<endl<<"Movimiento en V_SUB imposible!";
                        }
                }
                else
                {
                    //cout<<endl<<"Comprobando fichas en orientacion H_IZQ.";
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        c++;
                        i--;
                        //cout<<endl<<"Ficha contraria encontrada en posicion: ( "<<i<<", "<<j<<" )";
                    }
                    else
                        if(fichaActual == EstadoTablero::miFicha)
                        {
                            pos.valida      = true;
                            pos.filaFin     = i;
                            pos.columnaFin  = j;
                            //cout<<endl<<"C en V_SUB: "<<c;
                            pos.cantidad    = c;
                            pos.direccion = DIRECCION;
                            seguir = false;
                            //cout<<endl<<"Movimiento terminado en posicion: (( "<<pos.filaFin<<", "<<pos.columnaFin<<" )";
                        }
                        else
                        {
                            if(c==1)
                                pos.valida  = false;

                            seguir      = false;
                            //cout<<endl<<"Movimiento en V_SUB imposible!";
                        }
                }
                //system("pause");
            }
            //cout<<endl<<"Cantidad V_SUB: "<<pos.cantidad;
            return pos;
        }
        else
        {
            pos.valida = false;
            //return pos;
        }

        if((DIRECCION == V_BAJ)  && ((i < 7)))
        {
            while(seguir)
            {
                char fichaActual = EstadoTablero::matTablero[i+1][j];
                if(prim)
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        prim            = false;
                        pos.filaIni     = i;
                        pos.columnaIni  = j;
                        //c++;
                    }
                    else
                        if((fichaActual == EstadoTablero::miFicha) || (fichaActual == VACIO))
                        {
                            pos.valida  = false;
                            seguir      = false;
                        }
                }
                else
                {
                    if(fichaActual == EstadoTablero::fichaContraria)
                    {
                        c++;
                        i++;
                    }
                    else
                        if(fichaActual == EstadoTablero::miFicha)
                        {
                            pos.valida      = true;
                            pos.filaFin     = i;
                            pos.columnaFin  = j;
                            pos.cantidad    = c;
                            //cout<<endl<<"C en V_BAJ: "<<c;
                            pos.direccion = DIRECCION;
                            seguir = false;
                        }
                        else
                        {
                            if(c==1)
                                pos.valida  = false;
                            seguir      = false;
                        }
                }
            }
            //cout<<endl<<"Cantidad V_BAJ: "<<pos.cantidad;
            return pos;
        }
        else
        {
            pos.valida = false;
            //return pos;
        }
        //cout<<endl<<"Vertical bajando Cantidad: "<<pos.cantidad;
        return pos;
}
