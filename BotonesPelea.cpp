#include "BotonesPelea.h"

BotonesPelea::BotonesPelea(): circ(15.f){

    circ.setFillColor(sf::Color(255, 0, 0));
    circ.setOutlineThickness(5.f);
    circ.setOutlineColor(sf::Color(0, 255, 0));
}

void BotonesPelea::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(circ, states);
}

void BotonesPelea::Posicion(float x, float y){
    circ.setPosition(x, y);
}
sf::FloatRect BotonesPelea::getBounds() const{
    return circ.getGlobalBounds();
}
