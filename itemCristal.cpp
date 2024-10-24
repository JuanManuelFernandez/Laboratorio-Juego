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
    // Calcula las coordenadas x e y de la mitad de la pantalla
    x = x / 2 - _sprite.getGlobalBounds().width / 2;
    y = y / 2 - _sprite.getGlobalBounds().height / 2;

    // Establece la posición del sprite en la mitad de la pantalla
    _sprite.setPosition(x, y);
}
sf::FloatRect Cristal::getBounds() const{
    return _sprite.getGlobalBounds();
}
void Cristal::hide(){
    _sprite.setPosition(-100, -100);
}
