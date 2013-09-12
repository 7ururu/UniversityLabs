#ifndef _3_BFS01_HPP
#define _3_BFS01_HPP

#include "../problem.hpp"

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

namespace _3_
{	

const int MAX_EDGE_COST = 2;
const int N = 100000;
const int INFINITY = 1000 * 1000 * 1000;

struct Edge
{
	Edge(int to = -1, int cost = 0) : to(to), cost(cost) {}
	int to,
		cost;
};

int n, m;
std::vector < Edge > edges[N];
std::queue < int > q[MAX_EDGE_COST];
int dist[N];

int findFrom,
	findTo;

class BFS01 : Problem
{
public:
	BFS01() : Problem("")
	{
		scanf("%i%i", &n, &m);
		for (int i = 0; i < m; i++)
		{
			int u, v, cost;
			scanf("%i%i%i", &u, &v, &cost);
			u--;	v--;
			edges[u].push_back(Edge(v, cost));
			edges[v].push_back(Edge(u, cost));
		}
		findFrom = 0;
		findTo = n - 1;
	}

	int solve()
	{
		for (int i = 0; i < n; i++)
			dist[i] = i == findFrom ? 0 : INFINITY;
		q[0].push(findFrom);

		while (true)
		{
			int v;
			bool empty = true;
			for (int i = 0; i < MAX_EDGE_COST && empty; i++)
				if (!q[i].empty())
				{
					v = q[i].front();
					q[i].pop();
					empty = false;
				}
			if (empty)
				break;
			for (int i = 0; i < edges[v].size(); i++)
			{
				Edge e = edges[v][i];
				if (dist[e.to] > dist[v] + e.cost)
				{
					dist[e.to] = dist[v] + e.cost;
					q[e.cost].push(e.to);
				}
			}
		}

		printf("%i", dist[findTo]);

		return 0;
	}
};

}

#endif