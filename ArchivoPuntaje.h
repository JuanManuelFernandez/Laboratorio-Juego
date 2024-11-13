#ifndef ARCHIVOPUNTAJE_H_INCLUDED
#define ARCHIVOPUNTAJE_H_INCLUDED

#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Puntaje.h"

using namespace std;

class ArchivoPuntos{
    private:
        char Nombre[30];
    public:
        ArchivoPuntos(const char *n);
        Puntaje leerRegistro(int pos);
        int ContarRegistros();
        bool GrabarRegistro();
};


#endif // ARCHIVOPUNTAJE_H_INCLUDED
