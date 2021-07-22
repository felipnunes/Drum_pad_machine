#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>



int const qtd_audios = 9;
int const qtd_presets = 3;

class sound {
    public:
    int actual_preset_code;
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
    samples_base[0][0].loadFromFile("assets/audios/sample1/kick1.wav");
    samples_base[1][0].loadFromFile("assets/audios/sample1/hihat1.wav");
    samples_base[2][0].loadFromFile("assets/audios/sample1/clap1.wav");
    samples_base[3][0].loadFromFile("assets/audios/sample1/open_hihat1.wav");
    samples_base[4][0].loadFromFile("assets/audios/sample1/TOM 1.wav");
    samples_base[5][0].loadFromFile("assets/audios/sample1/TOM 2.wav");
    samples_base[6][0].loadFromFile("assets/audios/sample1/TOM 3.wav");
    samples_base[7][0].loadFromFile("assets/audios/sample1/snare1.wav");
    samples_base[8][0].loadFromFile("assets/audios/sample1/open_hihat1_2.wav");

    //sample_2

    samples_base[6][1].loadFromFile("assets/audios/sample2/zebrallete1.wav");
    samples_base[7][1].loadFromFile("assets/audios/sample2/zebrallete2.wav");
    samples_base[8][1].loadFromFile("assets/audios/sample2/zebrallete3.wav");
    samples_base[3][1].loadFromFile("assets/audios/sample2/solo1.wav");
    samples_base[4][1].loadFromFile("assets/audios/sample2/solo2.wav");
    samples_base[5][1].loadFromFile("assets/audios/sample2/solo3.wav");
    samples_base[0][1].loadFromFile("assets/audios/sample2/kick1.wav");
    samples_base[1][1].loadFromFile("assets/audios/sample2/hihat.wav");
    samples_base[2][1].loadFromFile("assets/audios/sample2/snare.wav");

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

    actual_preset_code = preset_code;
    for(int i = 0; i < qtd_audios; i++) {
        this->actual_preset[i].setBuffer(samples_base[i][preset_code]);
    }
}

void sound::playSound(int sound_code) {
    this->actual_preset[sound_code].play();
}

void sound::comands(sound *som, display *drum_pad) {
    //comandos para troca de samples

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
        som->setActualPreset(0);
        drum_pad->set_preset_number_color(actual_preset_code);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        som->setActualPreset(1);
        drum_pad->set_preset_number_color(actual_preset_code);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
        som->setActualPreset(2);
        drum_pad->set_preset_number_color(actual_preset_code);
    }

    

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