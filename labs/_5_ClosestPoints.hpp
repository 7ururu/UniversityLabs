#ifndef _5_CLOSEST_POINTS
#define _5_CLOSEST_POINTS

#include "../problem.hpp"

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

namespace _5_
{

struct Point
{
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	double x, y;

	static bool xCmp(const Point& a, const Point& b)
	{
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	}

	static bool yCmp(const Point& a, const Point& b)
	{
		return a.y < b.y || (a.y == b.y && a.x < b.x);
	}

	double distanceTo(const Point& other) const
	{
		return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}
};

const int N = 1000000;
int n;
Point p[N];
int L[N], 
	R[N];

class ClosestPoints : Problem
{
public:
	ClosestPoints() : Problem("")
	{
		scanf("%i", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		memset(L, -1, sizeof(int) * n);
		memset(R, -1, sizeof(int) * n);
	}

	int solve()
	{
		int root = build2dTree(0, n - 1, true);
		double ans = 1e18;
		for (int i = 0; i < n; i++)
			minDistance(root, p[i], true, ans);
		printf("%.3lf", ans);
		return 0;
	}
private:
	int build2dTree(int l, int r, bool xSpliting)
	{
		if (l == r)
			return l;
		int m = (l + r) / 2;
		std::nth_element(p + l, p + m, p + r + 1, (xSpliting ? Point::xCmp : Point::yCmp));
		if (m - 1 - l >= 0)
			L[m] = build2dTree(l, m - 1, !xSpliting);
		if (r - m - 1 >= 0)
			R[m] = build2dTree(m + 1, r, !xSpliting);
		return m;
	}

	void minDistance(int v, const Point& point, bool xSpliting, double& result)
	{
		if (v == -1)
			return;
		if (p[v].x != point.x || p[v].y != point.y)
			result = std::min(result, point.distanceTo(p[v]));
		if (xSpliting)
		{
			if (point.x < p[v].x)
			{
				minDistance(L[v], point, !xSpliting, result);
				if (p[v].x - point.x <= result)
					minDistance(R[v], point, !xSpliting, result);
			}
			else
			{
				minDistance(R[v], point, !xSpliting, result);
				if (point.x - p[v].x <= result)
					minDistance(L[v], point, !xSpliting, result);
			}
		}
		else
		{
			if (point.y < p[v].y)
			{
				minDistance(L[v], point, !xSpliting, result);
				if (p[v].y - point.y <= result)
					minDistance(R[v], point, !xSpliting, result);
			}
			else
			{
				minDistance(R[v], point, !xSpliting, result);
				if (point.y - p[v].y <= result)
					minDistance(L[v], point, !xSpliting, result);
			}
		}
	}
};

}
#endif