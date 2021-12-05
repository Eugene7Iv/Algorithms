#include <iostream>
#include <vector>
#include <array>
#include "divide_and_rule/MaxSumSubarray.h"
#include "utils.h"

int main()
{
	std::vector<int> v{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	printArray<int>(v.data(), v.size());

	std::cout << "Brute Force" << std::endl;
	std::array<int, 3> bruteForceRes{ MaxSumSubarray::bruteForce(v) };
	printSubarray<int>(v.data(), bruteForceRes[0], bruteForceRes[1], v.size());
	printArray<int>(bruteForceRes.data(), bruteForceRes.size());

	std::cout << "Divide And Rule" << std::endl;
	std::array<int, 3> divideAndRuleRes{ MaxSumSubarray::divide_and_rule(v) };
	printSubarray<int>(v.data(), divideAndRuleRes[0], divideAndRuleRes[1], v.size());
	printArray<int>(divideAndRuleRes.data(), divideAndRuleRes.size());

	return 0;
}