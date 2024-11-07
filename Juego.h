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
#include "BotonesPelea.h"
#include "Menu.h"

class Juego{
    protected:
        int puntos, EnemigoActivo;
        int* puntoSalud;
        bool Visibles, EnemigoMuerto, Gano, SobreBoton1, SobreBoton2, Peleando, EnCambio, PosicionFinal, PeleaTerminada, Reproducir, fondoMensaje, fondoMensajeFinal, Muerto, CheckPoint;
        ///FONDO
        sf::Texture fondo;
        sf::Sprite spriteFondo;
        ///CONTADOR
        sf::Font font;
        sf::Text text, TextSalud, TextMenu;
        ///SONIDO
        sf::SoundBuffer buffer, buffer2;
        sf::Sound soundItem, soundHeart;
        sf::Vector2i PosicionMouse;
        ///MUSICA
        sf::Music MusicaMapa, MusicaPelea, MusicaPeleaFinal, MusicaVictoria, MusicaDerrota, MusicaFinal;
    public:
        Juego();
        void Jugar();
        ~Juego();
};

#endif // JUEGO_H_INCLUDED
