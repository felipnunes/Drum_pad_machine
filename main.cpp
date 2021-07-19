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

            if(event.type == sf::Event::KeyPressed)
                if(event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }

                //comandos do drumpad
                else if(event.key.code == sf::Keyboard::V) {
                    som->playSound(0);
                }
                else if(event.key.code == sf::Keyboard::B) {
                    som->playSound(1);
                }
                else if(event.key.code == sf::Keyboard::N) {
                    som->playSound(2);
                }
                else if(event.key.code == sf::Keyboard::F) {
                    som->playSound(3);
                }
                else if(event.key.code == sf::Keyboard::G) {
                    som->playSound(4);
                }
                else if(event.key.code == sf::Keyboard::H) {
                    som->playSound(5);
                }
                else if(event.key.code == sf::Keyboard::R) {
                    som->playSound(6);
                }
                else if(event.key.code == sf::Keyboard::T) {
                    som->playSound(7);
                }
                else if(event.key.code == sf::Keyboard::Y) {
                    som->playSound(8);
                }

        }

        window.clear();

        //atualiza o display
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                window.draw(display.matrix[i][j]);
            }
        }

        //atualiza o audio

        window.display();
    }

    return 0;
}


//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && sfml-app.exe