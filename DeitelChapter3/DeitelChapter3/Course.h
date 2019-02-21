#include <string>

class Course
{
private:
	double courseRating;
	std::string courseName;
public:
	Course(std::string, double);
	double getRating();
	std::string getName();
	void setRating(double);
	void setName(std::string);
	void Show();
};


