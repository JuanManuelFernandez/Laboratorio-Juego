#include "enemigo.h"

Enemigo::Enemigo(string E, int w, int h){
    shape.setSize(sf::Vector2f(w, h));
    _texture.loadFromFile(E);

    shape.setTexture(&_texture);
}

void Enemigo::Respawn(float x, float y){
    shape.setPosition(x, y);
}

void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(shape, states);
}

sf::FloatRect Enemigo::getBounds() const{
    return shape.getGlobalBounds();
}
