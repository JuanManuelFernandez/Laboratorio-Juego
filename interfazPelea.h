#ifndef INTERFAZPELEA_H_INCLUDED
#define INTERFAZPELEA_H_INCLUDED

#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;

class Interfaz: public sf::Drawable{
    protected:
        sf::RectangleShape rec;
    public:
        Interfaz();
        void Posicion();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif // INTERFAZPELEA_H_INCLUDED
