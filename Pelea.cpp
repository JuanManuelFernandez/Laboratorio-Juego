#include "Pelea.h"

EnPelea::EnPelea(){
    font.loadFromFile("Pixeleada.ttf");
    TextTurno.setFont(font);
    TextHP.setFont(font);
    TextHPE.setFont(font);

    srand(time(0));
}

void EnPelea::Posicion(float x, float y){
    rec.setPosition(x, y);
}

void EnPelea::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(rec, states);
}

int EnPelea::Probabilidad(){
    return rand() % 100 + 1;
}

void EnPelea::setTextura(string Enlace){
    _texture.loadFromFile(Enlace);
    rec.setTexture(&_texture);
}

void EnPelea::setTam(int w, int h){
    rec.setSize(sf::Vector2f(w, h));
}

bool EnPelea::Pelear(int* HP, int p, bool s){
    if(setVida){
        HPE = p;
    }
    setVida = false;

    TextTurno.setCharacterSize(30);
    TextHP.setString("SALUD: " + to_string(*HP));
    TextHP.setCharacterSize(30);
    TextHP.setPosition(550, 10);
    TextHPE.setString("SALUD: " + to_string(HPE));
    TextHPE.setCharacterSize(30);
    TextHPE.setPosition(30, 10);

    ///TURNO DE ZARAC
    if(TurnoJugador){
        TextTurno.setPosition(200, 150);
        TextTurno.setString("TURNO DE ZARAC");
        if(reloj.getElapsedTime().asSeconds() >= 2){
            TextTurno.setPosition(-100, -100);
        }
        if(s){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !Clickeo){
                if(Probabilidad() >= 1){
                    HPE -= 10;
                }
                Clickeo = true;
                TurnoJugador = false;
                reloj.restart(); ///SE COMIENZA EL CONTEO PARA DESAPARECER EL TEXTO DE TURNO
                TextTurno.setPosition(170, 150);
                TextTurno.setString("TURNO DEL ENEMIGO");
            }
            else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !Clickeo){
                if(Probabilidad() > 50){
                    HPE -= 25;
                }
                Clickeo = true;
                TurnoJugador = false;
                reloj.restart();
                TextTurno.setPosition(170, 150);
                TextTurno.setString("TURNO DEL ENEMIGO");
            }
        }
    }

    ///TURNO DEL ENEMIGO
    if(!TurnoJugador && reloj.getElapsedTime().asSeconds() >= 2){
        TextTurno.setPosition(-100, -100); ///RECORDAR CAMBIAR PARA BORRAR EL TEXTO
        if(HPE > 0){
            if(Probabilidad() > 1){
                *HP -= 10;
            }
        }
        TurnoJugador = true;
        Clickeo = false;
        reloj.restart();
    }

    if(HPE <= 0){
        setVida = true;
        TurnoJugador = true;
        Clickeo = false;
        return true;
    }
    else if(HP <= 0){
        setVida = true;
        return false;
    }
    return false;
}

sf::Text EnPelea::getTextoTurno(){
    return TextTurno;
}
sf::Text EnPelea::getTextHP(){
    return TextHP;
}
sf::Text EnPelea::getTextHPE(){
    return TextHPE;
}
/*
int EnPelea::getSalud(){
    return HP;
}
*/
