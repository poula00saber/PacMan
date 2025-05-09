#include "pacman.h"
#include <SFML/Window/Keyboard.hpp>

pacman::pacman() {
    pactexture.loadFromFile("PacMan16.png");
    pacsprite.setTexture(pactexture);
    pacsprite.setTextureRect(IntRect(0, 0, 16, 16));
    pacsprite.setScale(3, 3);
    pacsprite.setPosition(90, 90); // »œ«Ì… „‰ √Ê· Œ«‰…
    frame = 0;
    speed = 0.07f;
    animationSpeed = 0.1f;
    status = -1;
}
void pacman::movement() {
    Vector2f pos = pacsprite.getPosition();
    int i = static_cast<int>(pos.y) / 90;
    int j = static_cast<int>(pos.x) / 90;

    // Handle keyboard input to change direction
    if (Keyboard::isKeyPressed(Keyboard::D) && g.pacmanMatrix[i][j + 1] != 0) {
        status = 0;
    }
    else if (Keyboard::isKeyPressed(Keyboard::A) && g.pacmanMatrix[i][j - 1] != 0) {
        status = 1;
    }
    else if (Keyboard::isKeyPressed(Keyboard::W) && g.pacmanMatrix[i - 1][j] != 0) {
        status = 2;
    }
    else if (Keyboard::isKeyPressed(Keyboard::S) && g.pacmanMatrix[i + 1][j] != 0) {
        status = 3;
    }

    if (status == 0 && g.pacmanMatrix[i][j + 1] != 0) {  // Right
        frame = 0;
        /* direction = {1, 0}; */
            pacsprite.setTextureRect(IntRect((frame % 5) * 16, 0, 16, 16));
        pacsprite.move(speed, 0);
    }
    else if (status == 1 && g.pacmanMatrix[i][j - 1] != 0) {  // Left
        frame = 1;
        /* direction = { -1, 0 };*/
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 0, 16, 16));
        pacsprite.move(-speed, 0);
    }
    else if (status == 2 && g.pacmanMatrix[i - 1][j] != 0) {  // Up
        frame = 2;
        direction = { 0, -1 };
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 0, 16, 16));
        pacsprite.move(0, -speed);
    }
    else if (status == 3 && g.pacmanMatrix[i + 1][j] != 0) {  // Down
        frame = 3;
        direction = { 0, 1 };
        pacsprite.setTextureRect(IntRect((frame % 5) * 16, 0, 16, 16));
        pacsprite.move(0, speed);
    }

}
void pacman::draw(RenderWindow& window) {
    window.draw(pacsprite);
}
//
//Vector2i pacman::getGridPosition() {
//    return Vector2i(pacsprite.getPosition().x / 32, pacsprite.getPosition().y / 32);
//}
//
//bool pacman::canMove(Vector2i dir) {
//    Vector2i gridPos = getGridPosition();
//    return g.pacmanMatrix[gridPos.y + dir.y][gridPos.x + dir.x] != 0;
//}
//
//
//
//void pacman::handleInput() {
//    // ·· Ê”⁄… ·«Õﬁ« ≈–« √—œ   ›’· «·≈œŒ«· ⁄‰ «·Õ—ﬂ…
//}