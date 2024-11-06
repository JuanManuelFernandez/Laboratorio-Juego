#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "botones.h"

class Menu{
    protected:
        sf::Sprite spriteFondo;
        sf::Texture fondo;
        sf::Vector2i PosicionMouse;
        sf::Event event;
        sf::Music MenuMusic;
        bool Reproducir;
    public:
        Menu();
        void HacerMenu();
};

#endif // MENU_H_INCLUDED
