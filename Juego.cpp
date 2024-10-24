#include "Juego.h"

void Juego::Jugar(){
    ///INICIO DE VENTANA
    sf::RenderWindow window(sf::VideoMode(800, 600), "Kingdom of Kloster");
    window.setFramerateLimit(60);

    font.loadFromFile("Pixeleada.ttf");
    fontVida.loadFromFile("Pixeleada.ttf");

    text.setFont(font);
    TextSalud.setFont(fontVida);
    TextSaludE.setFont(fontVida);
    text.setColor(sf::Color::White);
    TextSalud.setColor(sf::Color::White);
    TextSaludE.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setCharacterSize(30);
    text.setPosition(10, 10);

    TextSalud.setCharacterSize(30);
    TextSalud.setPosition(70, 10);

    TextSaludE.setCharacterSize(30);

    fondo.loadFromFile("fondo/Pixeleado.png");
    spriteFondo.setTexture(fondo);

    buffer.loadFromFile("sonidos/item.wav");
    soundItem.setBuffer(buffer);

    buffer2.loadFromFile("sonidos/heart.wav");
    soundHeart.setBuffer(buffer2);

    ///INSTANCIA DE LOS OBJ DE CLASE(MAPA)
    Personaje Zarac;
    Enemigo Esqueleto("Enemigos/Esqueleto.png", 60, 120);
    Enemigo Rata("Enemigos/rata2.png", 180, 120);

    Cuadrado formas[] = {
        Cuadrado("objetos/derrumbada.png", 153, 75),
        Cuadrado("objetos/casa3.png", 178, 169),
        Cuadrado("objetos/casa4.png", 171, 153),
        Cuadrado("objetos/casa2.png", 80, 150),
        Cuadrado("objetos/solaire.png", 61, 162)
    };

    Cristal item("objetos/Gema1.png");
    Cristal item2("objetos/Gema2.png");
    Cristal item3("objetos/Gema1.png");
    Cristal item4("objetos/Gema2.png");

    Corazon itemC, itemC2;

    ///INSTANCIA DE LOS OBJ DE CLASE(PELEA)
    Interfaz InterfazAtaques;
    EnPelea PersonajeP("Personaje/ZaracFight.png", 150, 160);
    EnPelea EnemigoP("Enemigos/Esqueleto.png", 80, 160);

    ///RESPAWNS PERSONAJE, ENEMIGOS, ESTRUCTURAS
    Zarac.Respawn(900, 50);
    Esqueleto.Respawn(270, 80);
    Rata.Respawn(50, 230);

    formas[0].Posicion(80, 70);
    formas[1].Posicion(550, 20);
    formas[2].Posicion(75, 400);
    formas[3].Posicion(600, 400);
    formas[4].Posicion(380, 190);

    ///RESPAWN CRISTAL
    item.respawn(800, 800);
    item2.respawn(50, 600);
    item3.respawn(1550, 540);
    item4.respawn(1550, 660);

    ///RESPAWN CORAZON
    itemC.respawn(1100, 50);
    itemC2.respawn(800, 1150);

    ///RESPAWN PELEA

    PersonajeP.Posicion(450, 220);
    EnemigoP.Posicion(250, 220);
    InterfazAtaques.Posicion();

    ///GAMELOOP
    while (window.isOpen()){
        ///ACTUALIZA LOS ESTADOS DONDE TIENE LA INFORMACION DE LOS INPUTS (PERIFERICOS DE ENTRADA)
        sf::Event event;
        while (window.pollEvent(event)){
            ///NOS PERFMITE CERRAR LA VENTANA
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        ///COMANDOS/CMD

        ///ESTABLECEMOS LAS CORDENADAS PARA EL EJE X e Y

        ///UPDATE
        Zarac.Update();
        if(Zarac.esColision(item)){
            puntos++;
            soundItem.play();
            item.hide();
        }
        if(Zarac.esColision(item2)){
            puntos++;
            soundItem.play();
            item2.hide();
        }
        if(Zarac.esColision(item3)){
            puntos++;
            soundItem.play();
            item3.hide();
        }
        if(Zarac.esColision(item4)){
            puntos++;
            soundItem.play();
            item4.hide();
        }

        if(Zarac.esColision(itemC) && puntoSalud<100){
            if(puntoSalud + 50 > 100){
                puntoSalud = 100;
            }
            else{
                puntoSalud += 50;
            }
            soundHeart.play();
            itemC.hide();
        }
        if(Zarac.esColision(itemC2) && puntoSalud<100){
            if(puntoSalud + 50 > 100){
                puntoSalud = 100;
            }
            else{
                puntoSalud += 50;
            }
            soundHeart.play();
            itemC2.hide();
        }

        if(Zarac.esColision(formas[0])){
            Zarac.setPosicion(Zarac.getPosicion() - Zarac.getVelocidad());
        }
        if(Zarac.esColision(formas[1])){
            Zarac.setPosicion(Zarac.getPosicion() - Zarac.getVelocidad());
        }
        if(Zarac.esColision(formas[2])){
            Zarac.setPosicion(Zarac.getPosicion() - Zarac.getVelocidad());
        }
        if(Zarac.esColision(formas[3])){
            Zarac.setPosicion(Zarac.getPosicion() - Zarac.getVelocidad());
        }


        ///TEST PELEA
        if(Zarac.esColision(Esqueleto)){
            Visibles = false;
            fondo.loadFromFile("fondo/pelea.png");
            TextSalud.setPosition(550, 10);
            TextSaludE.setPosition(30, 10);

            if(puntosSaludE>0){
                if(bandera){
                    if(PersonajeP.Probabilidad()>50){
                        ///sf::sleep(sf::seconds(2)); ///PAUSA EL JUEGO
                        puntosSaludE = puntosSaludE - 10;
                    }
                    bandera = false;
                }
            }
            if(puntoSalud>0){
                if(banderaE){
                    if(EnemigoP.Probabilidad()>50){
                        puntoSalud = puntoSalud - 10;
                    }
                    banderaE = false;
                }
            }
            if(puntosSaludE==0){
                if(reloj.getElapsedTime().asSeconds() >= 3){
                    Esqueleto.Respawn(-100, -100);
                    fondo.loadFromFile("fondo/Pixeleado.png");
                    Visibles = true;
                }
            }
            else{
                bandera = true;
                banderaE = true;
            }

        }

        text.setString(std::to_string(puntos));
        TextSalud.setString("Salud: " + std::to_string(puntoSalud));
        TextSaludE.setString("Salud: " + std::to_string(puntosSaludE));

        ///SE BORRA PARA NO SUPERPONER
        window.clear();

        ///DRAW FONDO
        window.draw(spriteFondo);

        ///DRAW PJ
        if(Visibles){
            ///DRAW PJ
            window.draw(Zarac);
            window.draw(Esqueleto);
            window.draw(Rata);
            window.draw(formas[0]);
            window.draw(formas[1]);
            window.draw(formas[2]);
            window.draw(formas[3]);
            window.draw(formas[4]);

            ///DRAW CRISTAL
            window.draw(item);
            window.draw(item2);
            window.draw(item3);
            window.draw(item4);

            ///DRAW CORAZON
            window.draw(itemC);
            window.draw(itemC2);
            window.draw(text);
            window.draw(TextSalud);
        }

        else{
            window.draw(PersonajeP);
            window.draw(EnemigoP);
            window.draw(TextSalud);
            window.draw(TextSaludE);
            window.draw(InterfazAtaques);
        }


        ///DISPLAY
        window.display();
    }

        ///LIBERACION DEL JUEGO

}
