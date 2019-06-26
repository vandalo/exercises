#pragma once

template <typename T>
constexpr T maxValue = T(1000);

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
