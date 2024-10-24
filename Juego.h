#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "funciones.h"
#include "itemCristal.h"
#include "itemCorazon.h"
#include "casa1.h"
#include "enemigo.h"
#include "Pelea.h"
#include "interfazPelea.h"

class Juego{
    protected:
        int puntos = 0;
        int puntoSalud = 100;
        int puntosSaludE = 50;
        bool Visibles = true;
        bool bandera = true;
        bool banderaE = true;
        ///FONDO
        sf::Texture fondo;
        sf::Sprite spriteFondo;
        ///CONTADOR
        sf::Font font;
        sf::Font fontVida;
        sf::Text text, TextSalud, TextSaludE;
        ///SONIDO
        sf::SoundBuffer buffer;
        sf::Sound soundItem;
        sf::SoundBuffer buffer2;
        sf::Sound soundHeart;
        ///RELOJ PARA TRANSICIÓN
        sf::Clock reloj;
    public:
        void Jugar();
};

#endif // JUEGO_H_INCLUDED
