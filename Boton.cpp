/*#include "Boton.hpp"

//Constructor
Boton::Boton(float ancho, float alto, float xPos, float yPos, sf::Image *imagenes)
{
    Boton::cImagenes = 2;
    for(int i=0; i<cImagenes; i++)
        Boton::imagenes[i] = &imagenes[i];

    Boton::estado       =  0;
    Boton::activo       =  true;
    Boton::mouseDentro  =  false;
    Boton::ancho        =  Boton::size.x   = ancho;
    Boton::alto         =  Boton::size.y   = alto;
    Boton::xPos         =  Boton::pos.x    = xPos;
    Boton::yPos         =  Boton::pos.y    = yPos;
    Boton::xPosMax      =  Boton::posMax.x = ancho + xPos;
    Boton::yPosMax      =  Boton::posMax.y = alto  + yPos;

    Boton::figura.SetColor(sf::Color::White);
    Boton::figura.SetScale(ancho, alto);
    Boton::figura.SetPosition(xPos, yPos);
}

//Función para evaluar si el puntero del ratón está sobre el area ocupada por el boton
//Function for evaluate if the pointer of mouse is over the area of button
bool Boton::isMouseOverBoton(float mouseX, float mouseY)
{
    return (((mouseX >= xPos) && (mouseX <= xPosMax)) && ((mouseY >= yPos) && (mouseY <= yPosMax)));
}

//Función para evaluar si se ha clickeado sobre el boton
//Function for evaluate if has clicking over button
bool Boton::isMousePressedLeftBoton(sf::RenderWindow *ventana)
{
    return (Boton::estado = Boton::isMouseOverBoton(ventana->GetInput().GetMouseX(), ventana->GetInput().GetMouseX())  && ventana->GetInput().IsMouseButtonDown(sf::Mouse::Left));
}*/
