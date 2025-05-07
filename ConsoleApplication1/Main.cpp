#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iomanip>
#include "Graph.cpp"
using namespace std;
using namespace sf;

unordered_map<int, vector<int>> Graph::graph;
unordered_map<int, Graph::Node> Graph::nodesInfo;
sf::RenderWindow window(sf::VideoMode(1680, 1050), "SFML works!");
sf::CircleShape shape(100.f);
void Update();
void Start();
void Draw();
float deltaTime;
int main()
{
   
	Graph g;
	int row = g.pacmanMatrix.size();
	int col = g.pacmanMatrix[0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
            int x = i * col + j;
            if (x<10)
            {
			cout <<x << "   ";
            continue;
            }
			if (x < 100)
			{
				cout << x << "  ";
				continue;
			}
			if (x < 1000)
			{
				cout << x << " ";
				continue;
			}


		}
		cout << endl;
	}
	cout << endl;
	cout << endl;



	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int x = g.pacmanMatrix[i][j];
			if (x < 10)
			{
				cout << x << "   ";
				continue;
			}
			if (x < 100)
			{
				cout << x << "  ";
				continue;
			}
			if (x < 1000)
			{
				cout << x << " ";
				continue;
			}


		}
		cout << endl;
	}



		g.graph = g.constructGraph(g.pacmanMatrix, 90);

	vector<int> path = g.bfs(22, 25);

	cout << path.size() << endl << endl << endl << endl;
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i] << " ";
	}

    Start();
    Clock clock;
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Update();
        Draw();
    }
    return 0;
}
void Start()
{
    // code here is only executed at the start of the program

    shape.setFillColor(sf::Color::Green);
}
void Update()
{
    // code here is executed every frame since the start of the program

}
void Draw()
{
    // code here is executed every frame since the start of the program

    window.clear(); //clear every pixel on the screen

    //Draw your sprites here

    window.draw(shape);

    
    window.display(); //Display sprites on screen
}
