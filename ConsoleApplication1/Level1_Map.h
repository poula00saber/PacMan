#pragma once
#include "Graph.h"
#include "TileMap.h"
class Level1_Map
{
private:
	Graph g;
	TileMap map;

public:
	Level1_Map();
	~Level1_Map();
	void drawMap(sf::RenderWindow&);

};

