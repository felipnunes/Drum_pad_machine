#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>



int const qtd_audios = 9;
int const qtd_presets = 1;

class sound {
    public:
    bool is_pressed[qtd_audios];
    sf::SoundBuffer buffer;
    sf::SoundBuffer samples_base[qtd_audios][qtd_presets];
    sf::Sound preset_data_base[qtd_audios][qtd_presets];
    sf::Sound actual_preset[qtd_audios];
    void setActualPreset(int preset_code);
    void playSound(int sound_code);
    void comands(sound *som, display *drum_pad);
    sound();
};

sound::sound() {

    //carrega os arquivos

    //sample_1
    samples_base[0][0].loadFromFile("kick1.wav");
    samples_base[1][0].loadFromFile("hihat1.wav");
    samples_base[2][0].loadFromFile("clap1.wav");
    samples_base[3][0].loadFromFile("open_hihat1.wav");
    samples_base[4][0].loadFromFile("TOM 1.wav");
    samples_base[5][0].loadFromFile("TOM 2.wav");
    samples_base[6][0].loadFromFile("TOM 3.wav");
    samples_base[7][0].loadFromFile("snare1.wav");
    samples_base[8][0].loadFromFile("open_hihat1_2.wav");

    //sample_2

    for(int i = 0; i < qtd_audios; i++) {
        //seta o standart
        actual_preset[i].setBuffer(samples_base[i][0]);
        for(int j = 0; j < qtd_presets; j++) {
            //seta todos a base de samples
            this->preset_data_base[i][j].setBuffer(samples_base[i][j]);
        }
    }
}

void sound::setActualPreset(int preset_code) {

    for(int i = 0; i < qtd_audios; i++) {
        this->actual_preset[i].setBuffer(samples_base[i][preset_code]);
    }

}

void sound::playSound(int sound_code) {
    this->actual_preset[sound_code].play();
}

void sound::comands(sound *som, display *drum_pad) {
    //comandos do drumpad
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        som->playSound(6);
        drum_pad->pressed_color(0,0);
        is_pressed[0] = true;
    }
        else {
            
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        som->playSound(7);
        drum_pad->pressed_color(1,0);
        is_pressed[1] = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        som->playSound(8);
        drum_pad->pressed_color(2,0);
        is_pressed[2] = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        som->playSound(3);
        drum_pad->pressed_color(0,1);
        is_pressed[3] = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
        som->playSound(4);
        drum_pad->pressed_color(1,1);
        is_pressed[4] = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        som->playSound(5);
        drum_pad->pressed_color(2,1);
        is_pressed[5] = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
        som->playSound(0);
        drum_pad->pressed_color(0,2);
        is_pressed[6] = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        som->playSound(1);
        drum_pad->pressed_color(1,2);
        is_pressed[7] = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
        som->playSound(2);
        drum_pad->pressed_color(2,2);
        is_pressed[8] = true;
    }
}

