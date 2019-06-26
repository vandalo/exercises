#include "CStructure.h"

#include "CMyList.h"
#include "CMyStack.h"
#include "CMyStaticArray.h"

#include <iostream>

CStructure::CStructure()
{

}

void CStructure::main()
{
	constexpr int arraySize1 = CMyStaticArray<int, 10>::GetSize();
	CMyStaticArray<int, 10> myArray;
	myArray[0] = 0;
	myArray[1] = 1;
	myArray[2] = 2;
	myArray[3] = 3;
	myArray[4] = 4;
	myArray[5] = 5;
	myArray[6] = 6;
	myArray[7] = 7;
	myArray[8] = 8;
	myArray[9] = 9;
	int value = myArray[3];

	for (const auto& value : myArray)
	{
		std::cout << value << std::endl;
	}

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

