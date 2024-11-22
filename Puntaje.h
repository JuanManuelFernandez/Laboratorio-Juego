#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED

#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstring>

using namespace std;

class Puntaje{
    private:
        char Nombre[30];
        int Puntos;
    public:
        Puntaje();
        void setNombre(const char* n);
        void setPuntaje(int& p);
        int getPuntaje();
        const char* getNombre();
        void Mostrar();
};


#endif // PUNTAJE_H_INCLUDED
