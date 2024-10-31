#ifndef BOTONES_H_INCLUDED
#define BOTONES_H_INCLUDED

#include <iostream>
#include <SFML\Graphics.hpp>

#include "colisiones.h"

using namespace std;

class Boton: public sf::Drawable, public Colision{
    protected:
        sf::RectangleShape rec;
        sf::Font font;
        sf::Text text;
    public:
        Boton(string E, int w, int h, float x, float y, int s, int r, int v, int a, string C);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void Posicion(float x, float y);
        void setColor(sf::Color color);
        sf::FloatRect getBounds() const override;
};

#endif // BOTONES_H_INCLUDED
