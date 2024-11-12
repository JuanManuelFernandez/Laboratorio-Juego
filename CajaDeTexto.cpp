#include "CajaDeTexto.h"

CajaDeTexto::CajaDeTexto(int tam, sf::Color color, bool Selec){
    Seleccionado = false;
    MaxCaracteres = false;

    fuente.loadFromFile("Pixeleada.ttf");

    Caja.setFont(fuente);
    Caja.setCharacterSize(tam);
    Caja.setColor(color);
    Seleccionado = Selec;

    if(Selec){
        Caja.setString("_");
    }
    else{
        Caja.setString("");
    }
}

void CajaDeTexto::Inputs(int tecla){
    if(tecla != DELETE_KEY && tecla != ENTER_KEY){
        texto << static_cast<char>(tecla);
    }
    else if(tecla == DELETE_KEY){
        if(texto.str().length() > 0){
            Borrar();
        }
    }

    Caja.setString(texto.str() + "_");
}

void CajaDeTexto::Borrar(){
    string T = texto.str();
    string Tnuevo = "";

    for(int i=0;i<T.length() - 1;i++){
        Tnuevo += T[i];
    }
    texto.str("");
    texto << Tnuevo;

    Caja.setString(texto.str());
}

void CajaDeTexto::Posicion(float x, float y){
    Caja.setPosition(x, y);
}

void CajaDeTexto::setLimite(bool ToF){
    MaxCaracteres = ToF;
}

void CajaDeTexto::setLimite(bool ToF, int limit){
    Limite = limit;
    MaxCaracteres = ToF;
}

void CajaDeTexto::setSelect(bool ToF){
    Seleccionado = ToF;
    if(!ToF){
        string T = texto.str();
        string Tnuevo = "";

        for(int i=0;i<T.length();i++){
            Tnuevo += T[i];
        }
        Caja.setString(Tnuevo);
    }
}

string CajaDeTexto::getTexto(){
    return texto.str();
}

void CajaDeTexto::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(Caja, states);
}

void CajaDeTexto::Escribiendo(sf::Event input){
    if(Seleccionado){
        int CharEscrito = input.text.unicode;
        if(CharEscrito<128){
            if(MaxCaracteres){
                if(texto.str().length()<=Limite){
                    Inputs(CharEscrito);
                }
                else if(texto.str().length()>Limite && CharEscrito == DELETE_KEY){
                    Borrar();
                }

            }
            else{
                Inputs(CharEscrito);
            }
        }
    }
}
