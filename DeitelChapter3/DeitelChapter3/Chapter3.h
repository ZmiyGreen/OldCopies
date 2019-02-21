#include <iostream>
#include <string>
#include <algorithm>

int GiveValue(int Value, int MaxBorder, int MinBorder = 1)
{
	if (Value >= MinBorder && Value <= MaxBorder)
		return Value;
	else
		return MinBorder;
}

class Day
{
private:
	int DValue;
public:
	explicit Day(int Value)
	{
		setDay(Value);
	}
	Day()
	{
		setDay(1);
	}
	void setDay(int Value)
	{
		DValue = GiveValue(Value, 12); //Значение месяца в пределах 1-12  
	}
	int getDay()
	{
		return DValue;
	}
};

class Month
{
private:
	int MValue;
public:
	explicit Month(int Value)
	{
		setMonth(Value);
	}
	Month()
	{
		setMonth(1);
	}
	void setMonth(int Value)
	{
		MValue = GiveValue(Value, 31);
	}
	int getMonth()
	{
		return MValue;
	}
};

class Year
{
private:
	int YValue;
public:
	explicit Year(int Value)
	{
		setYear(Value);
	}
	Year()
	{
		setYear(0);
	}
	void setYear(int Value)
	{
		YValue = GiveValue(Value, 2100, 0); //Значение года в прелелах от 0 до 2100 нашей эры.
	}
	int getYear()
	{
		return YValue;
	}
};

class Date
{
private:
	Day dayValue;
	Month monthValue;
	Year yearValue;
public:
	Date()
	{
		dayValue.setDay(1);
		monthValue.setMonth(1);
		yearValue.setYear(0);
	}
	Date(Day DValue, Month MValue, Year YValue)
	{
		dayValue.setDay(DValue.getDay());
		monthValue.setMonth(MValue.getMonth());
		yearValue.setYear(YValue.getYear());
	}
	void displayDate()
	{
		std::cout << dayValue.getDay() << "." << monthValue.getMonth() << "." << yearValue.getYear() << std::endl;
	}
};

class Person
{
private:
	std::string firstName; //Имя
	std::string lastName; //Фамилия
	Date bornDate;
public:
	Person()
	{
		bornDate;
		firstName;
		lastName;
	}
	explicit Person(const std::string& FName, const std::string& LName, const Date& BDate)
	{
		setFirstName(FName);
		setLastName(LName);
		bornDate = BDate;
	}
	void setFirstName(const std::string& Name)
	{
		firstName = NameCheck(Name);
	}
	void setLastName(const std::string& Name)
	{
		lastName = NameCheck(Name);
	}
	std::string getfirstName()
	{
		return firstName;
	}
	std::string getLastName()
	{
		return lastName;
	}
	void Show()
	{
		std::cout << getfirstName() << " " << getLastName() << " ";
		bornDate.displayDate();
	}
	std::string NameCheck(const std::string& Name)
	{
		if (Name.length() <= 25)
			return Name;
		else
			return Name.substr(0, 25);
	}
};

class Employee : Person
{
private:
	double monthSalary;
public:
	Employee() : Person()
	{
		setSalary(0);
	}
	Employee(const std::string& FName, const std::string& LName, const Date& BDate, double Money) : Person(FName, LName, BDate)
	{
		setSalary(Money);
	}
	void setSalary(const double &Money)
	{
		if (Money < 0)
			monthSalary = 0;
		else
			monthSalary = Money;
	}
	double getSalary()
	{
		return monthSalary;
	}
	double getYearSalary()
	{
		return monthSalary * 12;
	}
	void Show()
	{
		Person::Show();
		std::cout << "Зарплата/месяц: " << getSalary() << std::endl;
		std::cout << "Зарплата/год: " << getYearSalary() << std::endl;
		std::cout << std::endl;
	}

};
class Account
{
private:
	Person Owner;
	double Balance;
public:
	Account(Person Ow, double Bal)
	{
		Owner = Ow;
		setBalance(Bal);
	}
	void setBalance(double Bal)
	{
		if (Bal > 0)
			Balance = Bal;
		else
			Balance = 0;
	}
	void credit(double Value)
	{
		if (Value > 0)
			Balance += Value;
		else
			std::cout << "попытка внести на счет отризательную суму!" << std::endl;
	}
	void debet(double Sum)
	{
		if (Sum > Balance)
			std::cout << "Запрашиваемая сумма превышает доступные средства!" << std::endl;
		else
			Balance -= Sum;
	}
	double getBalance()
	{
		return Balance;
	}
	void Show()
	{
		Owner.Show();
		std::cout << "Баланс: " << getBalance() << std::endl;
	}
	bool operator<(Account Other)
	{
		return getBalance() < Other.getBalance();
	}
};

static class Collections
{
public:
	template<class T>
	static void Print(T& Value)
	{
		for (auto& i : Value)
			i.Show();
		std::cout << std::endl;
	}
	template<class T>
	static void Sort(T& Value)
	{
		std::sort(Value.begin(), Value.end());
		std::reverse(Value.begin(), Value.end());
	}
};