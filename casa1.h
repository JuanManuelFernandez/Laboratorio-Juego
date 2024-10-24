#ifndef CASA1_H_INCLUDED
#define CASA1_H_INCLUDED

#include <iostream>
#include <SFML\Graphics.hpp>
#include "colisiones.h"

using namespace std;

class Cuadrado: public sf::Drawable, public Colision{
    protected:
        sf::RectangleShape rec;
        sf::Texture _texture;
    public:
        Cuadrado(string E, int w, int h);
        void Posicion(float x, float y);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
};
#endif // CASA1_H_INCLUDED
