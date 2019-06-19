#pragma once

#include <vector>
#include <list>
#include <map>

class CStlCountAndFind {
public:
	CStlCountAndFind();
	void main();

	void Count();
	void CountIf();
	void AllNoneAnyOf();
	void Find();
	void FindIf();
	void OtherFinds();

private:
	std::vector<int> v;
	std::vector<int> v_odd;
	std::list<int> l;
	std::string s;
	std::string s2;
	std::map<int, int> m;
};

