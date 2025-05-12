#pragma once
#include <SFML/Graphics.hpp>
#include "Graph.h"

using namespace sf;

class pacman {
public:
    pacman();

    void movement();
    void draw(RenderWindow& window);
    int i, j;
    Sprite pacsprite;

public:
    int status;
    Texture pactexture;
    int frame;
    float speed;
    int restframe;
    Graph g;
};