#ifndef PELEA_H_INCLUDED
#define PELEA_H_INCLUDED

#include <iostream>
#include <ctime>
#include <SFML\Graphics.hpp>

using namespace std;

class EnPelea: public sf::Drawable{
    protected:
        sf::RectangleShape rec;
        sf::Texture _texture;
    public:
        EnPelea(string e, int w, int h);
        void Posicion(float x, float y);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        int Probabilidad();
};


#endif // PELEA_H_INCLUDED
