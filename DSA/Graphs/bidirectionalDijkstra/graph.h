#pragma once

#include <vector>
#include <fstream>
#include <queue>
#include <limits>
using namespace std;

struct Edge {
	int destination;
	int weight;
	Edge(int dest, int w);
};

class Graph
{
private:
	int numV;
	vector<vector<Edge>> adjList;
	int** adjMatrix = new int* [numV];
	vector<vector<Edge>> reversedList;
public:
	Graph(int verticles);
	~Graph();

	void addEdge(int, int, int);
	void removeEdge(int, int);
	void reverse();
	void printGraphL();
	void toMatrix();
	void printGraphM();
	int bidirectionalDijkstra(int, int);

private:
	int dijkstra(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>&,
		vector<int>&,
		const vector<int>& otherDist, vector<vector<Edge>> );
};
