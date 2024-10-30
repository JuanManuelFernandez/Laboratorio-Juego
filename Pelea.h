#ifndef PELEA_H_INCLUDED
#define PELEA_H_INCLUDED

#include <iostream>
#include <ctime>
#include <SFML\Graphics.hpp>
#include "botones.h"

using namespace std;

class EnPelea: public sf::Drawable{
    protected:
        sf::RectangleShape rec;
        sf::Texture _texture;
        sf::Font font;
        sf::Text TextHP, TextHPE, TextTurno;
        sf::Clock reloj;
        bool TurnoJugador = true, Clickeo = false, EnemigoMuerto = false, setVida = true;
        int HPE = 0;
        string Enlace;
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
        ///int getSalud();
        bool Pelear(int* HP, int p, bool s);
};


#endif // PELEA_H_INCLUDED
