#include "casa1.h"

Cuadrado::Cuadrado(string E, int w, int h){
    rec.setSize(sf::Vector2f(w, h));
    _texture.loadFromFile(E);

    rec.setTexture(&_texture);
}
void Cuadrado::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rec, states);
}
void Cuadrado::Posicion(float x, float y){
    rec.setPosition(x, y);
}
sf::FloatRect Cuadrado::getBounds() const{
    return rec.getGlobalBounds();
}
