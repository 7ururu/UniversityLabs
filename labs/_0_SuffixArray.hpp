#ifndef _0_SUFFIX_ARRAY_HPP
#define _0_SUFFIX_ARRAY_HPP

#include "../problem.hpp"

#include <iostream>
#include <vector>

namespace _0_
{

std::string s;

class _0_SuffixArray : Problem
{
public:
	_0_SuffixArray() : Problem("")
	{
		std::cin >> s;
	}

	int solve()
	{
		std::vector < int > suffArray = buildSuffixArray(s);
		for (int i = 0; i < s.size(); i++)
			printf("%i ", suffArray[i]);
		return 0;
	}
private:
	std::vector < int > buildSuffixArray(const std::string& s)
	{

	}
};

}
#endif