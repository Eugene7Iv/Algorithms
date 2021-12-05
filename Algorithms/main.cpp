#include <iostream>
#include <vector>
#include <array>
#include "divide_and_conquer/MaxSumSubarray.h"
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
	std::array<int, 3> divideAndConquerRes{ MaxSumSubarray::divide_and_conquer(v) };
	printSubarray<int>(v.data(), divideAndConquerRes[0], divideAndConquerRes[1], v.size());
	printArray<int>(divideAndConquerRes.data(), divideAndConquerRes.size());

	return 0;
}