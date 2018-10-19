#pragma once
#include <vector>
class Graph
{

public:	

	Graph(int size)
	{
		adj.resize(size);
		nodes = size;
	}

	void addEdge(int const source, int const destination);
	bool isDirected;
	std::vector<std::vector<int>> adj;
	int nodes;
};

