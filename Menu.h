#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "botones.h"
#include "CajaDeTexto.h"
#include "Puntaje.h"
#include "ArchivoPuntaje.h"

class Menu{
    protected:
        sf::Sprite spriteFondo;
        sf::Texture fondo;
        sf::Vector2i PosicionMouse;
        sf::Event event;
        sf::Music MenuMusic;
        bool Reproducir, Visibles, Activos, BotonPuntos;
        string* NombreEscrito;
    public:
        Menu();
        void HacerMenu();
        string getNombreEscrito();
};

#endif // MENU_H_INCLUDED
