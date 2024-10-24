#include "Pelea.h"

EnPelea::EnPelea(string e, int w, int h){
    rec.setSize(sf::Vector2f(w, h));
    _texture.loadFromFile(e);

    rec.setTexture(&_texture);

    srand(time(0));
}

void EnPelea::Posicion(float x, float y){
    rec.setPosition(x, y);
}

void EnPelea::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(rec, states);
}

int EnPelea::Probabilidad(){
    return rand() % 100;
}
