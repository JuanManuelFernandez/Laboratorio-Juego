#ifndef ITEMCORAZON_H_INCLUDED
#define ITEMCORAZON_H_INCLUDED

#include <SFML\Graphics.hpp>
#include "colisiones.h"

class Corazon: public sf::Drawable, public Colision{
    protected:
        sf::Sprite _sprite;
        sf::Texture _texture;
    public:
        Corazon();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void respawn(float x, float y);
        sf::FloatRect getBounds() const override;
        void hide();
};

#endif // ITEMCORAZON_H_INCLUDED
