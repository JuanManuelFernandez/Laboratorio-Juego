#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Juego.h"
#include "botones.h"
#include "CajaDeTexto.h"
#include "Puntaje.h"
#include "ArchivoPuntaje.h"
#include <memory>


class Menu{
    protected:
        sf::Sprite spriteFondo;
        sf::Texture fondo;
        sf::Vector2i PosicionMouse;
        sf::Event event;
        sf::Music MenuMusic;
        sf::Font font;
        sf::Text PuntajesNombre;
        bool Reproducir, Visibles, Activos, puntaje;
        std::unique_ptr<std::string> NombreEscrito;
        int cantReg;
        string TodosLosNombres;

    public:
        Menu();
        void HacerMenu(bool ToF);
        string getNombreEscrito();
        string agregarSaltoLinea(string saltoLinea, int CadaCuanto);
};

#endif // MENU_H_INCLUDED
