#include <iostream>
#include <vector>
#include <array>
#include "divide_and_rule/MaxSumSubarray.h"
#include "utils.h"

int main()
{
	std::cout << "Hello World!" << std::endl;

	std::vector<int> v{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	std::array<int, 3> res{ MaxSumSubarray::bruteForce(v) };

	printArray<int>(v.data(), v.size());
	printSubarray<int>(v.data(), res[0], res[1], v.size());
	printArray<int>(res.data(), res.size());

	return 0;
}