#include "TableroLogico.hpp"

TableroLogico::TableroLogico(int cCuadros)
{
    TableroLogico::cCuadros       = cCuadros;
    TableroLogico::matrix         = new char*[cCuadros];

    for(int i=0; i<cCuadros; i++)
        TableroLogico::matrix[i] = new char[cCuadros];
}

void TableroLogico::init()
{
    for(unsigned short int i=0; i<TableroLogico::cCuadros; i++)
    {
        for(unsigned short int j=0; j<TableroLogico::cCuadros; j++)
        {
            if((i==3 && j==3) || (i==4 && j==4))
            {
                TableroLogico::matrix[i][j] = 'O';
            }
            else
                if((i==3 && j==4) || (i==4 && j==3))
                {
                    TableroLogico::matrix[i][j] = 'X';
                }
                else
                {
                    TableroLogico::matrix[i][j] = '/';
                }
        }
    }
}

void TableroLogico::mostrar()
{
    cout<<"    |  ";
    for(unsigned short int i=0; i<TableroLogico::cCuadros; i++)
    {
        cout<<i<<"  |  ";
    }
    cout<<endl<<"    -------------------------------------------------"<<endl;
    cout<<"    ................................................."<<endl;
    cout<<"-----------------------------------------------------"<<endl;

    for(unsigned short int i=0; i<TableroLogico::cCuadros; i++)
    {
        cout<<" "<<i<<"  |  ";
        for(unsigned short int j=0; j<TableroLogico::cCuadros; j++)
        {
            cout<<TableroLogico::matrix[i][j]<<"  |  ";
        }
        cout<<endl<<"-----------------------------------------------------"<<endl;
    }
}
