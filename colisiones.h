#ifndef COLISIONES_H_INCLUDED
#define COLISIONES_H_INCLUDED

#include <SFML\Graphics.hpp>

class Colision {
    public:
        virtual sf::FloatRect getBounds() const = 0;
        bool esColision(Colision& col) const;
};

#endif // COLISIONES_H_INCLUDED
