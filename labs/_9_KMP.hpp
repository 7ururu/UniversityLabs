#ifndef _9_KMP_HPP
#define _9_KMP_HPP

#include "../problem.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace _9_
{	

std::string a, x;

class KMP : Problem
{
public:
	KMP() : Problem("")
	{
		std::cin >> x >> a;
	}

	int solve()
	{
		std::vector < int > pi = calculatePreffixFunction(x + "#" + a);
		bool flag = false;
		for (int i = 0; i < (int)pi.size() && !flag; i++)
			if (pi[i] == x.size())
			{
				std::cout << i - 2 * x.size() + 1;
				flag = true;
			}
		if (!flag)
			std::cout << -1;
		return 0;
	}
private:
	std::vector < int > calculatePreffixFunction(const std::string& s)
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