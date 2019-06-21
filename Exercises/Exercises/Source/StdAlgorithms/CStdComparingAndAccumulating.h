#pragma once

#include <vector>

class CStdComparingAndAccumulating
{
public:
	CStdComparingAndAccumulating();
	void main();

private:
	void Equals();
	void MyAccumulate();
	void Loops();

	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;
};