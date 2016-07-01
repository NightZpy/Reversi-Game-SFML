#include "TableroLogico.hpp"
#include "EstadoTablero.hpp"

void jugarDos();
void muevePC();

Arbol<DataTab> *arbolJuego;
DataTab estadoInicial;
Arbol<DataTab> *arbolActual;
bool jugando = false;
bool pistas  = false;
bool turno   = true;
bool finJuego = true;

TableroLogico tab(8);
EstadoTablero *estadoTablero;

DataTab nuevoEstado;

char s='/';
char jugador[2];
char fichaActual='/';
char fichaNoActual='/';
bool seguir=false;
int fila=-1;
int columna=-1;

int main()
{
    cout<<endl<<"En main...";
    //nuevoEstado = arbolActual->getInfo();
    //IteradorArbol<DataTab> itrArbActual = arbolActual;
    int sz=0;
    do
    {
        cout<<"Jugar para dos(2), contra el pc(1): ";
        cin>>sz;
        if(sz!=2 && sz!=1)
            cout<<endl<<"Escoja una ficha valida";
    }while(sz!=2 && sz!=1);

    jugador[0]='O';
    jugador[1]='X';

    do
    {
        cout<<endl<<"Escoje una ficha para jugar (O o X): ";
        cin>>s;
        s=toupper(s);
        if(s!='O' && s!='X')
            cout<<endl<<"Escoja una ficha valida";

    }while(s!='O' && s!='X');

    tab.init();
    cout<<endl<<"Tablero de inicio: "<<endl;
    tab.mostrar();
    estadoInicial.matTab = tab.getMatrix();

    if(s!=jugador[0])
    {
        cout<<endl<<"Empieza jugador: "<<jugador[1];
        fichaActual=jugador[1];
        fichaNoActual=jugador[0];
    }
    else
    {
        cout<<endl<<"Empieza jugador: "<<jugador[0];
        fichaActual=jugador[0];
        fichaNoActual=jugador[1];
    }

    do
    {
        cout<<endl<<"Moviendo ficha: "<<fichaActual;
        if(sz==1)
            muevePC();
        else
            jugarDos();


    }while(seguir);

    return 0;
}

void mueveJugador()
{
        cout<<endl<<"Escoja posicion para jugar (fila, columna): ";
        scanf("%d,%d",&fila, &columna);
        estadoTablero = new EstadoTablero(tab.getMatrix(), tab.getCCuadros(), fichaActual, fichaNoActual);

        /*if(estadoTablero->procesarJugada(fila, columna))
        {
            estadoTablero->calcularMovimientosValidos(fila, columna);
            estadoTablero->cambiarFichas();
            cout<<endl<<"Fichas capturadas: "<<estadoTablero->getFichasCapturadas()<<endl;
            tab.setMatrix(estadoTablero->getMatTablero());
            char aux        =   fichaActual;
            fichaActual     =   fichaNoActual;
            fichaNoActual   =   aux;
            system("pause");
            system("cls");
            cout<<endl<<"Tablero con los cambios: "<<endl;
            tab.mostrar();
        }
        else
        {
            cout<<endl<<"Movimiento invalido, vuelve a probar.";
        }*/



        cout<<endl<<"Desea seguir (Si:1; No:0): ";
        cin>>seguir;
}

void muevePC()
{
        estadoTablero = new EstadoTablero(tab.getMatrix(), tab.getCCuadros(), fichaActual, fichaNoActual);
        arbolJuego = &estadoTablero->procesarJugadaPC(estadoInicial, estadoTablero, tab);
        estadoTablero->calcularMinMaxValue(arbolJuego, true);

}

void jugarDos()
{
        cout<<endl<<"Escoja posicion para jugar (fila, columna): ";
        scanf("%d,%d",&fila, &columna);
        estadoTablero = new EstadoTablero(tab.getMatrix(), tab.getCCuadros(), fichaActual, fichaNoActual);

        if(!estadoTablero->lleno() && estadoTablero->procesarJugada(fila, columna))
        {
            estadoTablero->calcularMovimientosValidos(fila, columna);
            estadoTablero->cambiarFichas();
            cout<<endl<<"Fichas capturadas: "<<estadoTablero->getFichasCapturadas()<<endl;
            tab.setMatrix(estadoTablero->getMatTablero());
            char aux        =   fichaActual;
            fichaActual     =   fichaNoActual;
            fichaNoActual   =   aux;
            system("pause");
            system("cls");
            cout<<endl<<"Tablero con los cambios: "<<endl;
            tab.mostrar();
        }
        else
        {
            if(estadoTablero->listaPosValidas.getCNodos()>0)
            {
                cout<<endl<<"Movimiento invalido, vuelve a probar.";
            }
            else
            {
                char aux        =   fichaActual;
                fichaActual     =   fichaNoActual;
                fichaNoActual   =   aux;
            }

            if(estadoTablero->lleno())
            {
                estadoTablero->contarFichas();
                if(estadoTablero->cFichasContrarias > estadoTablero->cMisFichas)
                    cout<<endl<<"Gano: "<<estadoTablero->fichaContraria;
                else
                    cout<<endl<<"Gano: "<<estadoTablero->miFicha;

                tab.init();
            }

        }

        cout<<endl<<"Desea seguir (Si:1; No:0): ";
        cin>>seguir;
}


