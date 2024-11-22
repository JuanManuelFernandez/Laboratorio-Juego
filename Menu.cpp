#include "Menu.h"

Menu::Menu() : NombreEscrito(std::make_unique<std::string>()){
    fondo.loadFromFile("fondo/Menu.png");
    spriteFondo.setTexture(fondo);

    MenuMusic.openFromFile("sonidos/Musica/MenuTheme.wav");
    MenuMusic.setVolume(20.f);

    font.loadFromFile("Pixeleada.ttf");

    PuntajesNombre.setFont(font);
    PuntajesNombre.setCharacterSize(20);
    PuntajesNombre.setPosition(50, 100);

    Reproducir = true;
    Visibles = true;
    Activos = true;
    puntaje = false;


}

void Menu::HacerMenu(bool ToF){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Kingdom of Kloster");
    window.setFramerateLimit(60);

    MenuMusic.play();
    MenuMusic.setLoop(Reproducir);

    Boton Botones[] = {
        Boton("Pixeleada.ttf", 200, 60, 335, 210, 30, 0, 0, 0, "JUGAR"),
        Boton("Pixeleada.ttf", 200, 60, 315, 315, 27, 0, 0, 0, "PUNTAJE"),
        Boton("Pixeleada.ttf", 200, 60, 340, 410, 30, 0, 0, 0, "SALIR")
    };

    CajaDeTexto caja(30, sf::Color::White, true);
    caja.Posicion(250, 300);
    caja.setLimite(true, 10);

    Botones[0].Posicion(300, 200);
    Botones[1].Posicion(300, 300);
    Botones[2].Posicion(300, 400);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            switch(event.type){
                case sf::Event::TextEntered:
                    if(!Visibles && !puntaje){
                        caja.Escribiendo(event);
                    }
            }
        }
        ///BOTON PUNTAJE
        if(Activos){
            if(event.type==sf::Event::MouseMoved){
                PosicionMouse = sf::Mouse::getPosition(window);
                if(Botones[0].getBounds().contains(PosicionMouse.x, PosicionMouse.y)){ /// boton jugar
                    Botones[0].setColor(sf::Color::Green);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        fondo.loadFromFile("fondo/PreJuego.png");
                        Visibles = false;
                        Activos = false;
                    }
                }
                else{
                    Botones[0].setColor(sf::Color::Black);
                }
            }

            if(event.type==sf::Event::MouseMoved){
                PosicionMouse = sf::Mouse::getPosition(window);
                if(Botones[1].getBounds().contains(PosicionMouse.x, PosicionMouse.y)){
                    Botones[1].setColor(sf::Color::Blue);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        if(ToF){
                            ArchivoPuntos archi("Puntaje.dat");
                            Puntaje aux;
                            fondo.loadFromFile("fondo/Puntaje.png");
                            puntaje = true;
                            Visibles = false;
                            Activos = false;
                            cantReg = archi.ContarRegistros();
                            for(int i=0; i<cantReg; i++){
                                aux = archi.leerRegistro(i);
                                TodosLosNombres += aux.getNombre();
                                TodosLosNombres += " : ";
                                TodosLosNombres += to_string(aux.getPuntaje());
                                TodosLosNombres += " | ";
                            }
                            TodosLosNombres = agregarSaltoLinea(TodosLosNombres, 50);
                            PuntajesNombre.setString(TodosLosNombres);
                        }
                        else{
                            cout << "Debes jugar una partida para ver el puntaje" << endl;
                        }
                        TodosLosNombres = "";
                    }
                }
                else{
                    Botones[1].setColor(sf::Color::Black);
                }
            }
            ///BOTON SALIR
            if(event.type==sf::Event::MouseMoved){
                PosicionMouse = sf::Mouse::getPosition(window);
                if(Botones[2].getBounds().contains(PosicionMouse.x, PosicionMouse.y)){
                    Botones[2].setColor(sf::Color::Red);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        window.close();
                    }
                }
                else{
                    Botones[2].setColor(sf::Color::Black);
                }
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !Activos && !puntaje){
                window.close();
                *NombreEscrito = caja.getTexto();
                MenuMusic.stop();
                Juego objJuego;
                objJuego.Jugar(NombreEscrito.get());
                fondo.loadFromFile("fondo/Menu.png");
                Visibles = true;
                Activos = true;
        }
        else{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !Visibles && puntaje && !Activos){
                fondo.loadFromFile("fondo/Menu.png");
                puntaje = false;
                Visibles = true;
                Activos = true;
            }
        }

        window.clear();

        window.draw(spriteFondo);
        if(Visibles){
            window.draw(Botones[0]);
            window.draw(Botones[1]);
            window.draw(Botones[2]);
        }
        else if(!Visibles && !Activos && puntaje){
            window.draw(PuntajesNombre);
        }
        else{
            window.draw(caja);
        }

        window.display();
    }
}

string Menu::getNombreEscrito(){
    return *NombreEscrito;
}
string Menu::agregarSaltoLinea(string saltoLinea, int CadaCuanto) {
    string agregarSalto;
    for (int i = 0; i < saltoLinea.length(); ++i) {
        agregarSalto += saltoLinea[i];
        if ((i + 1) % CadaCuanto == 0) {
            agregarSalto += '\n';
        }
    }
    return agregarSalto;
}
