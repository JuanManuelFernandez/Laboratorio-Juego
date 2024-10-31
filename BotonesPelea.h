#ifndef BOTONESPELEA_H_INCLUDED
#define BOTONESPELEA_H_INCLUDED

#include <iostream>
#include <SFML\Graphics.hpp>

#include "colisiones.h"

class BotonesPelea: public sf::Drawable, public Colision{
    protected:
        sf::CircleShape circ;
    public:
        BotonesPelea();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void Posicion(float x, float y);
        sf::FloatRect getBounds() const override;
};


#endif // BOTONESPELEA_H_INCLUDED
