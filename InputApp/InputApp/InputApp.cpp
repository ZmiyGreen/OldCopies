#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>


class Person
{
private:
	std::string Name;
	int Age;
public:
	Person(std::string N, int A) : Name(N), Age(A) {}
	void Print()
	{
		std::cout << "Имя: " << Name << " Возраст: " << Age << std::endl;
	}
	bool operator<(const Person &Other)
	{
		return Age < Other.Age;
	}
};

void RuLang()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

template<typename T> T Input(std::string Text = "")
{
	T Value;
	std::cout << Text;
	//std::cin >> Value;
	std::getline(std::cin, Value);
	return Value;
}
template<typename T> void Sum(T A, T B)
{
	T Result = A + B;
	std::cout << "Сумма чисел: " << Result << std::endl;
}
void VPrint(std::vector<Person> V)
{
	for (auto i : V)
		i.Print();
}

int main()
{
	RuLang();
	auto A = Input<std::string>("Введите строку: ");
	std::cout << A << std::endl;
	auto B = Input<std::string>("Введите новую строку: ");
	std::cout << B << std::endl;
	/*Person P1("Иванов", 30);
	Person P2("Петров", 10);
	Person P3("Жуков", 20);
	std::vector<Person> V = { P1, P2, P3 };
	VPrint(V);
	std::cout << std::endl;
	std::sort(V.begin(), V.end());
	VPrint(V);*/
}

