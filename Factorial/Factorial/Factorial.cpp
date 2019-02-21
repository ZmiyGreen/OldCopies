#include "pch.h"
#include <iostream>
#include <string>

static class Factorial
{
public:
	static long long LoopFact(long long n)
	{
		for (int i = n - 1; i >= 1; i--)
			n *= i;
		return n;
	}
	static int RecFact(double n)
	{
		if (n == 1)
			return 1;
		else
			return n * RecFact(n - 1);
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int a{ 15 };
	std::cout << "Факториал числа " << a << " = " << Factorial::LoopFact(a) << std::endl;
}

