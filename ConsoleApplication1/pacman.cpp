#include "pacman.h"
#include <SFML/Window/Keyboard.hpp>

pacman::pacman() {
    pactexture.loadFromFile("Assets/images/PacMan32.png");
    pacsprite.setTexture(pactexture);
    pacsprite.setTextureRect(IntRect(4 * 16, 0, 16, 16));
    pacsprite.setScale(3, 3);
    pacsprite.setPosition(Graph::NODESIZE, Graph::NODESIZE);
    frame = 0;
    speed = 0.1f;
    status = -1;
}
void pacman::movement() {
    Vector2f pos = pacsprite.getPosition();
    i = static_cast<int>(pos.y) / Graph::NODESIZE;
    j = static_cast<int>(pos.x) / Graph::NODESIZE;

    // Handle keyboard input to change direction
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        status = 0;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left)) {
        status = 1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Up)) {
        status = 2;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        status = 3;
    }


    if (status == 0 && (Graph::pacmanMatrix[i][j + 1] != 0 || (pacsprite.getPosition().x <=g.nodesInfo[i * Graph::COLS + j].Xcenter && Graph::pacmanMatrix[i][j] != 0))) {  // Right
        frame++;
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 0, 16, 16));
        pacsprite.move(speed, 0);
    }
    else if (status == 1 && (Graph::pacmanMatrix[i][j - 1] != 0 || (pacsprite.getPosition().x >= g.nodesInfo[i * Graph::COLS + j].Xcenter && Graph::pacmanMatrix[i][j] != 0))) {  // Left
        frame++;
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 2 * 16, 16, 16));
        pacsprite.move(-speed, 0);
    }
    else if (status == 2 && (Graph::pacmanMatrix[i - 1][j] != 0 || (pacsprite.getPosition().y >= g.nodesInfo[i * Graph::COLS + j].Ycenter && Graph::pacmanMatrix[i][j] != 0))) {  // Up
        frame++;
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 16, 16, 16));
        pacsprite.move(0, -speed);
    }
    else if (status == 3 && (Graph::pacmanMatrix[i + 1][j] != 0 || (pacsprite.getPosition().y <= g.nodesInfo[i * Graph::COLS + j].Ycenter && Graph::pacmanMatrix[i][j] != 0))) {  // Down
        frame++;
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 3 * 16, 16, 16));
        pacsprite.move(0, speed);
    }
    else {
        status = -1;
        pacsprite.setTextureRect(IntRect(4 * 16, 0, 16, 16));
    }

}
void pacman::draw(RenderWindow& window) {
    window.draw(pacsprite);
}