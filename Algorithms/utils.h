#pragma once

namespace Utils
{
	template<typename T>
	void printArray(T* arr, int size)
	{
		std::cout << "{";
		for (int i = 0; i < size - 1; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << arr[size - 1] << "}" << std::endl;
	}

	template<typename T>
	void printSubarray(T* arr, int left, int right, int size)
	{
		if (left >= right)
		{
			std::cout << "Error: left >= right" << std::endl;
			return;
		}
		if (right >= size)
		{
			std::cout << "Error: right >= size" << std::endl;
			return;
		}

		std::cout << "{";
		for (int i = left; i <= right - 1; i++)
		{
			std::cout << arr[i] << ", ";
		}
		std::cout << arr[right] << "}" << std::endl;
	}
}