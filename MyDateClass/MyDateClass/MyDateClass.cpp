#include "pch.h"
#include <iostream>
#include <stdexcept>
#include <map>
#include <string>

unsigned int GiveValue(unsigned int& Value, unsigned int Border, std::string ErrorText)
{
	try
	{
		if (Value > Border || Value == 0)
			throw std::runtime_error(ErrorText);
		else
			return Value;
	}
	catch (std::runtime_error err)
	{
		std::cout << err.what() << std::endl;
		throw std::runtime_error(ErrorText);
	}
}

class Day
{
private:
	unsigned int DayValut;
public:
	explicit Day(unsigned int DValue)
	{
		DayValut = GiveValue(DValue, 31, "В месяце не может быть больше 31 дня!");
	}
	unsigned int GetDay() { return DayValut; }
};
class Month
{
private:
	unsigned int MonthValut;
public:
	explicit Month(unsigned int MValue)
	{
		MonthValut = GiveValue(MValue, 12, "Значение месяца должно быть от 1 до 12!");
	}
	unsigned int GetMonth() { return MonthValut; }
};
class Year
{
private:
	unsigned int YearValut;
public:
	explicit Year(unsigned int YValue) : YearValut(YValue) {}
	unsigned int GetYear() { return YearValut; }
};

class Date
{
private:
	Day DayValue;
	Month MonthValue;
	Year YearValue;
public:
	Date(Day DValue, Month MValue, Year YValue) : DayValue(DValue), MonthValue(MValue), YearValue(YValue) {}
	void Print()
	{
		std::cout << DayValue.GetDay() << "." << MonthValue.GetMonth() << "." << YearValue.GetYear() << std::endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	/*Date SomeDate { Day(3), Month(2), Year(2011) };
	SomeDate.Print();*/
	std::map<std::string, int> M
	{
		{"Февраль", 28},
	    {"Март", 31},
	    {"Апрель", 31}
	};
	M["Май"] = 31;
	for (auto i : M)
		std::cout << i.first << " " << i.second << std::endl;
}
