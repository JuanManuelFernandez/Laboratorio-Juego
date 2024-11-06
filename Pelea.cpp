#include "Pelea.h"

EnPelea::EnPelea(){
    TurnoJugador = true;
    Clickeo = false;
    EnemigoMuerto = false;
    setVida = true;

    font.loadFromFile("Pixeleada.ttf");
    TextTurno.setFont(font);
    TextHP.setFont(font);
    TextHPE.setFont(font);
    TextLog.setFont(font);
    TextLogDamage.setFont(font);

    Buff1.loadFromFile("sonidos/corte.wav");
    Buff2.loadFromFile("sonidos/miss.wav");
    Buff3.loadFromFile("sonidos/GolpeEnemigo.wav");

    Golpe.setBuffer(Buff1);
    Miss.setBuffer(Buff2);
    GolpeE.setBuffer(Buff3);

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

bool EnPelea::Pelear(int* HP, int p, int d, bool B1, bool B2){
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
    TextLog.setCharacterSize(27);
    TextLogDamage.setCharacterSize(24);


    ///TURNO DE ZARAC
    if(TurnoJugador){
        TextTurno.setPosition(200, 150);
        TextTurno.setString("TURNO DE ZARAC");
        if(reloj.getElapsedTime().asSeconds() >= 2){
            TextTurno.setPosition(-100, -100);
            TextLog.setPosition(-100, -100);
            TextLogDamage.setPosition(-100, -100);
        }
        if(B1){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !Clickeo){
                if(Probabilidad() >= 1){
                    Golpe.play();
                    HPE -= 10;
                    TextLog.setPosition(420, 450);
                    TextLog.setString("Golpe acertado!");
                    TextLogDamage.setPosition(390, 500);
                    TextLogDamage.setString("Realizaste 10 de Dano!");

                }
                else{
                    Miss.play();
                }
                Clickeo = true;
                TurnoJugador = false;
                reloj.restart(); ///SE COMIENZA EL CONTEO PARA DESAPARECER EL TEXTO DE TURNO
                TextTurno.setPosition(170, 150);
                TextTurno.setString("TURNO DEL ENEMIGO");
            }
        }
        else if(B2){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !Clickeo){
                if(Probabilidad() >= 1){
                    Golpe.play();
                    HPE -= 25;
                    TextLog.setPosition(420, 450);
                    TextLog.setString("Golpe acertado!");
                    TextLogDamage.setPosition(390, 500);
                    TextLogDamage.setString("Realizaste 25 de Dano!");
                }
                else{
                    Miss.play();
                    TextLog.setPosition(400, 450);
                    TextLog.setString("Fallaste el Golpe!");
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
            if(Probabilidad() >= 25){
                GolpeE.play();
                *HP -= d;
                TextLog.setPosition(420, 450);
                TextLog.setString("Golpe Recibido");
                TextLogDamage.setPosition(390, 500);
                TextLogDamage.setString("Recibiste " + to_string(d) + " de dano!");
            }
            else{
                Miss.play();
                TextLog.setPosition(400, 450);
                TextLog.setString("El enemigo FALLO!");
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
        TextLog.setPosition(-100, -100);
        TextLogDamage.setPosition(-100, -100);
        return true;
    }
    else if(*HP <= 0){
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
sf::Text EnPelea::getTextLog(){
    return TextLog;
}
sf::Text EnPelea::getTextLogDamage(){
    return TextLogDamage;
}
