#include "pch.h"
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std::chrono_literals;
//using std::chrono::seconds;
#include <thread>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>

class Time
{
private:
	int second;
	int minute;
	int hour;
	int Validator(const int& Value, const int& MinBorder, const int& MaxBorder)
	{
		return Value <= MaxBorder && Value >= MinBorder ? Value : MinBorder;
	}
	void plusTime(Time& Other)
	{
		second += Other.second;
		minute += Other.minute;
		hour += Other.hour;
		if (second > 59)
		{
			minute += 1;
			second -= 60;
		}
		if (minute > 59)
		{
			hour += 1;
			minute -= 60;
		}
	}
public:
	explicit Time(int h, int min, int sec)
	{
		setTime(h, min, sec);
	}
	explicit Time() : Time{ 0, 0,0 } {}
	explicit Time(int h) : Time{h, 0,0} {}
	explicit Time(int h, int min) : Time(h, min, 0) {}
	std::string ToString()
	{
		std::stringstream Out;
		Out << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second << std::endl;
		return Out.str();
	}
	int getInSeconds()
	{
		return (hour * std::pow(60, 2)) + (minute * 60) + second;
	}
	void setTime(int h, int min, int sec)
	{
		/*second = Validator(sec, 0, 59);
		minute = Validator(min, 0, 59);
		hour = Validator(h, 0, 23);*/
		try
		{
			if ((h >= 0 && h <= 23) && (min >= 0 && min <= 59) && (sec >= 0 && sec <= 59))
			{
				hour = h;
				minute = min;
				second = sec;
			}
			else
			{
				throw std::invalid_argument("Некорректный формат ввода!");
			}
		}
		catch (std::invalid_argument& Ex)
		{
			std::cout << Ex.what() << std::endl;
			//setTime(0, 0, 0);
			throw;
		}
	}
	void Show()
	{
		std::cout << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second << std::endl;
	}
	Time operator +(Time Other)
	{
		plusTime(Other);
		return Time(hour, minute, second);
	}
	Time operator +=(Time Other)
	{
		plusTime(Other);
		return Time(hour, minute, second);
	}
	bool operator <(Time Other)
	{
		return getInSeconds() < Other.getInSeconds();
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	/*int i = 0;
	for (i; i < 10; i++)
	{
		std::cout << i << std::endl;
		std::this_thread::sleep_for(1s);
	}*/
	/*std::vector<Time> Times
	{
		Time{ 2,7,30 },
		Time(20, 3, 19),
		Time(7, 3, 43),
		Time(7, 50, 29),
		Time(19, 42, 5)
	};*/
	//std::sort(Times.begin(), Times.end());
	//std::sort(Times.begin(), Times.end(), [](Time& a, Time& b) {return a.getInSeconds() > b.getInSeconds(); });
	/*for (auto& i : Times)
		i.Show();*/
	/*Time T1(3, 59, 50);
	T1.Show();
	for (int i = 0; i < 300; i++)
	{
		std::this_thread::sleep_for(0.1s);
		T1 += Time(0, 0, 1);
		T1.Show();
	}
	T1.Show();*/
	/*Time T1(25, 5, 30);
	T1.Show();
	auto TimeStr = T1.ToString();
	std::cout << TimeStr << std::endl;*/
}