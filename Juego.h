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
#include "botones.h"

class Juego{
    protected:
        int puntos = 0, EnemigoActivo = 0;
        int* puntoSalud;
        bool Visibles = true, EnemigoMuerto = false, Gano = false, SobreBoton = false;
        ///FONDO
        sf::Texture fondo;
        sf::Sprite spriteFondo;
        ///CONTADOR
        sf::Font font;
        sf::Text text, TextSalud;
        ///SONIDO
        sf::SoundBuffer buffer, buffer2;
        sf::Sound soundItem, soundHeart;
        ///RELOJ PARA TRANSICIÓN
        ///sf::Clock reloj;
        sf::Vector2i PosicionMouse;
        sf::Event event;
    public:
        void Jugar();
        ~Juego();
};

#endif // JUEGO_H_INCLUDED
