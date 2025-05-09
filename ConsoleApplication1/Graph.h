#include <SFML/Graphics.hpp>
#include<Bits.h>
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
	static vector<vector<int>> pacmanMatrix;




	static Node ConstructNode(int i, int j, int nodeSize);

	static unordered_map<int, vector<int>> constructGraph(std::vector<std::vector<int>>& pacmanMatrix, int nodeSize = 90);\

	static vector<int> bfs(int start, int target);

	static vector<int> ReconstructPath(std::vector<int>& parent, int start, int target);

};


