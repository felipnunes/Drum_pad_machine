#include<SFML/Graphics.hpp>
#include<iostream>
const float square_side = 50.0;
const int matrix_lenght = 3;
//const int positionX = ;
class display {
    public:
    sf::Color original_color[3];
    sf::Sprite matrix[matrix_lenght][matrix_lenght];
    sf::Texture texture[3];
    display(int screenSise);
    void pressed_color(int x, int y);
    void reset_matrix();
};

display::display(int screenSise) {
    //carrega texturas
    texture[0].loadFromFile("drum_pad1.jpg");
    texture[1].loadFromFile("drum_pad2.jpg");
    texture[2].loadFromFile("drum_pad3.jpg");

    
    for(int i = 0; i < 3; i++) {
        texture[i].setSmooth(true);
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

    for(int i = 0; i < 3; i++) {
        original_color[i] = matrix[i][i].getColor();
    }
}

void display::pressed_color(int x, int y) {
    this->matrix[x][y].setColor(sf::Color(130,33,25));
}

void display::reset_matrix() {
    for(int i = 0; i < matrix_lenght; i++ ) {
        for(int j = 0; j < matrix_lenght; j++) {

            if(j = 0)
            matrix[i][j].setColor(original_color[1]);
            if(j = 1)
            matrix[i][j].setColor(original_color[1]);
            if(j = 2)
            matrix[i][j].setColor(original_color[2]);
        }
    }
}
