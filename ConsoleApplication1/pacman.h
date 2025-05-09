#pragma once
#include <SFML/Graphics.hpp>
#include "Graph.h"

using namespace sf;

class pacman {
public:
    pacman();

    void movement();
    void draw(RenderWindow& window);
    Vector2i getGridPosition();
    bool canMove(Vector2i dir);
    void updateAnimation();
    void handleInput();

public:
    int status;
    Texture pactexture;
    Sprite pacsprite;
    int frame;
    float speed;
    Vector2i direction;
    Clock animationClock;
    float animationSpeed;


    Graph g;
};