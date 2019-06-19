#include "CStlSort.h"

#include <iostream>
#include <algorithm>

CStlSort::CStlSort() :
	v{4,1,0,1,-2,3,7,-6,2,0,0,-9,9}
	, staff{
		{ "Kate", "Gregory", 1000 },
		{ "Obvious", "Artificial", 2000 },
		{ "Fake", "Name", 1000 },
		{ "Alan", "Turing", 2000 },
		{ "Grace", "Hopper", 2000 },
		{ "Anita", "Borg", 2000 },
	}
{

}

void CStlSort::main()
{
	Sort();
	IsSorted();
	HighesAndLowest();
}

void CStlSort::Sort()
{
	std::cout << "SORT / STABLE_SORT" << std::endl;
	auto v2 = v;
	std::sort(begin(v2), end(v2));
	std::sort(begin(v2), end(v2), [](auto elem1, auto elem2) { return elem1 > elem2; });
	std::sort(begin(v2), end(v2), [](auto elem1, auto elem2) { return abs(elem1) > abs(elem2); });

	
	//std::sort(begin(staff), end(staff)); - only works if operator< is implemented

	//this sorts by salary (int)
	std::sort(begin(staff), end(staff), [](Employee e1, Employee e2) { return e1.getSalary() < e2.getSalary(); });

	//this sorts by name (string)
	std::sort(begin(staff), end(staff), [](Employee e1, Employee e2) { return e1.getSortingName() < e2.getSortingName(); });

	//This will sort by salary but in case that we have same salary will keep the order that we had.
	//As last sort we done was by name. In case that we have the same salary this will be sort by name
	std::stable_sort(begin(staff), end(staff), [](Employee e1, Employee e2) { return e1.getSalary() < e2.getSalary(); });
}

void CStlSort::IsSorted()
{
	std::cout << "IS_SORT" << std::endl;
	auto v2 = v;

	//We sort big to small
	std::sort(begin(v2), end(v2), [](auto elem1, auto elem2) { return elem1 > elem2; });

	//Default sort is small to big so this return false
	auto sorted = is_sorted(begin(v2), end(v2));

	//With this lambda we change default check from big to small so it returns true
	sorted = is_sorted(begin(v2), end(v2), [](auto elem1, auto elem2) { return elem1 > elem2; });
}

void CStlSort::HighesAndLowest()
{
	std::cout << "MAX_ELEMENT / MIN_ELEMMENT / UPPER_BOUND / LOWER_BOUND" << std::endl;
	int high = *(max_element(begin(v), end(v)));
	int low = *(min_element(begin(v), end(v)));

	//if you have sorted the container, the first element is the lowest and the last one is the highest
	auto v2 = v;
	std::sort(begin(v2), end(v2));
	low = *begin(v2);
	high = *(end(v2) - 1);

	//Returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found.
	int positive = *upper_bound(begin(v2), end(v2), 0);

	std::sort(begin(staff), end(staff), [](Employee e1, Employee e2) { return e1.getSortingName() < e2.getSortingName(); });

	//Returns an iterator pointing to the first element in the range [first, last) that is not less than (i.e. greater or equal to) value, or last if no such element is found.
	auto p = std::lower_bound(begin(staff), end(staff), "Gregory, Kate", [](Employee e1, std::string n) { return e1.getSortingName() < n; });
	int sal = p->getSalary();
}

