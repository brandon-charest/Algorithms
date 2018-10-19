#include "Graph.h"
#include <queue>
#include <iostream>
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
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	graph.addEdge(0, 4);
	graph.addEdge(1, 5);
	graph.addEdge(2, 5);
	graph.addEdge(3, 6);
	graph.addEdge(4, 6);
	graph.addEdge(5, 7);
	graph.addEdge(6, 7);

	BFS(graph, 0);

	return 0;
}

