// Exercises.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Source\StdAlgorithms\CStdAlgorithms.h"
#include "Source\Structures\CStructure.h"
#include "Source\Templates\CMyTemplateTest.h"

int main()
{
	CStdAlgorithms stdAlgorithm;
	CStructure structures;
	CMyTemplateTest templates;
	stdAlgorithm.main();
	structures.main();
	templates.main();


	while (true) {}
    return 0;
}

