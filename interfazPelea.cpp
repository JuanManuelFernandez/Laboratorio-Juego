#include "interfazPelea.h"

Interfaz::Interfaz(){
    rec.setSize(sf::Vector2f(350, 200));
    rec.setFillColor(sf::Color(0, 100, 230)); ///ROJO, VERDE Y AZUL (255 VALOR PURO)

    rec.setOutlineThickness(10.f);
    rec.setOutlineColor(sf::Color::Blue);
}

void Interfaz::Posicion(){
    rec.setPosition(10, 405);
}

void Interfaz::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(rec, states);
}
