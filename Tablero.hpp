/*#ifndef TABLERO_HPP_INCLUDED
#define TABLERO_HPP_INCLUDED

#include "Ventana.hpp"
#include "Boton.hpp"
#include "Globals.hpp"

class Tablero
{
    public:
        Tablero(unsigned short int cCuadros);//, sf::Color color = sf::Color::Black, sf::Vector2f size, sf::Vector2f posIni);
        void init();
        void mostrar();

        //Getters
        //Boton **getBoton(int i, int j)      { return Tablero::matrixBotones[i][j];  }
        unsigned short int getCCuadros()    { return Tablero::cCuadros;             }
        //sf::Color getColor()                { return Tablero::color;                }
        //sf::Vector2f getSize()              { return Tablero::size;                 }
        //sf::Vector2f getPosIni()            { return Tablero::posIni;               }
        //sf::Vector2f getSizeBoton()         { return Tablero::sizeBoton;            }

    private:
        unsigned short int cCuadros;
        char **matrix;
        //Boton **matrixBotones;
        //sf::Color color;
        //sf::Vector2f size;
        //sf::Vector2f posIni;
        //sf::Vector2f sizeBoton;

};

#endif // TABLERO_HPP_INCLUDED*/
