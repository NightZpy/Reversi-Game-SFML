/*#ifndef VENTANA_H
#define VENTANA_H


#include "Globals.hpp"
#include "Tablero.hpp"

class Ventana
{
    public:
        Ventana(float ancho, float alto, int pBits, std::string titulo, sf::Color colorFondo, bool dimensionable);
        virtual ~Ventana();
        void redimensionar(bool dimensionable)                  { Ventana::dimensionable = dimensionable;   }
        void visualizarVentana()                                { Ventana::ventana.Display();               }
        void pintarVentana(sf::Color color = sf::Color::Black)  { Ventana::ventana.Clear(color);            }
        /*void encajarTablero(Tablero tablero);

    //protected:

    //private:

        sf::RenderWindow ventana;
        sf::Color colorFondo;
        int ancho;
        int alto;
        bool dimensionable;
};

#endif // VENTANA_H*/
