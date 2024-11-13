#include "Puntaje.h"

Puntaje::Puntaje(){
    Puntos = 0;
}

void Puntaje::setNombre(string* n){
    Nombre = *n;
}

void Puntaje::setPuntaje(int* p){
    Puntos = *p;
}

string Puntaje::getNombre(){
    return Nombre;
}

int Puntaje::getPuntaje(){
    return Puntos;
}

void Puntaje::Mostrar(){
    cout << "Nombre: " <<  Nombre << endl;
    cout << "Puntaje: " <<  Puntos << endl;
}
