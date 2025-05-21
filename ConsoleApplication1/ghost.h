#pragma once
#include "Graph.h"
#include <SFML/Graphics.hpp>
#include"pacman.h"
#include "Food.h"

using namespace sf;

class ghost
{
public:
<<<<<<< Updated upstream
    ghost();

    void movement(pacman& pac ,Graph& g);
=======
    ghost(int x,int y, string photo);
    void setVulnerable();
    void movement(pacman& pac, Graph& g,int level);
>>>>>>> Stashed changes
    void draw(RenderWindow& window);
    bool checkCollision(pacman& pac);
    int i, j;
    Sprite ghostSprite;
    int moveCounter;
    vector<int> path;

    int countRemainingFood(const vector<unique_ptr<Food>>& foodList);
    bool isStuck() const;
    int lastVisitedNode;
    int stationaryCounter;

public:
    int status;
    Texture ghostTex;
    int frame;
    float speed;
    Graph g;
     

};