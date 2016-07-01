#ifndef TABLEROLOGICO_H
#define TABLEROLOGICO_H

#include "Globals.hpp"

class TableroLogico
{
    public:
        TableroLogico(int cCuadros = 0);

        //virtual ~TableroLogico();

        unsigned short int getCCuadros()    { return TableroLogico::cCuadros; }
        void init();
        void mostrar();

        void    setMatrix(char** matrix) { this->matrix=matrix;     }
        char**  getMatrix()              { return this->matrix;     }

    private:
        unsigned short int cCuadros;
        char **matrix;
};

#endif // TABLEROLOGICO_H
