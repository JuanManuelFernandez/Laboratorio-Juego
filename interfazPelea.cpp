#include "interfazPelea.h"

Interfaz::Interfaz(){
    rec.setSize(sf::Vector2f(350, 200));
    rec.setFillColor(sf::Color(0, 100, 230)); ///ROJO, VERDE Y AZUL (255 VALOR PURO)

    rec.setOutlineThickness(10.f);
    rec.setOutlineColor(sf::Color::Blue);

    font.loadFromFile("Pixeleada.ttf");
    TextAtaque.setFont(font);

    TextAtaque.setCharacterSize(30);
    TextAtaque.setFillColor(sf::Color::White);
    TextAtaque.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TextAtaque.setString("LIGERO");
    TextAtaque.setPosition(50, 450);

    TextAtaque2.setFont(font);

    TextAtaque2.setCharacterSize(30);
    TextAtaque2.setFillColor(sf::Color::White);
    TextAtaque2.setStyle(sf::Text::Bold | sf::Text::Underlined);
    TextAtaque2.setString("PESADO");
    TextAtaque2.setPosition(50, 500);
}

void Interfaz::Posicion(){
    rec.setPosition(10, 405);
}

void Interfaz::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(rec, states);
    target.draw(TextAtaque, states);
    target.draw(TextAtaque2, states);
}
