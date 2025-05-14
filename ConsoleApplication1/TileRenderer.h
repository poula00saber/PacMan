#pragma once
#include <SFML/Graphics.hpp>
#include "Graph.h"
<<<<<<< HEAD
#include "pacman.h"
=======
#include "Food.h"

>>>>>>> df484b6ffb1d6458f126ea2e8cf430d76e25f1d6
using namespace std;
using namespace sf;
class TileRenderer {
public:
    TileRenderer( int tileSize,int level);
    void draw(RenderWindow& window);
    void checklevel(int value);
<<<<<<< HEAD
    int eating(pacman player);
    void draweating(RenderWindow& window, pacman player);
=======
    int eating();
    void generateFood();
    vector<unique_ptr<Food>>& getfoodList();
    void initializeFood();


>>>>>>> df484b6ffb1d6458f126ea2e8cf430d76e25f1d6
private:
    int tileSize;
    Texture texture0, texture1;
    Sprite sprite0, sprite1;
    std::vector<std::unique_ptr<Food>> foodList; 
};
