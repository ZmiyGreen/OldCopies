#include "pch.h"
#include <iostream>
#include "Chapter3.h"
#include <string>
#include <vector>

class Invoke
{
private:
	std::string Article;
	std::string Description;
	int Number;
	double Price;
	void setArticte(std::string_view Str)
	{
		if (Str.length() <= 15)
			Article = Str;
		else
			Article = Str.substr(0, 15);
	}
	void setDescription(std::string_view Str)
	{
		if (Str.length() <= 25)
			Description = Str;
		else
			Description = Str.substr(0, 25);
	}
	void setNumber(int Value)
	{
		if (Value >= 0 && Value <= 100)
			Number = Value;
		else
			Number = 0;
	}
	void setPrice(double Pri)
	{
		if (Pri >= 0)
			Price = Pri;
		else
			Price = 0;
	}
public:
	Invoke()
	{
		setArticte("");
		setDescription("");
		setPrice(0);
		setNumber(0);
	}
	explicit Invoke(std::string Art, std::string Des, int N, double D)
	{
		setArticte(Art);
		setDescription(Des);
		setPrice(D);
		setNumber(N);
	}
	std::string getArticle()
	{
		return Article;
	}
	std::string getDescription()
	{
		return Description;
	}
	double getPrice()
	{
		return Price;
	}
	double getNumber()
	{
		return Number;
	}
	double getSumPrice()
	{
		return Number * Price;
	}
	void Show()
	{
		std::cout << "Товар: " << getArticle() << std::endl;
		std::cout << "Описание: " << getDescription() << std::endl;
		std::cout << "Количество: " << getNumber() << std::endl;
		std::cout << "Стоимость за 1: " << getPrice() << std::endl;
		std::cout << "Суммарная стоимость: " << getSumPrice() << std::endl;
		std::cout << std::endl;
	}
	bool operator<(Invoke Other)
	{
		return getSumPrice() < Other.getSumPrice();
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	/*Account A1(Person("Иванов1", "Иван1", Date(Day(3), Month(10), Year(2002))), 400);
	Account A2(Person("Иванов2", "Иван2", Date(Day(3), Month(10), Year(2008))), 408);
	Account A3(Person("Иванов3", "Иван3", Date(Day(3), Month(10), Year(2003))), 400.7);
	Account A4(Person("Иванов4", "Иван4", Date(Day(3), Month(10), Year(2005))), 480);
	Account A5(Person("Иванов5", "Иван5", Date(Day(3), Month(10), Year(2001))), 200);
	std::vector<Account> Users { A1, A2, A3, A4, A5 };
	Users[0].credit(100);
	Users[1].debet(400);
	Collections::Print(Users);
	Collections::Sort(Users);
	Collections::Print(Users);*/
	std::vector<Invoke> Product
	{
		Invoke{ "Монитор1", "классический монитор", 7, 350 },
		Invoke { "Монитор2", "классический монитор", 5, 330 },
		Invoke { "Монитор3", "классический монитор", 7, 550 }
	};
	Collections::Print(Product);
	Collections::Sort(Product);
	Collections::Print(Product);
}

