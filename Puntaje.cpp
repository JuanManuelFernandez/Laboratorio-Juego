#include "Puntaje.h"

Puntaje::Puntaje(){
    Puntos = 0;
}

void Puntaje::setNombre(const char* n){
    strcpy(Nombre, n);
}

void Puntaje::setPuntaje(int& p){
    Puntos = p;
}

int Puntaje::getPuntaje(){
    return Puntos;
}

const char* Puntaje::getNombre(){
    return Nombre;
}

void Puntaje::Mostrar(){
    cout << "Nombre: " <<  Nombre << endl;
    cout << "Puntaje: " <<  Puntos << endl;
}
