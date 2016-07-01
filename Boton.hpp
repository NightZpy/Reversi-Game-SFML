#ifndef BOTON_HPP_INCLUDED
#define BOTON_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//#include "Control.hpp"
#include <iostream>

using namespace std;

class Boton
{
    public:

        Boton(float ancho, float alto, float xPos, float yPos);//, sf::Image *imagenes = NULL);

        //Setters
        void setSize(float ancho, float alto);
        void setSize(sf::Vector2f size);
        void activar(bool b)          { activo = b;  }

        //getters
        float getSizeX()        { return ancho;   }
        float getSizeY()        { return alto;    }
        sf::Vector2f getSize()  { return size;    }
        float getPosX()         { return xPos;    }
        float getPosY()         { return yPos;    }
        sf::Vector2f getPos()   { return pos;     }
        float getMaxPosX()      { return xPosMax; }
        float getMaxPosY()      { return yPosMax; }
        sf::Vector2f getPosMax(){ return posMax;  }
        bool isActivo()         { return activo;  }
        sf::Sprite getFigura()  { return figura;  }

        //Otras funciones utiles / Others utils functions
        bool isMouseOverBoton(float mouseX, float mouseY);
        bool isMousePressedLeftBoton(sf::RenderWindow *ventana);

        //Función para cambiar la imagen del boton
        //Function for change the button image
        void cambiarImagen(int img)    { if(Boton::activo) Boton::figura.SetImage(*imagenes[img]);}

        //Función para cambiar el color del boton
        //Function for change the button color
        void cambiarColor(sf::Color c) { if(Boton::activo) figura.SetColor(c); }

    private:
        //Control *control;
        int cImagenes;
        int estado;
        bool activo;
        bool mouseDentro;
        sf::Sprite figura;
        sf::Image **imagenes;
        float ancho;
        float alto;
        sf::Vector2f size;
        float xPos;
        float yPos;
        float xPosMax;
        float yPosMax;
        sf::Vector2f pos;
        sf::Vector2f posMax;
};
#endif // BOTON_HPP_INCLUDED
