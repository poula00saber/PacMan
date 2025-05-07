#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
#include "Graph.h"
using namespace std;

class Graph
{
public:
	struct Node {
		int XstartPoint, YstartPoint, XendPoint, YendPoint,Xcenter,Ycenter;
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


	
	Node ConstructNode(int i, int j, int nodeSize) {
		Node node;
		node.x = i;
		node.y = j;
		node.XstartPoint = j * nodeSize;
		node.YstartPoint = i * nodeSize;
		node.XendPoint = node.XstartPoint + nodeSize - 1;
		node.YendPoint = node.YstartPoint + nodeSize - 1;
		node.Xcenter = node.XstartPoint + (nodeSize / 2);
		node.Ycenter = node.YstartPoint + (nodeSize / 2);
		return node;
	}

	unordered_map<int, vector<int>> constructGraph(vector<vector<int>>& pacmanMatrix, int nodeSize = 90) {
		unordered_map<int, vector<int>> graph;
		int row = pacmanMatrix.size();
		int col = pacmanMatrix[0].size();
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (pacmanMatrix[i][j] != 0)
				{
					vector <int>v;
					if ((i - 1 >= 0 && pacmanMatrix[i - 1][j])) { // up
						int x = i * col + j;
						v.push_back(x);
					}
					if ((i + 1 < row && pacmanMatrix[i + 1][j])) {// down
						int x = (col * (i + 1)) + j;
						v.push_back(x);
					}
					if ((j - 1 >= 0 && pacmanMatrix[i][j - 1])) {// left 
						int x = (col * (i)) + j - 1;
						v.push_back(x);
					}

					if ((j + 1 < col && pacmanMatrix[i][j + 1])) {// right
						int x = (col * (i)) + j + 1;
						v.push_back(x);
					}
					if (v.size())
					{
						int nodeId = (col * i) + j;
						graph[nodeId] = v;
						nodesInfo[nodeId] = ConstructNode(i, j, nodeSize);

					}
				}
			}


		}
		return graph;
	}



	static vector <int>  bfs(unordered_map<int, vector<int>>& graph, int start, int target) {
		queue<int> q;
		vector<bool> visited(graph.size() + 5, false);
		vector<int> parent(graph.size() + 5, -1);
		q.push(start);
		visited[start] = true;
		while (q.size())
		{
			int front = q.front();
			q.pop();
			for (int child : graph[front]) {
				if (!visited[child])
				{
					visited[child] = 1;
					parent[child] = front;
					q.push(child);
				}
			}
		}
		vector <int> path = ReconstructPath(parent, start, target);
		cout << graph.size() << endl;
		return path;
	}
	vector <int> static ReconstructPath(vector <int>& parent, int start, int target) {
		vector <int> path;
		int current = target;
		while (current != -1)
		{
			path.push_back(current);
			current = parent[current];
		}
		reverse(path.begin(), path.end());
		return path;
	}
};


