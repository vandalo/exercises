#pragma once

#include <vector>

class CStdGenerateAndManipulateCollections
{
public:
	CStdGenerateAndManipulateCollections();
	void main();
	void Copy();
	void Move();
	void Removing();
	void CreatingCollections();

private:
	std::vector<int> a;
};