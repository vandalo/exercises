#include "CStructure.h"

#include "CMyList.h"

#include <iostream>

CStructure::CStructure()
{

}

void CStructure::main()
{
	CMyList<int> myList;
	std::cout << myList.empty() << std::endl;
	myList.push_back(1);
	myList.push_front(0);
	myList.push_back(2);
	myList.push_back(3);

	std::cout << myList.empty() << std::endl;

	std::cout << myList.front() << " " << myList.back() << std::endl;

	myList.print();

	myList.pop_back();
	myList.print();

	myList.pop_front();
	myList.print();
}

