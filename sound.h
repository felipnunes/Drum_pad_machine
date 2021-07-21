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
        if (is_pressed[0] == false) {
            som->playSound(6);
            drum_pad->pressed_color(0,0);
            this->is_pressed[0] = true;
        }
    }
        else {
            drum_pad->reset_matrix(0,0);
            this->is_pressed[0] = false;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        if (is_pressed[1] == false) {
            som->playSound(7);
            drum_pad->pressed_color(1,0);
            this->is_pressed[1] = true;
        }
    }
        else {
            drum_pad->reset_matrix(1,0);
            this->is_pressed[1] = false;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        if (is_pressed[2] == false) {
            som->playSound(8);
            drum_pad->pressed_color(2,0);
            this->is_pressed[2] = true;
        }
    }
        else {
            drum_pad->reset_matrix(2,0);
            this->is_pressed[2] = false;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
        if (is_pressed[3] == false) {
            som->playSound(3);
            drum_pad->pressed_color(0,1);
            this->is_pressed[3] = true;
        }
    }
        else {
            drum_pad->reset_matrix(0,1);
            this->is_pressed[3] = false;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
        if (is_pressed[4] == false) {
            som->playSound(4);
            drum_pad->pressed_color(1,1);
            this->is_pressed[4] = true;
        }
    }
        else {
            drum_pad->reset_matrix(1,1);
            this->is_pressed[4] = false;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
        if (is_pressed[5] == false) {
            som->playSound(5);
            drum_pad->pressed_color(2,1);
            this->is_pressed[5] = true;
        }
    }
        else {
            drum_pad->reset_matrix(2,1);
            this->is_pressed[5] = false;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
        if (is_pressed[6] == false) {
            som->playSound(0);
            drum_pad->pressed_color(0,2);
            this->is_pressed[6] = true;
        }
    }
        else {
            drum_pad->reset_matrix(0,2);
            this->is_pressed[6] = false;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        if (is_pressed[7] == false) {
            som->playSound(1);
            drum_pad->pressed_color(1,2);
            this->is_pressed[7] = true;
        }
    }
        else {
            drum_pad->reset_matrix(1,2);
            this->is_pressed[7] = false;
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
        if (is_pressed[8] == false) {
            som->playSound(2);
            drum_pad->pressed_color(2,2);
            this->is_pressed[8] = true;
        }
    }
        else {
            drum_pad->reset_matrix(2,2);
            this->is_pressed[8] = false;
        }
}