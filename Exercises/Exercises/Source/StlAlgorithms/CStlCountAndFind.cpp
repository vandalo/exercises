#include "CStlCountAndFind.h"

#include <iostream>
#include <vector>
#include <algorithm>

CStlCountAndFind::CStlCountAndFind() : 
	v{2,7,1,6,2,2,-2,4,4,0,6,2} 
	, v_odd{ 1,7,1,1,1,1 }
	, l{ 2,7,1,6,2,-2,4,0 }
	, s("27162-240")
	, s2("hello world I am here!")
	, m{ {1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30}, {7,31}, {8,31}, {9,30}, {10,31}, {11, 30}, {12, 31} }
{}

void CStlCountAndFind::main()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "Start Algorithm Test" << std::endl;
	std::cout << "--------------------------" << std::endl;

	Count();
	CountIf();
	AllNoneAnyOf();
	Find();
	FindIf();
	OtherFinds();
}

// Count how many entries have the target value (2)
void CStlCountAndFind::Count()
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

void CStlCountAndFind::CountIf()
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

void CStlCountAndFind::AllNoneAnyOf()
{
	std::cout << "ALL_OF / NONE_OF / ANY_OF" << std::endl;
	bool allof, noneof, anyof;
	//return if all the elements are odd
	allof = all_of(begin(v_odd), end(v_odd), [](auto elem) {return elem % 2 != 0; });

	//return if no one of the elements are odd
	noneof = none_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });

	//return if any element is odd
	anyof = any_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
}

void CStlCountAndFind::Find()
{
	std::cout << "FIND" << std::endl;

	//find an element in the vector, return an iterator
	int weLookedFor = -1;
	auto result = find(begin(v), end(v), 0);
	if (result != end(v))
	{
		weLookedFor = *result;
	}

	//find the first 2 after that 0
	result = find(result, end(v), 2);
	if (result != end(v))
	{
		weLookedFor = *result;
	}
	//The if is needed, else we would have wrong memory access

	//Check this with strings
	auto letter = find(begin(s2), end(s2), 'a');
}

void CStlCountAndFind::FindIf()
{
	std::cout << "FIND_IF" << std::endl;

	//Find first odd value
	auto result = find_if(begin(v), end(v), [](auto elem) { return elem % 2 != 0; });
}

void CStlCountAndFind::OtherFinds()
{
	std::cout << "FIND_IF_NOT / FIND_FIRST_OF / SEARCH / FIND_END / SEARCH_N" << std::endl;

	int weAreLookingFor = -1;

	//returns a pointer to the first occurence of even number
	auto result = find_if_not(begin(v), end(v), [](auto elem) { return elem % 2 != 0; });

	std::vector<int> primes{ 1,2,3,5,7,11,13 };
	//This will return the first prime in v
	result = find_first_of(begin(v), end(v), begin(primes), end(primes));

	//return a pointer to the first element of the subsequence
	std::vector<int> subsequence{ 6,2 };
	result = search(begin(v), end(v), begin(subsequence), end(subsequence));

	//string subsequence
	std::string am = "am";
	auto resultChar = search(begin(s2), end(s2), begin(am), end(am));

	//Here we are searching the last occurrence of the subsequence, then we increment iterator so this should be out of range
	result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));
	result++; result++;
	if (result != end(v))
	{
		int thisShouldNotEnter = *result;
	}

	//We search in the vector to find two consecutive 4. if find, this will return a pointer to the first 4 from the ocurrence
	result = search_n(begin(v), end(v), 2, 4);

	//Searches the range [first, last) for two consecutive identical elements.
	result = adjacent_find(begin(v), end(v));
}
