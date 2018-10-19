#include "Graph.h"

void Graph::addEdge(int const source, int const destination)
{
	
	adj[source].push_back(destination);
	if (!isDirected)
	{
		adj[destination].push_back(source);
	}
}
