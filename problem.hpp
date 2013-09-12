#ifndef PROBLEM_HPP
#define PROBLEM_HPP

#include <string>

class Problem
{
public:
	Problem(const std::string& name)
	{
		if (name.empty())
		{
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
		else
		{
			freopen((name + ".in").c_str(), "r", stdin);
			freopen((name + ".out").c_str(), "w", stdout);
		}
	}

	virtual ~Problem()
	{

	}
};

#endif