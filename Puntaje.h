#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;

class Puntaje{
    private:
        string Nombre;
        int Puntos;
    public:
        Puntaje();
        void setNombre(string* n);
        void setPuntaje(int* p);
        string getNombre();
        int getPuntaje();
        void Mostrar();
};


#endif // PUNTAJE_H_INCLUDED
