#ifndef ITEMCRISTAL_H_INCLUDED
#define ITEMCRISTAL_H_INCLUDED

#include <iostream>
#include <SFML\Graphics.hpp>
#include "colisiones.h"

using namespace std;

class Cristal: public sf::Drawable, public Colision{
    protected:
        sf::Sprite _sprite;
        sf::Texture _texture;
    public:
        Cristal(string E);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void respawn(float x, float y);
        sf::FloatRect getBounds() const override; ///COLISION
        void hide();
};

#endif // ITEMCRISTAL_H_INCLUDED
