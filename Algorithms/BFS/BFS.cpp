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

	Graph graph(15);
	graph.isDirected = false;
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(1, 4);
	graph.addEdge(2, 5);
	graph.addEdge(2, 6);
	graph.addEdge(5, 9);
	graph.addEdge(5, 10);
	graph.addEdge(4, 7);
	graph.addEdge(4, 8);
	graph.addEdge(7, 11);
	graph.addEdge(7, 12);

	BFS(graph, 7);

	return 0;
}

