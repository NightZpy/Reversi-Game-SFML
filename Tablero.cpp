/*#include "Tablero.hpp"

Tablero::Tablero(unsigned short int cCuadros)//, sf::Color color, sf::Vector2f size, sf::Vector2f posIni)
{
    Tablero::cCuadros       = cCuadros;
    Tablero::matrix         = new char*[cCuadros];
    for(int i=0; i<cCuadros; i++)
        matrix[i] = new char[cCuadros];

    //Tablero::matrixBotones  = new Boton[cCuadros][cCuadros];
    //Tablero::color          = color;
    //Tablero::size           = size;
    //Tablero::posIni         = posIni;
    //Tablero::sizeBoton.x    = size.x / cCuadros;
    //Tablero::sizeBoton.y    = size.y / cCuadros;
}

void Tablero::init()
{
    float yPos = 0.f;
    for(unsigned short int i=0; i<Tablero::cCuadros; i++)
    {
        for(unsigned short int j=0; j<Tablero::cCuadros; j++)
        {
            if(j == 0)
            {
                Tablero::matrixBotones[i][j] = new Boton(Tablero::sizeBoton.x, Tablero::sizeBoton.y, Tablero::posIni.x, Tablero::posIni.y);
            }
            else
                {
                    Tablero::matrixBotones[i][j] = new Boton(Tablero::sizeBoton.x, Tablero::sizeBoton.y, Tablero::matrixBotones[i][j-1].getMaxPosX(), yPos);
                }

            if((i==4 && j==4) || (i==5 && j==5))
            {
                Tablero::matrix[i][j] = '0';
            }
            else
                if((i==4 && j==5) || (i==5 && j==4))
                {
                    Tablero::matrix[i][j] = '1';
                }
                else
                {
                    Tablero::matrix[i][j] = '2';
                }
        }
        //yPos = Tablero::matrixBotones[i][0].getMaxPosY();
    }
}

void Tablero::mostrar()
{
    for(unsigned short int i=0; i<Tablero::cCuadros; i++)
    {
        for(unsigned short int j=0; j<Tablero::cCuadros; j++)
        {
            cout<<"| "<<Tablero::matrix[i][i]<<" | ";
        }
        cout<<"|"<<endl;
        cout<<"---------------------------------------------------------"<<endl;
    }
}*/
