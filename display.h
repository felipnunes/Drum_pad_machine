#include <SFML/Graphics.hpp>
#include <iostream>
const float square_side = 50.0;
const int matrix_lenght = 3;
const int qtd_preset = 3;
class display {
    public:
    sf::Texture icons[qtd_preset];
    sf::Sprite icons_sprite[qtd_preset];
    sf::Color original_color;
    sf::Sprite matrix[matrix_lenght][matrix_lenght];
    sf::Texture texture[3];
    display(int screenSise);
    void pressed_color(int x, int y);
    void reset_matrix(int i, int j);
    void set_preset_number_color(int actual_preset_code);
};

display::display(int screenSise) {
    //carrega texturas

    //pad texture
    texture[0].loadFromFile("assets/images/drum_pad1.jpg");
    texture[1].loadFromFile("assets/images/drum_pad2.jpg");
    texture[2].loadFromFile("assets/images/drum_pad3.jpg");

    for(int i = 0; i < 3; i++) {
        texture[i].setSmooth(true);
    }
    //icon texture

    icons[0].loadFromFile("assets/images/1.png");
    icons[1].loadFromFile("assets/images/2.png");
    icons[2].loadFromFile("assets/images/3.png");
    
    for(int i = 0; i < qtd_preset; i++) {
        icons[i].setSmooth(true);
        icons_sprite[i].setTexture(icons[i]);
        icons_sprite[i].setPosition(sf::Vector2f(screenSise/3 + 10 + i * 60, screenSise/11 - 10));
    }



    
    //gera matriz de sprites
    for(int i = 0; i < matrix_lenght; i++ ) {
        for(int j = 0; j < matrix_lenght; j++) {

            if(j == 0)
                matrix[i][j].setTexture(texture[0]);
            if(j == 1)
                matrix[i][j].setTexture(texture[1]);
            if(j == 2)
                matrix[i][j].setTexture(texture[2]);

            
            matrix[i][j].setPosition(sf::Vector2f(screenSise/4 - 47 + i*120, screenSise/4 - 47 + j*120));
        }
    }

        original_color = matrix[0][0].getColor();
    
}

void display::pressed_color(int x, int y) {
    this->matrix[x][y].setColor(sf::Color(130,33,25));
}
void display:: set_preset_number_color(int actual_preset_code) {
    this->icons_sprite[actual_preset_code].setColor(sf::Color::Red);
    for(int i = 0; i < qtd_preset; i++) {
        if(i != actual_preset_code) {
            icons_sprite[i].setColor(sf::Color::White);
        }
    }
}


void display::reset_matrix(int i, int j) {
    
    matrix[i][j].setColor(original_color);
    
}
