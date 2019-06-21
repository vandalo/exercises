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
	void TransformElements();

private:
	std::vector<int> a;
};