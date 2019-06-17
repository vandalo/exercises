#include "CStrlCount.h"

#include <iostream>
#include <vector>
#include <algorithm>

CStrlCount::CStrlCount() : 
	v{2,7,1,6,2,-2,4,0} 
{}

void CStrlCount::main()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "Start Count Algorithm Test" << std::endl;
	std::cout << "--------------------------" << std::endl;

	CountTwos();
}

// Count how many entries have the target value (2)
void CStrlCount::CountTwos()
{
	std::cout << "(1)Loop output / (2)STL v1 / (3)STL v2" << std::endl << std::endl;
	//Loop
	int twos = 0;
	int const target = 2;

	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == target) { twos++; }
	}
	std::cout << "(1)Result: " << twos << std::endl;

	//Stl
	twos = count(v.begin(), v.end(), target);
	std::cout << "(2)Result: " << twos << std::endl;

	twos = count(begin(v), end(v), target);
	std::cout << "(3)Result: " << twos << std::endl;
}

