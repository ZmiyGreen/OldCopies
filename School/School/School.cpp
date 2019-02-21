#include "pch.h"
#include <iostream>
#include <string>

static class Input
{
public:
	template<typename T1>
	static T1 Validate(T1 Value, T1 MaxBorder, T1 MinBorder = 0)
	{
		return Value <= MinBorder && Value >= MaxBorder ? Value : MinBorder;
	}
};

int main()
{
	int A = Input::Validate<int>(5, 0, 20);
	std::cout << A << std::endl;
}