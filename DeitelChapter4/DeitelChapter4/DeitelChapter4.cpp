#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string Str;
	std::cout << "Введите имя: " << std::endl;
	std::cin >> Str;
	std::cout << "Имя: " << Str << std::endl;
}
