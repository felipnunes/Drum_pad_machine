#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>



int const qtd_audios = 9;
int const qtd_presets = 1;

class sound {
    public:
    sf::SoundBuffer buffer;
    sf::SoundBuffer samples_base[qtd_audios][qtd_presets];
    sf::Sound preset_data_base[qtd_audios][qtd_presets];
    sf::Sound actual_preset[qtd_audios];
    void setActualPreset(int preset_code);
    void playSound(int sound_code);
    sound();
};

sound::sound() {

    //carrega os arquivos
    samples_base[0][0].loadFromFile("kick1.wav");
    samples_base[1][0].loadFromFile("hihat1.wav");
    samples_base[2][0].loadFromFile("clap1.wav");
    samples_base[3][0].loadFromFile("open_hihat1.wav");
    samples_base[4][0].loadFromFile("TOM 1.wav");
    samples_base[5][0].loadFromFile("TOM 2.wav");
    samples_base[6][0].loadFromFile("TOM 3.wav");
    samples_base[7][0].loadFromFile("snare1.wav");
    samples_base[8][0].loadFromFile("open_hihat1_2.wav");

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

