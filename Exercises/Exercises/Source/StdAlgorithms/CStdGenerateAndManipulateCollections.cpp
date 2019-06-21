#include "CStdGenerateAndManipulateCollections.h"

#include <iostream>
#include <algorithm>
#include <numeric>

CStdGenerateAndManipulateCollections::CStdGenerateAndManipulateCollections() :
	a{3 , 6, 1, 0, -2, 5 }
{

}

void CStdGenerateAndManipulateCollections::main() 
{
	Copy();
	Move();
	Removing();
	CreatingCollections();
	ReplaceElements();
	TransformElements();
}

void CStdGenerateAndManipulateCollections::Copy()
{
	std::cout << "COPY / COPY_IF / COPY_N / COPY_BACKWARD" << std::endl;

	std::vector<int> v2(a.size());

	//Copy the elements from one container to the other
	//Do NOT use if you want to copy the full container
	copy(begin(a), end(a), begin(v2));

	//Use this to copy full container
	auto v3 = a;

	auto position = find(begin(a), end(a), 1);
	std::vector<int> v4(a.size());
	copy(begin(a), position, begin(v4));

	std::vector<int> v5(a.size());
	//Copy only the elements that returns true in lambda
	copy_if(begin(a), end(a), begin(v5), [](int elem) {return elem % 2 == 0; });

	//Copy the N elements from starting on iterator into the other iterator
	copy_n(begin(v5), 3, begin(v2));

	copy(begin(a), position + 1, position + 1);

	copy_backward(begin(v3), end(v3), end(a));

	//The commented line might work or not depending on the compiler, as you are modifying the same container
	//copy(begin(a), end(a) - 1, end(a) + 1);

	//This is how we have to do, this, starts from the last element
	copy_backward(begin(a), end(a) - 1, end(a));

	//Use copy_backword if the 3rd parameter iterator is in the middle of first and second parameter else use copy
}

void CStdGenerateAndManipulateCollections::Move()
{
	std::cout << "MOVE / MOVE_BACKWARD" << std::endl;

	struct test
	{
		int a;
		int b;
		test() : a(1), b(2) {}
	};

	std::vector<test> vecA(3);
	std::vector<test> vecB(1);

	vecB = vecA;
	vecA[0].a = 5;

	move(begin(vecA), end(vecA), begin(vecB));
}

void CStdGenerateAndManipulateCollections::Removing()
{
	std::cout << "REMOVE / REMOVE_IF" << std::endl;

	auto newend = remove(begin(a), end(a), 3);
	int s = a.size();
	int logicalsize = newend - begin(a);
	a.erase(newend, end(a));

	a = { 3 , 6, 1, 0, -2, 5 };
	a.erase(remove(begin(a), end(a), 3), end(a));
}

void CStdGenerateAndManipulateCollections::CreatingCollections()
{
	std::vector<int> v6(10);
	//fill the vector between the iterators
	fill(begin(v6), end(v6), 1);

	//this will fill from iterator N times
	fill_n(begin(v6), 6, 2);

	//This one need numeric include
	//this will set the value N, N+1, N+2... in the range of the iterators
	iota(begin(v6), end(v6), 5);

	int index = 10;
	//this will fill the vector with the number generated into the lambda
	generate(begin(v6), end(v6), [&index]() {return --index; });
	a = v6;
	index = 1;
	//this will fill the vector with the number generated into the lambda, but from begin to N times
	generate_n(begin(v6), 7, [&index]() {return (index *= 2); });

}

void CStdGenerateAndManipulateCollections::ReplaceElements()
{
	std::cout << "REPLACE / REPLACE_IF" << std::endl;
	std::vector<int> v6{2,4,8,16,32,64,128,2,1,0};

	//This will replace the elements that have 3th parameter values for last parameter value in the range of iterators
	replace(begin(v6), end(v6), 2, 7);

	//This will replace the elements that lambdas return true, with the last parameter value
	// On this case all values less than will be replaced by 7
	replace_if(begin(v6), end(v6), [](auto elem) {return elem < 16; }, 7);
}

void CStdGenerateAndManipulateCollections::TransformElements()
{
	std::cout << "TRANSFORM" << std::endl;
	std::vector<int> v6{ 2,4,8,16,32,64,128,2,1,0 };
	a = v6;

	//iterate the elements between the two first iterators, set them in the third iterator and the value is the result of the lambda
	transform(begin(v6), end(v6), begin(v6), [](int elem) {return elem * 2; }); 

	//iterate the elements between the two first iterators and get the elem2 from the third parameter, set them in the fourth iterator and the value is the result of the lambda
	transform(begin(a), end(a) - 1, begin(a) + 1, begin(v6), [](int elem1, int elem2) {return elem1 - elem2; });
	
	iota(begin(v6), end(v6), 1);
	iota(begin(a), end(a), 2);
	std::vector<int>v7(10);
	transform(begin(a), end(a), begin(v6), begin(v7), [](int elem1, int elem2) {return elem1 + elem2; });
}

