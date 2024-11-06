#include "Juego.h"

Juego::Juego(){
    puntoSalud = new int(100);
    puntos = 0;
    EnemigoActivo = 0;
    Visibles = true;
    EnemigoMuerto = false;
    Gano = false;
    SobreBoton1 = false;
    SobreBoton2 = false;
    Peleando = false;
    EnCambio = false;
    PosicionFinal = false;
    PeleaTerminada = false;
    Reproducir = true;
    fondoMensaje= true;
    fondoMensajeFinal = false;
    font.loadFromFile("Pixeleada.ttf");

    text.setFont(font);
    TextSalud.setFont(font);
    text.setColor(sf::Color::White);
    TextSalud.setColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setCharacterSize(30);
    text.setPosition(10, 10);

    TextSalud.setCharacterSize(30);
    TextSalud.setPosition(70, 10);

    fondo.loadFromFile("fondo/Pixeleado.png");

    spriteFondo.setTexture(fondo);

    buffer.loadFromFile("sonidos/item.wav");
    soundItem.setBuffer(buffer);

    buffer2.loadFromFile("sonidos/heart.wav");
    soundHeart.setBuffer(buffer2);

    MusicaMapa.openFromFile("sonidos/Musica/MapTheme.wav");
    MusicaMapa.setVolume(20.f);

    MusicaPelea.openFromFile("sonidos/Musica/Normal-Fight.wav");
    MusicaPelea.setVolume(20.f);

    MusicaVictoria.openFromFile("sonidos/Musica/VictoryTheme.wav");
    MusicaVictoria.setVolume(20.f);

    MusicaPeleaFinal.openFromFile("sonidos/Musica/FinalBossTheme.wav");
    MusicaPeleaFinal.setVolume(20.f);
}

void Juego::Jugar(){
    ///INICIO DE VENTANA
    sf::RenderWindow window(sf::VideoMode(800, 600), "Kingdom of Kloster");
    window.setFramerateLimit(60);

    MusicaMapa.play();
    MusicaMapa.setLoop(Reproducir);

    Inicializador ejem;
    ejem.ejemplo();

    ///INSTANCIA DE LOS OBJ DE CLASE(MAPA)
    Personaje Zarac;
    Enemigo Esqueleto("Enemigos/Esqueleto.png", 60, 120);
    Enemigo Rata("Enemigos/rata2.png", 180, 120);
    Enemigo Artorias("Enemigos/ArtoriasMap.png", 250, 250);

    Cuadrado formas[] = {
        ///MAPA MAIN
        Cuadrado("objetos/derrumbada.png", 153, 75),
        Cuadrado("objetos/casa3.png", 178, 169),
        Cuadrado("objetos/casa4.png", 171, 153),
        Cuadrado("objetos/casa2.png", 80, 150),
        Cuadrado("objetos/solaire.png", 61, 162),
        ///MAPA FINAL
        Cuadrado("objetos/CasaDestruida.png", 170, 169),
        Cuadrado("objetos/Escombros.png", 200, 100)
    };

    Cristal item("objetos/Gema1.png");
    Cristal item2("objetos/Gema2.png");
    Cristal item3("objetos/Gema1.png");
    Cristal item4("objetos/Gema2.png");

    Corazon itemC, itemC2;

    ///INSTANCIA DE LOS OBJ DE CLASE(PELEA)
    Interfaz InterfazAtaques;
    EnPelea Pelea;
    EnPelea PersonajeP;
    EnPelea EnemigoE;
    EnPelea EnemigoR;
    EnPelea EnemigoFinal;

    BotonesPelea Boton1;
    Boton1.Posicion(250, 450);
    BotonesPelea Boton2;
    Boton2.Posicion(250, 500);

    ///RESPAWNS PERSONAJE, ENEMIGOS, ESTRUCTURAS
    Zarac.Respawn(410, 0);
    Esqueleto.Respawn(270, 80);
    Rata.Respawn(50, 230);
    Artorias.Respawn(400, 100);

    formas[0].Posicion(80, 70);
    formas[1].Posicion(550, 20);
    formas[2].Posicion(75, 400);
    formas[3].Posicion(600, 400);
    formas[4].Posicion(380, 190);
    formas[5].Posicion(80, 10);
    formas[6].Posicion(550, 20);

    ///RESPAWN CRISTAL
    item.respawn(800, 800);
    item2.respawn(50, 600);
    item3.respawn(1550, 540);
    item4.respawn(1550, 660);

    ///RESPAWN CORAZON
    itemC.respawn(1100, 50);
    itemC2.respawn(800, 1150);

    InterfazAtaques.Posicion();

    ///FIN DEFINICION/INSTANCIA DE LOS OBJETOS

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
        ///UPDATE
        Zarac.Update(Peleando);
        if(Zarac.getCambio()){
            fondo.loadFromFile("fondo/EscenarioFinal.png");
            EnCambio = true;
            if(PosicionFinal==false){
                Zarac.Respawn(100, 300);
                PosicionFinal = true;
            }
        }
        if(EnCambio==false){
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

            if(Zarac.esColision(itemC) && *puntoSalud<100){
                if(*puntoSalud + 50 > 100){
                    *puntoSalud = 100;
                }
                else{
                    *puntoSalud += 50;
                }
                soundHeart.play();
                itemC.hide();
            }
            if(Zarac.esColision(itemC2) && *puntoSalud<100){
                if(*puntoSalud + 50 > 100){
                    *puntoSalud = 100;
                }
                else{
                    *puntoSalud += 50;
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

            ///PELEA ESQUELETO
            if(Zarac.esColision(Esqueleto)){
                MusicaMapa.pause();
                if (MusicaPelea.getStatus() != sf::Music::Playing){
                    MusicaPelea.play();
                    MusicaPelea.setLoop(Reproducir);
                }
                Visibles = false;
                Peleando = true;
                EnemigoActivo = 1;
                fondo.loadFromFile("fondo/pelea.png");
                PersonajeP.setTextura("Personaje/ZaracFight.png");
                PersonajeP.setTam(150, 160);
                PersonajeP.Posicion(450, 220);

                EnemigoE.setTextura("Enemigos/Esqueleto.png");
                EnemigoE.setTam(80, 160);
                EnemigoE.Posicion(250, 220);

                if(event.type==sf::Event::MouseMoved){
                    PosicionMouse = sf::Mouse::getPosition(window);
                    if(Boton1.getBounds().contains(PosicionMouse.x, PosicionMouse.y)){
                        SobreBoton1 = true;
                    }
                    else if(Boton2.getBounds().contains(PosicionMouse.x, PosicionMouse.y)){
                        SobreBoton2 = true;
                    }
                }
                if(!PeleaTerminada){
                    Gano = Pelea.Pelear(puntoSalud, 50, 10, SobreBoton1, SobreBoton2);
                }

                ///MURIO SI/NO
                if(Gano==true){
                    PeleaTerminada = true;
                    EnemigoMuerto = true;
                }
                ///RESETEA SI EL ENEMIGO MURIO
                if(EnemigoMuerto){
                    fondo.loadFromFile("fondo/EnNegro.png");
                    MusicaPelea.stop();
                    if(MusicaVictoria.getStatus() != sf::Music::Playing){
                        MusicaVictoria.play();
                        MusicaVictoria.setLoop(Reproducir);
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                        Visibles = true;
                        PeleaTerminada = false;
                        EnemigoMuerto = false;
                        Gano = false;
                        Peleando = false;
                        puntos += 5;
                        Esqueleto.Respawn(-100, -100);
                        MusicaVictoria.stop();
                        MusicaMapa.play();
                        fondo.loadFromFile("fondo/Pixeleado.png");
                    }
                }
                SobreBoton1 = false;
                SobreBoton2 = false;
            }
            ///PELEA RATA
            if(Zarac.esColision(Rata)){
                MusicaMapa.pause();
                if (MusicaPelea.getStatus() != sf::Music::Playing){
                    MusicaPelea.play();
                    MusicaPelea.setLoop(Reproducir);
                }
                Visibles = false;
                Peleando = true;
                EnemigoActivo = 2;
                fondo.loadFromFile("fondo/pelea.png");
                PersonajeP.setTextura("Personaje/ZaracFight.png");
                PersonajeP.setTam(150, 160);
                PersonajeP.Posicion(450, 220);

                EnemigoR.setTextura("Enemigos/rata.png");
                EnemigoR.setTam(250, 160);
                EnemigoR.Posicion(150, 250);

                if(event.type==sf::Event::MouseMoved){
                    PosicionMouse = sf::Mouse::getPosition(window);
                    if(Boton1.getBounds().contains(PosicionMouse.x, PosicionMouse.y)){
                        SobreBoton1 = true;
                    }
                    else if(Boton2.getBounds().contains(PosicionMouse.x, PosicionMouse.y)){
                        SobreBoton2 = true;
                    }
                }
                if(!PeleaTerminada){
                    Gano = Pelea.Pelear(puntoSalud, 50, 10, SobreBoton1, SobreBoton2);
                }

                ///MURIO SI/NO
                if(Gano==true){
                    PeleaTerminada = true;
                    EnemigoMuerto = true;
                }
                ///RESETEA SI EL ENEMIGO MURIO
                if(EnemigoMuerto){
                    fondo.loadFromFile("fondo/EnNegro.png");
                    MusicaPelea.stop();
                    if(MusicaVictoria.getStatus() != sf::Music::Playing){
                        MusicaVictoria.play();
                        MusicaVictoria.setLoop(Reproducir);
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                        Visibles = true;
                        PeleaTerminada = false;
                        EnemigoMuerto = false;
                        Gano = false;
                        Peleando = false;
                        puntos += 5;
                        Rata.Respawn(-200, -200);
                        MusicaVictoria.stop();
                        MusicaMapa.play();
                        fondo.loadFromFile("fondo/Pixeleado.png");
                    }
                }
                SobreBoton1 = false;
                SobreBoton2 = false;
            }
        }
        else{
            ///CASAS MAPA FINAL
            if(Zarac.esColision(formas[5])){
                Zarac.setPosicion(Zarac.getPosicion() - Zarac.getVelocidad());
            }
            if(Zarac.esColision(formas[6])){
                Zarac.setPosicion(Zarac.getPosicion() - Zarac.getVelocidad());
            }
            ///PELEA ARTORIAS
            if(Zarac.esColision(Artorias)){
                MusicaMapa.pause();
                if(MusicaPeleaFinal.getStatus() != sf::Music::Playing && !EnemigoMuerto){
                    MusicaPeleaFinal.play();
                    MusicaPeleaFinal.setLoop(Reproducir);
                }
                Visibles = false;
                Peleando = true;
                EnemigoActivo = 2;
                fondo.loadFromFile("fondo/pelea.png");
                PersonajeP.setTextura("Personaje/ZaracFight.png");
                PersonajeP.setTam(150, 160);
                PersonajeP.Posicion(450, 220);

                EnemigoFinal.setTextura("Enemigos/ArtoriasFight.png");
                EnemigoFinal.setTam(300, 300);
                EnemigoFinal.Posicion(100, 110);

                if(event.type==sf::Event::MouseMoved){
                    PosicionMouse = sf::Mouse::getPosition(window);
                    if(Boton1.getBounds().contains(PosicionMouse.x, PosicionMouse.y)){
                        SobreBoton1 = true;
                    }
                    else if(Boton2.getBounds().contains(PosicionMouse.x, PosicionMouse.y)){
                        SobreBoton2 = true;
                    }
                }
                if(!PeleaTerminada){
                    Gano = Pelea.Pelear(puntoSalud, 100, 15, SobreBoton1, SobreBoton2);
                }
                ///MURIO SI/NO
                if(Gano==true){
                    PeleaTerminada = true;
                    EnemigoMuerto = true;
                }
                ///RESETEA SI EL ENEMIGO MURIO
                if(EnemigoMuerto){
                    if(fondoMensaje){
                        fondo.loadFromFile("fondo/Mensaje.png");
                    }
                    if(MusicaPeleaFinal.getStatus() == sf::Music::Playing){
                        MusicaPeleaFinal.pause();
                    }
                    /*
                    if(MusicaVictoria.getStatus() != sf::Music::Playing){
                        MusicaVictoria.play();
                        MusicaVictoria.setLoop(Reproducir);
                    }
                    */
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                        fondoMensaje=false;
                        fondoMensajeFinal = true;
                        /*
                        Visibles = true;
                        PeleaTerminada = false;
                        EnemigoMuerto = false;
                        Gano = false;
                        Peleando = false;
                        puntos += 5;
                        Artorias.Respawn(-300, -300);
                        MusicaVictoria.stop();
                        MusicaMapa.play(),
                        fondo.loadFromFile("fondo/EscenarioFinal.png");
                        */
                    }
                    if(fondoMensajeFinal){
                        fondo.loadFromFile("fondo/PantallaFinal.png");
                    }
                    /*
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                        window.close();
                        Menu objMenu;
                        objMenu.HacerMenu();
                    }
                    */
                }
                SobreBoton1 = false;
                SobreBoton2 = false;
            }
        }

        text.setString(std::to_string(puntos));
        TextSalud.setString("Salud: " + std::to_string(*puntoSalud));

        ///SE BORRA PARA NO SUPERPONER
        window.clear();

        ///DRAW FONDO
        window.draw(spriteFondo);

        ///DRAW PJ
        if(Zarac.getCambio()==false){
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
                if(EnemigoMuerto==false){
                    window.draw(PersonajeP);
                    ///VERIFICAMOS EN QUE PELEA ESTAMOS
                    if(EnemigoActivo==1){
                        window.draw(EnemigoE);
                    }
                    else if(EnemigoActivo==2){
                        window.draw(EnemigoR);
                    }
                    window.draw(Pelea.getTextHP());
                    window.draw(Pelea.getTextHPE());
                    window.draw(Pelea.getTextoTurno());
                    window.draw(Pelea.getTextLog());
                    window.draw(Pelea.getTextLogDamage());

                    window.draw(InterfazAtaques);
                    window.draw(Boton1);
                    window.draw(Boton2);
                }
            }
        }
        else{
            if(Visibles){
                window.draw(Zarac);
                window.draw(Artorias);
                window.draw(formas[5]);
                window.draw(formas[6]);
                window.draw(text);
                window.draw(TextSalud);
            }
            else{
                if(EnemigoMuerto==false){
                    window.draw(PersonajeP);
                    window.draw(EnemigoFinal);
                    window.draw(Pelea.getTextHP());
                    window.draw(Pelea.getTextHPE());
                    window.draw(Pelea.getTextoTurno());
                    window.draw(Pelea.getTextLog());
                    window.draw(Pelea.getTextLogDamage());

                    window.draw(InterfazAtaques);
                    window.draw(Boton1);
                    window.draw(Boton2);
                }
            }
        }
        ///DISPLAY
        window.display();
    }
}

Juego::~Juego(){
    delete puntoSalud;
}
