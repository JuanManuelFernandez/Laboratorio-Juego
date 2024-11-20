#include "ArchivoPuntaje.h"

ArchivoPuntos::ArchivoPuntos(const char *n){
    strcpy(Nombre, n);
}

Puntaje ArchivoPuntos::leerRegistro(int pos){
    Puntaje objPuntaje;
    FILE *p = fopen(Nombre,"rb");
    if(p==NULL){
        cout << "NO SE CREO EL ARCHIVO" << endl;
        return objPuntaje;
    }
    fseek(p, pos * sizeof (Puntaje), 0);
    fread(&objPuntaje, sizeof (Puntaje), 1, p);
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

bool ArchivoPuntos::GrabarRegistro(Puntaje objPuntaje){
    FILE *p = fopen(Nombre, "ab");
    if(p==NULL){
        cout << "NO SE ABRIO EL ARCHIVO EN GRABAR" << endl;
        return false;
    }
    int Escribir = fwrite(&objPuntaje, sizeof (Puntaje), 1, p);
    fclose(p);
    return Escribir;
}
