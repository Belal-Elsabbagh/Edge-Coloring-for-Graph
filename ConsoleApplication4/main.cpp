#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	int n, e;

	cout << "Enter number of vertices and edges respectively:";
	cin >> n >> e;

	cout << "\n";
	Graph g(n, e);

	for (int i = 0; i < e; i++)
	{
		int v1, v2;
		cout << "\nEnter edge vertices of edge " << i + 1 << " :";
		cin >> v1 >> v2;
		v1--; v2--;
		g.graph[v1].push_back(make_pair(v2, i));
		g.graph[v2].push_back(make_pair(v1, i));
	}

	g.colour(0);
	g.display(cout);
}