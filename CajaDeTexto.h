#ifndef CAJADETEXTO_H_INCLUDED
#define CAJADETEXTO_H_INCLUDED

#include <SFML\Graphics.hpp>
#include <iostream>
#include "sstream"
///INPUT PARA BORRAR
#define DELETE_KEY 8
#define ENTER_KEY 13

using namespace std;

class CajaDeTexto: public sf::Drawable{
    private:
        sf::Text Caja;
        ostringstream texto;
        sf::Font fuente;
        bool Seleccionado, MaxCaracteres;
        int Limite;
    public:
        CajaDeTexto(int tam, sf::Color color, bool Selec);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void Inputs(int tecla);
        void Borrar();
        void Posicion(float x, float y);
        void Escribiendo(sf::Event input);
        void setLimite(bool ToF);
        void setLimite(bool ToF, int limit);
        void setSelect(bool ToF);
        string getTexto();
};


#endif // CAJADETEXTO_H_INCLUDED
