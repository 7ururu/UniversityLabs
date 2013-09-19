#ifndef _7_PREFFIX_FUNCTION_HPP
#define _7_PREFFIX_FUNCTION_HPP

#include "../problem.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace _7_
{	

std::string s;

class PreffixFunction : Problem
{
public:
	PreffixFunction() : Problem("")
	{
		std::cin >> s;
	}

	int solve()
	{
		std::vector < int > ans = calculate(s);
		for (int i = 0; i < (int)ans.size(); i++)
			printf("%i ", ans[i]);
		return 0;
	}
private:
	std::vector < int > calculate(const std::string& s)
	{
		std::vector < int > pi(s.size(), 0);
		for (int i = 1; i < (int)s.size(); i++)
		{
			int j = pi[i - 1];
			while (j > 0 && s[i] != s[j])
				j = pi[j - 1];

			if (s[i] == s[j])
				j++;
			pi[i] = j;
		}
		return pi;
	}
};

}
#endif