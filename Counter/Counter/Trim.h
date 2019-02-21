#include <string>

static class Trim
{
public:
	static std::string SimpleTrim(std::string Str, char c)
	{
		if (Str[Str.length() - 1] == c)
			return Str.substr(0, Str.length() - 1);
		else
			return Str;
	}
	static void LinkTrim(std::string& Str, char c)
	{
		if (Str[Str.length() - 1] == c)
			Str = Str.substr(0, Str.length() - 1);
	}
	static std::string_view RightTrim(std::string_view Str, char c);
	/*{
		if (Str[Str.length() - 1] == c)
			return Str.substr(0, Str.length() - 1);
		else
			return Str.data();
	}*/
	static std::string_view LeftTrim(std::string_view Str, char c);
	static std::string_view FullTrim(std::string_view Str, char c);
};
