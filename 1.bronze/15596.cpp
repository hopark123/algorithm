#include <iostream>
#include <vector>

long long sum(std::vector<int> &a)
{
	long long res = 0;
	for (std::vector<int>::iterator it = a.begin(); it < a.end(); it++)
		res += *it;
	return (res);
}