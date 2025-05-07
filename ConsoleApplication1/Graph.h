#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
using namespace std;
#pragma once
class Graph
{
public:
	struct Node {
		int XstartPoint, YstartPoint, XendPoint, YendPoint, Xcenter, Ycenter;
		int x, y;
	};


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


	static vector<int> bfs(unordered_map<int,vector<int>>& graph, int start, int target);
	static vector<int> ReconstructPath(vector<int>& parent, int start, int target);
	unordered_map<int,vector<int>> constructGraph(vector<vector<int>>& pacmanMatrix, int nodeSize = 90);
	Node ConstructNode(int i, int j, int nodeSize);



};

