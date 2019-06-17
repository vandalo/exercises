#include "CStrlCount.h"

#include <iostream>
#include <vector>
#include <algorithm>

CStrlCount::CStrlCount() : 
	v{2,7,1,6,2,-2,4,0} 
	, l{ 2,7,1,6,2,-2,4,0 }
	, s("27162-240")
	, m{ {1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30}, {7,31}, {8,31}, {9,30}, {10,31}, {11, 30}, {12, 31} }
{}

void CStrlCount::main()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "Start Count Algorithm Test" << std::endl;
	std::cout << "--------------------------" << std::endl;

	CountTwos();
	CountIfOdd();
}

// Count how many entries have the target value (2)
void CStrlCount::CountTwos()
{
	std::cout << "COUNT" << std::endl;
	//Loop
	int twos = 0;
	int const target = 2;
	char const targetChar = '2';

	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == target) { twos++; }
	}

	//Stl count using vector, list, string
	twos = count(v.begin(), v.end(), target);

	twos = count(begin(v), end(v), target);

	twos = count(l.begin(), l.end(), target);

	twos = count(begin(l), end(l), target);

	twos = count(s.begin(), s.end(), targetChar);

	twos = count(begin(s), end(s), targetChar);
}

void CStrlCount::CountIfOdd()
{
	std::cout << "COUNT_IF" << std::endl;
	//Loop
	int odds = 0;

	for (auto elem : v)
	{
		if (elem % 2 != 0) { odds++; }
	}
	odds = count_if(begin(v), end(v), [](auto elem) { return elem % 2 != 0; });

	//Count from the map how many months are long
	count_if(begin(m), end(m), [](auto m) { return m.second == 31; });
}

