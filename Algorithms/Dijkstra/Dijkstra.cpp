#include <vector>
#include <queue>
#include <functional>
#include <iostream>

typedef std::pair<int, int> pair;
typedef std::vector<std::vector<pair>> vvpair;

struct Graph
{
	Graph(int V)
	{
		vertices = V;
		adj.resize(V);
	}
	void addEdge(int const &source, int const dest, int const &weight)
	{
		adj[source].push_back({ dest, weight });
		adj[dest].push_back({ source, weight });
	}
	int vertices;
	vvpair adj;
};

void printFromSource(int const &verticies, std::vector<int> const &distance)
{
	std::cout << "Vertex" << "\t" << "Distance from Source" << "\n";
	for (int i = 0; i < verticies; i++)
	{
		std::cout << i << "\t" << distance[i] << "\n";
	}
}

void shortestPath(Graph graph, int src)
{
	std::priority_queue<pair, std::vector<pair>, std::greater<pair>> pQ;
	std::vector<int> distance(graph.vertices, INT_MAX);

	// source has a distance of 0
	distance[src] = 0;
	
	pQ.push({ 0,src });

	while (!pQ.empty())
	{
		int temp = pQ.top().second;
		pQ.pop();

		// get all vertex adjacent to temp
		for (auto const &x : graph.adj[temp])
		{
			int vertex = x.first;
			int weight = x.second;

			// if there is a shorter path to vertex through temp
			if (distance[vertex] > distance[temp] + weight)
			{
				// update vertex distance to newest shortest distance
				distance[vertex] = distance[temp] + weight;
				pQ.push({ distance[vertex], vertex });
			}
		}
	}
	printFromSource(graph.vertices, distance);
}


int main()
{
	Graph graph(9);
	
	graph.addEdge(0, 1, 4);
	graph.addEdge(0, 7, 8);
	graph.addEdge(1, 2, 8);
	graph.addEdge(1, 7, 11);
	graph.addEdge(2, 3, 7);
	graph.addEdge(2, 8, 2);
	graph.addEdge(2, 5, 4);
	graph.addEdge(3, 4, 9);
	graph.addEdge(3, 5, 14);
	graph.addEdge(4, 5, 10);
	graph.addEdge(5, 6, 2);
	graph.addEdge(6, 7, 1);
	graph.addEdge(6, 8, 6);
	graph.addEdge(7, 8, 7);

	shortestPath(graph,0);

	return 0;
}

