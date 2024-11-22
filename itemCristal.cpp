#include "itemCristal.h"

Cristal::Cristal(string E){
    //_texture.loadFromFile("objetos/Gema1.PNG");
    _texture.loadFromFile(E);
    _sprite.setTexture(_texture);
}
void Cristal::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_sprite, states);
}
void Cristal::respawn(float x, float y) {
    // Establece la posición del sprite en la mitad de la pantalla
    _sprite.setPosition(x, y);
}
sf::FloatRect Cristal::getBounds() const{
    return _sprite.getGlobalBounds();
}
void Cristal::hide(){
    _sprite.setPosition(-100, -100);
}
