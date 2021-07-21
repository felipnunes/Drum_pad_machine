#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "display.h" 
#include "sound.h"

int const screenSise = 500;
int main()
{
    sf::RenderWindow window(sf::VideoMode(screenSise, screenSise), "DPM");
    display display(screenSise);
    sound *som = new sound();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        window.clear();

        //atualiza o display
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                window.draw(display.matrix[i][j]);
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            display.reset_matrix();
        }
        //atualiza o audio

        //comandos do drumpad
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
                    som->playSound(0);
                    display.pressed_color(0,2);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                    som->playSound(1);
                    display.pressed_color(1,2);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                    som->playSound(2);
                    display.pressed_color(2,2);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                    som->playSound(3);
                    display.pressed_color(0,1);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                    som->playSound(4);
                    display.pressed_color(1,1);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                    som->playSound(5);
                    display.pressed_color(2,1);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    som->playSound(6);
                    display.pressed_color(0,0);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
                    som->playSound(7);
                    display.pressed_color(1,0);
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                    som->playSound(8);
                    display.pressed_color(2,0);
                }

        window.display();

    }
    return 0;
}


//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && sfml-app.exe