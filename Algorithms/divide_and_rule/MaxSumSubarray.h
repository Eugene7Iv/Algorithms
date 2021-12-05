#pragma once
#include <vector>
#include <array>
#include <climits>
namespace MaxSumSubarray
{
	std::array<int, 3> bruteForce(const std::vector<int>& v)
	{
		int left = -1;
		int right = -1;
		int sum = INT_MIN;
		std::array<int, 3> res{left, right, sum};

		for (int i = 0; i < v.size(); i++)
		{
			int curSum = v[i];
			for (int j = i + 1; j < v.size(); j++)
			{
				curSum += v[j];
				if (curSum >= sum)
				{
					sum = curSum;
					res[0] = i;
					res[1] = j;
					res[2] = sum;
				}
			}
		}
		return res;
	}
}
