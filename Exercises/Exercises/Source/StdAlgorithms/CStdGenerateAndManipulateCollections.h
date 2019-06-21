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
	void ReplaceElements();

private:
	std::vector<int> a;
};