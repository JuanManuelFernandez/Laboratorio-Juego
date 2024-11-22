#include "itemCorazon.h"

///CORAZON/VIDA
Corazon::Corazon(){
    _texture.loadFromFile("objetos/Heart.PNG");
    _sprite.setTexture(_texture);
}
void Corazon::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_sprite, states);
}
void Corazon::respawn(float x, float y){
    _sprite.setPosition(x, y);
}
sf::FloatRect Corazon::getBounds() const{
    return _sprite.getGlobalBounds();
}
void Corazon::hide(){
    _sprite.setPosition(-100, -100);
}
