#include "ArchivoPuntaje.h"

ArchivoPuntos::ArchivoPuntos(const char *n){
    strcpy(Nombre, n);
}

Puntaje ArchivoPuntos::leerRegistro(int pos){
    Puntaje objPuntaje;
    FILE *p = fopen(Nombre,"rb");
    if(p==NULL){
        cout << "NO SE CREO EL ARCHIVO" << endl;
    }
    fseek(p, pos * sizeof (objPuntaje), 0);
    fread(&objPuntaje, sizeof (objPuntaje), 1, p);
    fclose(p);
    return objPuntaje;
}

int ArchivoPuntos::ContarRegistros(){
    int cant = 0;
    FILE *p = fopen(Nombre, "rb");
    if(p==NULL){
        cout << "NO SE ABRIO EL ARCHIVO EN CONTAR" << endl;
    }
    fseek(p, 0, 2);
    ///0 ES EL PRINCIPIO DEL ARCHIVO Y EL 2 INDICA HASTA EL FINAL
    cant = ftell(p)/sizeof(Puntaje);
    fclose(p);
    return cant;
}

bool ArchivoPuntos::GrabarRegistro(){
    Puntaje objPuntaje;
    int Escribir;
    FILE *p = fopen(Nombre, "wb");
    if(p==NULL){
        cout << "NO SE ABRIO EL ARCHIVO EN GRABAR" << endl;
    }
    Escribir = fwrite(&objPuntaje, sizeof (objPuntaje), 1, p);
    fclose(p);
    return Escribir;
}
