#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "display.h" 
#include "sound.h"

int const screenSise = 500;
int main()
{
    sf::RenderWindow window(sf::VideoMode(screenSise, screenSise), "DPM");
    display *drum_pad = new display(screenSise);
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

        //atualiza o drum_pad
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                window.draw(drum_pad->matrix[i][j]);
            }
            window.draw(drum_pad->icons_sprite[i]);
        }



        //atualiza o audio

        som->comands(som, drum_pad);





        window.display();

    }
    return 0;
}


//g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio && sfml-app.exe