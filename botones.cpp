#include "botones.h"

Boton::Boton(string E, int w, int h, float x, float y, int s, int r, int g, int b, string C){
            ///FUENTE, ANCHO Y ALTO, POSICION X E Y DEL TEXTO, SIZE(TAM), RED, GREEN, BLUE(escala rgb)
    rec.setSize(sf::Vector2f(w, h));
    rec.setFillColor(sf::Color(r, g, b));

    font.loadFromFile(E);
    text.setFont(font);

    text.setCharacterSize(s);
    text.setColor(sf::Color::Black);
    text.setPosition(x, y);

    text.setString(C);
}

void Boton::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(rec, states);
    target.draw(text, states);
}

void Boton::Posicion(float x, float y){
    rec.setPosition(x, y);
}

sf::FloatRect Boton::getBounds() const{
    return rec.getGlobalBounds();
}
