#include <iostream>
#include <vector>
#include <array>
#include "divide_and_conquer/MaxSumSubarray.h"
#include "utils.h"

int main()
{
	std::vector<int> v{ -13, -3, -25, -20, -3, -16, -23, -18, -20, -7, -12, -5, -1, -15, -4, -7 };
	Utils::printArray<int>(v.data(), v.size());

	std::cout << "Brute Force" << std::endl;
	auto bruteForceRes{ MaxSumSubarray::bruteForce(v) };
	Utils::printSubarray<int>(v.data(), bruteForceRes[0], bruteForceRes[1], v.size());
	Utils::printArray<int>(bruteForceRes.data(), bruteForceRes.size());

	std::cout << "Divide And Rule" << std::endl;
	auto divideAndConquerRes{ MaxSumSubarray::divide_and_conquer(v) };
	Utils::printSubarray<int>(v.data(), divideAndConquerRes[0], divideAndConquerRes[1], v.size());
	Utils::printArray<int>(divideAndConquerRes.data(), divideAndConquerRes.size());

	return 0;
}