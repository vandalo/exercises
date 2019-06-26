#include "CMyTemplateTest.h"

#include <iostream>

CMyTemplateTest::CMyTemplateTest(){}

void CMyTemplateTest::main()
{
	std::cout << maxValue<int> << std::endl;
	std::cout << maxValue<double> << std::endl;
	std::cout << maxValue<char> << std::endl;
}

