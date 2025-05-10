#pragma once
#include "Graph.h"
#include <SFML/Graphics.hpp>


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
    Graph g;


};