#include "pacman.h"
#include <SFML/Window/Keyboard.hpp>

pacman::pacman() {
    pactexture.loadFromFile("Assets/images/PacMan32.png");
    pacsprite.setTexture(pactexture);
    pacsprite.setTextureRect(IntRect(4 * 16, 0, 16, 16));
    pacsprite.setScale(3, 3);
    pacsprite.setPosition(g.NODESIZE, g.NODESIZE);
    frame = 0;
    speed = 0.1f;
    status = -1;
    restframe = 0;
}
void pacman::movement() {
    Vector2f pos = pacsprite.getPosition();
    i = static_cast<int>(pos.y) / g.NODESIZE;
    j = static_cast<int>(pos.x) / g.NODESIZE;

    if (j == 0 && status == 1 && g.pacmanMatrix[i][Graph::COLS - 1] != 0) {
        pacsprite.setPosition(Graph::nodesInfo[i * Graph::COLS + Graph::COLS - 1].XstartPoint, pacsprite.getPosition().y);
        j = Graph::COLS - 1;
    }
    else if (j == Graph::COLS - 1 && status == 0 && g.pacmanMatrix[i][0] != 0) {
        pacsprite.setPosition(Graph::nodesInfo[i * Graph::COLS].XendPoint, pacsprite.getPosition().y);
        j = 0;
    }

    if (i == 0 && status == 2 && g.pacmanMatrix[Graph::ROWS - 1][j] != 0) {
        pacsprite.setPosition(pacsprite.getPosition().x, Graph::nodesInfo[(Graph::ROWS - 1) * Graph::COLS + j].YendPoint);
        i = Graph::ROWS - 1;
    }
    else if (i == Graph::ROWS - 1 && status == 3 && g.pacmanMatrix[0][j] != 0) {
        pacsprite.setPosition(pacsprite.getPosition().x, Graph::nodesInfo[j].YstartPoint);
        i = 0;
    }

    // Handle keyboard input to change direction
    if (Keyboard::isKeyPressed(Keyboard::Right) && g.pacmanMatrix[i][j + 1] != 0) {

        status = 0;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left) && g.pacmanMatrix[i][j - 1] != 0) {
        status = 1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Up) && g.pacmanMatrix[i - 1][j] != 0) {
        status = 2;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down) && g.pacmanMatrix[i + 1][j] != 0) {
        status = 3;
    }



    if (status == 0 && (g.pacmanMatrix[i][j + 1] != 0 || (pacsprite.getPosition().x <= Graph::nodesInfo[i * Graph::COLS + j].Xcenter && g.pacmanMatrix[i][j] != 0))) {  // Right
        frame++;
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 0, 16, 16));
        pacsprite.move(speed, 0);
        restframe = 0;
    }
    else if (status == 1 && (g.pacmanMatrix[i][j - 1] != 0 || (pacsprite.getPosition().x >= Graph::nodesInfo[i * Graph::COLS + j].Xcenter && g.pacmanMatrix[i][j] != 0))) {  // Left
        frame++;
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 2 * 16, 16, 16));
        pacsprite.move(-speed, 0);
        restframe = 2;
    }
    else if (status == 2 && (g.pacmanMatrix[i - 1][j] != 0 || (pacsprite.getPosition().y >= Graph::nodesInfo[i * Graph::COLS + j].Ycenter && g.pacmanMatrix[i][j] != 0))) {  // Up
        frame++;
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 16, 16, 16));
        pacsprite.move(0, -speed);
        restframe = 1;
    }
    else if (status == 3 && (g.pacmanMatrix[i + 1][j] != 0 || (pacsprite.getPosition().y <= Graph::nodesInfo[i * Graph::COLS + j].Ycenter && g.pacmanMatrix[i][j] != 0))) {  // Down
        frame++;
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 3 * 16, 16, 16));
        pacsprite.move(0, speed);
        restframe = 3;
    }
    else {
        pacsprite.setTextureRect(IntRect(4 * 16, restframe * 16, 16, 16));
        status = -1;
    }

}
void pacman::draw(RenderWindow& window) {
    window.draw(pacsprite);
}

