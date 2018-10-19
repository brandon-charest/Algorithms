
#include <queue>
#include <iostream>
#include <vector>

struct Graph
{
	Graph(int size) : nodes(size)
	{
		adj.resize(size);		
	}

	void addEdge(int const source, int const destination)
	{
		adj[source].push_back(destination);
		if (!isDirected)
		{
			adj[destination].push_back(source);
		}
	}
	bool isDirected;
	std::vector<std::vector<int>> adj;
	int nodes;
};



void BFS(Graph const graph, int vertex)
{
	
	std::vector<uint8_t> visited(graph.nodes, 0);
	std::queue<int> q;

	q.push(vertex);	
	visited[vertex] = 1;

	while (!q.empty())
	{
		vertex = q.front();
		std::cout << vertex << " ";
		q.pop();		

		for (auto it = graph.adj[vertex].begin(); it != graph.adj[vertex].end(); it++)
		{
			if (visited[*it] != 1)
			{
				visited[*it] = 1;
				q.push(*it);
			}
		}
	}
}


int main()
{

	Graph graph(10);
	graph.isDirected = false;
	graph.addEdge(1, 0);
	graph.addEdge(0, 2);
	graph.addEdge(2, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 4);

	BFS(graph, 0);

	return 0;
}

