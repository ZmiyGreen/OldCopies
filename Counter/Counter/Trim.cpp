#include "pch.h"
#include "Trim.h"
#include <iostream>

std::string_view Trim::LeftTrim(std::string_view Str, char c)
{
	size_t first = Str.find_first_not_of(c);
	if (first != 0)
		return Str.substr(first, Str.length());
	else
		return Str;
}

std::string_view Trim::FullTrim(std::string_view Str, char c)
{
	int FirstCounter = 0;
	int LastCounter = 0;
	size_t last = Str.length();
	size_t first = 0;
	while (Str[--last] == c)
		LastCounter++;
	while (Str[first++] == c)
		FirstCounter++;
	std::cout << FirstCounter << " " << LastCounter << std::endl;
	if (LastCounter == 0 && FirstCounter == 0)
		return Str;
	else
		return Str.substr(FirstCounter, Str.length() - (LastCounter+FirstCounter));
}

std::string_view Trim::RightTrim(std::string_view Str, char c)
{
	int counter = 0;
	size_t last = Str.length();
	while (Str[--last] == c)
		counter++;
	if (last != Str.length())
		return Str.substr(0, Str.length() - counter);
	else
		return Str;
}