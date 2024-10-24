#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <SFML\Graphics.hpp>
#include "colisiones.h"

class Personaje: public sf::Drawable, public Colision{
    protected:
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::Vector2f _velocidad;
    public:
        Personaje();
        void Update();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void Respawn(float x, float y);
        sf::FloatRect getBounds() const override;
        void setPosicion(const sf::Vector2f& posicion);
        sf::Vector2f getPosicion();
        sf::Vector2f getVelocidad() const;
};

#endif // FUNCIONES_H_INCLUDEDSS
