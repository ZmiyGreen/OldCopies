#include "pch.h"
#include "Course.h"
#include <iostream>

Course::Course(std::string Name, double Rating)
{
	Course::setName(Name);
	Course::setRating(Rating);
}
std::string Course::getName()
{
	return courseName;
}
double Course::getRating()
{
	return courseRating;
}
void Course::setName(std::string Name)
{
	courseName = Name;
}
void Course::setRating(double Rating)
{
	courseRating = Rating;
}
void Course::Show()
{
	std::cout << "Название курса: " << getName() << " Рейтинг: " << getRating() << std::endl;
}
