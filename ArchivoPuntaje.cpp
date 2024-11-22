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
    fseek(p, pos * sizeof (Puntaje), 0); /// puntero del archivo para moverse, el tamaño en bytes a moverse, desde donde empieza el desplazamiento
    fread(&objPuntaje, sizeof (Puntaje), 1, p); /// donde se va a almacenar el dato leido, el tamaño del tipo de dato, 1 solo elemento, puntero del archivo a leer
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
    int Escribir = fwrite(&objPuntaje, sizeof (Puntaje), 1, p); /// direccion de la variable que vamos a grabar, el tamaño de la cantidad de bytes a grabar (sizeof), solo 1 variable, nombre logico del archivo a escribir -> p
    fclose(p);
    return Escribir;
}
