#pragma once
#include <vector>
#include <array>
#include <climits>
#include <functional>

namespace MaxSumSubarray
{
	enum Res
	{
		FirstIndx,
		SecondIndx,
		Sum,
		Count
	};

	using return_type = std::array<int, Count>;

	return_type bruteForce(const std::vector<int>& v)
	{
		int left = -1;
		int right = -1;
		int sum = INT_MIN;
		return_type res{left, right, sum};

		for (int i = 0; i < v.size(); i++)
		{
			int curSum = v[i];
			for (int j = i + 1; j < v.size(); j++)
			{
				curSum += v[j];
				if (curSum >= sum)
				{
					sum = curSum;
					res[FirstIndx] = i;
					res[SecondIndx] = j;
					res[Sum] = sum;
				}
			}
		}
		return res;
	}

	return_type find_max_crossing_subarray(const std::vector<int>& v, int left, int mid, int right)
	{
		return_type res{ -1, -1, 0 };

		int left_sum = INT_MIN;
		int sum = 0;
		for (int i = mid; i >= left; i--)
		{
			sum += v[i];
			if (sum >= left_sum)
			{
				left_sum = sum;
				res[FirstIndx] = i;
			}
		}

		int right_sum = INT_MIN;
		sum = 0;
		for (int j = mid + 1; j <= right; j++)
		{
			sum += v[j];
			if (sum >= right_sum)
			{
				right_sum = sum;
				res[SecondIndx] = j;
			}
		}
		res[Sum] += left_sum + right_sum;

		return res;
	}

	return_type find_max_subarray(const std::vector<int>& v, int left, int right)
	{
		if (left == right)
		{
			return { left, right, v[left] };
		}
		else
		{
			int mid = (left + right) / 2;

			return_type leftRes = find_max_subarray(v, left, mid);
			return_type rightRes = find_max_subarray(v, mid + 1, right);
			return_type midRes = find_max_crossing_subarray(v, left, mid, right);

			if (leftRes[Sum] >= rightRes[Sum] && leftRes[Sum] >= midRes[Sum])
				return leftRes;
			else if (rightRes[Sum] >= leftRes[Sum] && rightRes[Sum] >= midRes[Sum])
				return rightRes;
			else
				return midRes;
		}
	}

	return_type divide_and_rule(const std::vector<int>& v)
	{
		return find_max_subarray(v, 0, v.size() - 1);
	}
}
