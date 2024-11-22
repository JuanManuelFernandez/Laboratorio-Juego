#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>
#include "colisiones.h"

using namespace std;

class Enemigo: public sf::Drawable, public Colision{
    protected:
        sf::RectangleShape shape;
        sf::Texture _texture;
    public:
        Enemigo(string E, int w, int h);
        void Respawn(float x, float y);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
};


#endif // ENEMIGO_H_INCLUDED
