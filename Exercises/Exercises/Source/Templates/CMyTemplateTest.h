#pragma once

//Variable template specialization
//By default the maxValue will be 1000 but if we use it as double the value will be 2000 and if we use char, then will be Z
template <typename T>
constexpr T maxValue = T(1000);

//This is marked as error by the editor but it's a known bug from Visual studio
template <>
constexpr double maxValue<double> = 2000;

template <>
constexpr char maxValue<char> = 'Z';

class CMyTemplateTest
{
public:
	CMyTemplateTest();
	void main();
};
