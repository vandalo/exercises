#pragma once

#include <vector>
#include <string>

class Employee
{
public:
	Employee(std::string first, std::string last, int sal) :
		firstname(first), lastname(last), salary(sal) {}

	int getSalary() { return salary; }
	std::string getSortingName() { return lastname + ", " + firstname; }

private:
	std::string firstname;
	std::string lastname;
	int salary;
};

class CStdSort
{
public:
	CStdSort();
	void main();
	void Sort();
	void IsSorted();
	void HighesAndLowest();
	void RandomGenerator();
	void PartialSort();
	void NthElement();

private:
	std::vector<int> v;
	std::vector<Employee> staff;
};