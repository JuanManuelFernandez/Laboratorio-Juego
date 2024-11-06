#ifndef PELEA_H_INCLUDED
#define PELEA_H_INCLUDED

#include <iostream>
#include <ctime>
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include "botones.h"

using namespace std;

class EnPelea: public sf::Drawable{
    protected:
        sf::RectangleShape rec;
        sf::Texture _texture;
        sf::SoundBuffer Buff1, Buff2, Buff3;
        sf::Sound Golpe, Miss, GolpeE;
        sf::Font font;
        sf::Text TextHP, TextHPE, TextTurno, TextLog, TextLogDamage;
        sf::Clock reloj;
        bool TurnoJugador, Clickeo, EnemigoMuerto, setVida;
        int HPE = 0;
        string Enlace, EnlaceBuff;
    public:
        EnPelea();
        void Posicion(float x, float y);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        int Probabilidad();
        void setTextura(string Enlace);
        void setTam(int w, int h);
        sf::Text getTextoTurno();
        sf::Text getTextHP();
        sf::Text getTextHPE();
        sf::Text getTextLog();
        sf::Text getTextLogDamage();
        bool Pelear(int* HP, int p, int d, bool B1, bool B2);
};


#endif // PELEA_H_INCLUDED
