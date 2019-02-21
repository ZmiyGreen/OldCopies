#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "Trim.h"

class WordCounter
{
private:
	std::vector<std::pair<std::string, int>> Counter;
	bool deleteSimbols;
public:
	size_t Size()
	{
		return Counter.size();
	}
	WordCounter(std::string_view Path, bool del = true)
	{
		deleteSimbols = { del };
		Read(Path);
	}
	void Read(std::string_view Path)
	{
		std::map<std::string, int> Dict;
		std::string Buffer;
		std::fstream Stream(Path.data());
		while (Stream >> Buffer)
			++Dict[Trim::SimpleTrim(Buffer, '.')];
		Stream.close();
		Counter = { Dict.cbegin(), Dict.cend() };
	}
	void Sort()
	{
		std::sort(Counter.begin(), Counter.end(), [](const auto& a, const auto& b) {return b.second < a.second; });
	}
	void Print()
	{
		std::cout << "Всего записей: " << Size() << std::endl;
		for (const auto& i : Counter)
			std::cout << i.first << " " << i.second << std::endl;
	}
	void Head(int top = 5)
	{
		std::cout << "Всего записей: " << Size() << " Отображено записей" << top << std::endl;
		for (int i = 0; i < top; i++)
			std::cout << Counter[i].first << " " << Counter[i].second << std::endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	/*WordCounter Counter("Input.txt");
	Counter.Sort();
	Counter.Print();*/
	//Counter.Head(3);
	std::string Str{ "!!Привет!!" };
	//Str = Trim::LeftTrim(Str, '!');
	//Str = Trim::RightTrim(Str, '!');
	Str = Str.substr(2, 6);
	std::cout << Str << std::endl;
}

