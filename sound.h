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
    void comands(sound *som, display *drum_pad, int *frame);
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

void sound::comands(sound *som, display *drum_pad, int *frame) {
    //comandos do drumpad
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        if (*frame == 0) {
            som->playSound(6);
            drum_pad->pressed_color(0,0);
            *frame = 1;
        }
    }
        else {
            drum_pad->reset_matrix(0,0);
            is_pressed[0] = false;
            *frame = 0;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        som->playSound(7);
        drum_pad->pressed_color(1,0);
    }
        else {
            drum_pad->reset_matrix(1,0);
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        som->playSound(8);
        drum_pad->pressed_color(2,0);
    }
        else {
            drum_pad->reset_matrix(2,0);
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        som->playSound(3);
        drum_pad->pressed_color(0,1);
    }
        else {
            drum_pad->reset_matrix(0,1);
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
        som->playSound(4);
        drum_pad->pressed_color(1,1);
    }
        else {
            drum_pad->reset_matrix(1,1);
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        som->playSound(5);
        drum_pad->pressed_color(2,1);
    }
        else {
            drum_pad->reset_matrix(2,1);
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
        som->playSound(0);
        drum_pad->pressed_color(0,2);
    }
        else {
            drum_pad->reset_matrix(0,2);
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        som->playSound(1);
        drum_pad->pressed_color(1,2);
    }
        else {
            drum_pad->reset_matrix(1,2);
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
        som->playSound(2);
        drum_pad->pressed_color(2,2);
    }
        else {
            drum_pad->reset_matrix(2,2);
        }
}