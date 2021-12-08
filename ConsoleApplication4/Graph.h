#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Graph
{
public:
	vector<int> color;
	vector<vector<pair<int, int>>> graph;
	bool vis[100011];
	
	Graph(int nVertices, int nEdges) 
		: graph(nVertices), color(nEdges, -1)
	{}

	void colour(int node)
	{
		queue<int> q;
		int c = 0;
		set<int> already_colored;
		
		if (vis[node])
			return;

		vis[node] = 1;


		for (int i = 0; i < graph[node].size(); i++)
		{
			if (color[graph[node][i].second] != -1)
			{
				already_colored.insert(color[graph[node][i].second]);
			}
		}

		for (int i = 0; i < graph[node].size(); i++)
		{
			if (!vis[graph[node][i].first])
			{
				q.push(graph[node][i].first);
			}
			if (color[graph[node][i].second] == -1)
			{
				while (already_colored.find(c) != already_colored.end())
					c++;
				//cout<<graph[node][i].second+1<<" "<<c<<"\n";
				color[graph[node][i].second] = c;
				already_colored.insert(c);
				c++;
			}
		}

		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			colour(temp);
		}
		return;
	}
	
	void display(ostream& out) const
	{
		for (int i = 0; i < color.size(); i++)
		{
			out << "Edge " << i + 1 << " is coloured " << color[i] + 1 << "\n";
		}
	}
};
  
