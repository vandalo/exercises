#include "CStdComparingAndAccumulating.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

CStdComparingAndAccumulating::CStdComparingAndAccumulating() :
	a{ 1,2,3,4,5 }
	, b{1,2,0,4,3}
	, c{ 1,2,3,4,5 }
{

}

void CStdComparingAndAccumulating::main()
{
	Equals();
	MyAccumulate();
	Loops();
}

void CStdComparingAndAccumulating::Equals()
{
	std::cout << "EQUAL / MISMATCH" << std::endl;
	bool same = a.size() == b.size();
	for (size_t i = 0; i < a.size() && same; i++)
	{
		if (a[i] != b[i])
		{
			same = false;
		}
	}

	//return if two containers are equals
	auto ending1 = end(a);
	same = equal(begin(a), end(a), begin(c), end(c));


	//Return a pair with the two iterator pointing the first elements mismatching
	auto firstchange = std::mismatch(begin(a), end(a), begin(b));
	firstchange = std::mismatch(begin(a), end(a), begin(c));

	// If we reimplement the == we can use mismatch
	struct StructA {
		int a;
		int b;
		int c;
		StructA()
		{
			a = 1;
			b = 2;
			c = 3;
		}
		bool operator==(const StructA& rhs)
		{
			return a == rhs.a && b == rhs.b && c == rhs.c;
		}

	};


	std::vector<StructA> arrA(5);
	std::vector<StructA> arrB(5);
	auto firstchangeStr = std::mismatch(begin(arrA), end(arrA), begin(arrB));
}

void CStdComparingAndAccumulating::MyAccumulate()
{
	std::cout << "ACCUMULATE" << std::endl;

	//Will accumulate the values of a container
	int total = 0;
	total = std::accumulate(begin(a), end(a), 0);

	//You can add lambdas so on this case you only accumulate even numbers
	total = accumulate(begin(a), end(a), 0, [](int total, int i) { if (i % 2 == 0) return total + i; return total; });

	//Here we are multiplaing all the numbers, BUT the initial value is 1, so we do 1*1*2*3...
	total = accumulate(begin(a), end(a), 1, [](int total, int i) { return total * i; });

	//This is the same as previous but we put initial number as 0 so we have 0*1*2*3... = 0
	total = accumulate(begin(a), end(a), 0, [](int total, int i) { return total * i; });

	std::vector<std::string> words{ "one","two","three" };
	auto allwords = accumulate(begin(words), end(words), std::string{});
	int length = allwords.size();
	allwords = accumulate(begin(words), end(words), std::string{ "Words:" }, [](const std::string& total, std::string& s) { return total + " " + s; });
	length = allwords.size();

	std::string s = accumulate(begin(a), end(a), std::string{ "The numbers are:" }, [](const std::string& total, int i) {return total + " " + std::to_string(i); });
}

void CStdComparingAndAccumulating::Loops()
{
	std::cout << "FOR / FOR_EACH" << std::endl;
	std::vector<int> b(a);

	//Normal for
	for (auto it = begin(b); it != end(b); it++)
	{
		*it = 0;
	}

	//Ranged for, the best if you have to iterate into all the collection
	for (auto& i : b)
	{
		i = 1;
	}

	//For_each, iterates all elements from one iterator to another
	for_each(begin(b), end(b), [](int& elem) { elem = 2; });

	//As this example for_Each is useful when you don't want to iterate in the complete collection but in some of them
	b = a;
	auto firstthree = find(begin(b), end(b), 3);
	for_each(firstthree, end(b), [](int& elem) { elem = 0; });

	b = a;
	firstthree = find(begin(b), end(b), 3);
	for_each(firstthree, end(b), [](int& elem) { if (elem % 2 == 0) elem = 0; });
}

