#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
using namespace std;

class Graph
{
public:
	struct Node {
		int XstartPoint, YstartPoint, XendPoint, YendPoint, Xcenter, Ycenter;
		int x, y;
	};
	Graph();
	static const int mapCells = 20;
	static unordered_map<int, vector<int>> graph;
	static unordered_map<int, Node>nodesInfo;
	vector<vector<int>> pacmanMatrix = {
	   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	   {0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0},
	   {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0},
	   {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0},
	   {0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0},
	   {0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0},
	   {0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0},
	   {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0},
	   {0,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,0},
	   {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
	   {0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0},
	   {0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0},
	   {0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0},
	   {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0},
	   {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0},
	   {0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0},
	   {0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0},
	   {0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0},
	   {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0},
	   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};



	static Node ConstructNode(int i, int j, int nodeSize);

	static unordered_map<int, vector<int>> constructGraph(std::vector<std::vector<int>>& pacmanMatrix, int nodeSize = 90);\

	static vector<int> bfs(int start, int target);

	static vector<int> ReconstructPath(std::vector<int>& parent, int start, int target);

};


