#include <vector>
#include <iostream>
#include <stack>

struct Graph
{
	Graph(int size) : nodes(size)
	{
		adj.resize(size);	
		visited = std::vector<uint8_t>(size, 0);
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
	int nodes;
	std::vector<std::vector<int>> adj;	
	std::vector<uint8_t> visited;
};


void DFS(Graph graph, int source)
{
	std::stack<int> stack;

	stack.push(source);

	while (!stack.empty())
	{
		source = stack.top();
		stack.pop();

		if (graph.visited[source] != 1)
		{
			std::cout << source << " ";		
			graph.visited[source] = 1;
		}

		for (auto it = graph.adj[source].begin(); it != graph.adj[source].end(); it++)
		{
			if (graph.visited[*it] != 1)
			{			
				stack.push(*it);
			}
		}
	}
}

int main()
{

	Graph graph(5);
	graph.isDirected = false;
	graph.addEdge(1, 0);
	graph.addEdge(0, 2);
	graph.addEdge(2, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 4);

	DFS(graph, 0);

	return 0;
}

