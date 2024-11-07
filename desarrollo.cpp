#include "funciones.h"
#include "casa1.h"

///PERSONAJE MAIN
Personaje::Personaje(){
    ///LE DAMOS UNA TEXTURA AL PERSONAJE
    _texture.loadFromFile("Personaje/Zarac.PNG");

    _sprite.setTexture(_texture);

    ///ESTABLECEMOS LA VELOCIDAD
    _velocidad = {5, 5};

    ///PARA QUE LA TRANSICIÓN DEL SALTO AL CAMBIO DE POSICIÓN NO SE NOTE
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, 0);

    CambioEscena = false;
}

void Personaje::Update(bool P){
    _velocidad = {0, 0};

    ///MOVIMIENTOS CON LOS INPUTS
    if(P==false){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            _texture.loadFromFile("Personaje/back.png");
            _velocidad.y = -5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            _texture.loadFromFile("Personaje/izq-der.png");
            _velocidad.x = -5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
             _texture.loadFromFile("Personaje/Zarac.png");
            _velocidad.y = 5;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            _texture.loadFromFile("Personaje/izq-der.png");
            _velocidad.x = 5;
        }

        _sprite.move(_velocidad);
    }

    if(_velocidad.x < 0){
        _sprite.setScale(1, 1);
    }

    else if(_velocidad.x > 0){
        _sprite.setScale(-1, 1);
    }

    ///HACEMOS QUE EL PERSONAJE NO SE SALGA DE LA PANTALLA PARA ARRIBA Y PARA LA IZQ
    if(_sprite.getGlobalBounds().left < 0){
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if(_sprite.getGlobalBounds().top < 0){
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }

    ///HACEMOS QUE EL PERSONAJE NO SE SALGA DE LA PANTALLA PARA ABAJO Y PARA LA DER
    /// Si va a la derecha cambia la escena
    if(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800){
        _sprite.setPosition(800 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
        CambioEscena = true;
    }
    if(_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600){
        _sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
    }
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_sprite, states);
}

void Personaje::Respawn(float x, float y) {
    _sprite.setPosition(x, y);
}
sf::FloatRect Personaje::getBounds() const{
    return _sprite.getGlobalBounds();
}
void Personaje::setPosicion(const sf::Vector2f& posicion){
    _sprite.setPosition(posicion);
}
sf::Vector2f Personaje::getPosicion(){
    return _sprite.getPosition();
}
sf::Vector2f Personaje::getVelocidad() const{
    return _velocidad;
}

bool Personaje::getCambio(){
    return CambioEscena;
}
