#pragma once
#include "Graph.h"
#include "TileMap.h"
class Map_Level
{
private:
	Graph g;
	TileMap map;

public:
	Map_Level();
	~Map_Level();
	void drawMap(sf::RenderWindow&);

};

