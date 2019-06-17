#pragma once

#include <vector>
#include <list>
#include <map>

class CStrlCount {
public:
	CStrlCount();
	void main();

	void CountTwos();
	void CountIfOdd();

private:
	std::vector<int> v;
	std::list<int> l;
	std::string s;
	std::map<int, int> m;
};

