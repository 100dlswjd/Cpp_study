/*
#include <iostream>
#include <cstring>

class String
{
private:
	int len;
	char* str;
public:
	String()
	{
		len = 0;
		str = NULL;
	}
	String(const char* s)
	{
		len = strlen(s)+1;
		str = new char[len];
		strcpy_s(str, len, s);
	}
	String(const String& s)
	{
		len = s.len;
		str = new char[len];
		strcpy_s(str, len, s.str);
	}
	~String()
	{
		if (str != NULL)
			delete[]str;
	}
	String& operator=(const String& s)
	{
		if (str != NULL)
			delete[]str;
		len = s.len;
		str = new char[len];
		strcpy_s(str, len, s.str);
		return *this;
	}
	String& operator+=(const String& s)
	{
		int rlen = len + (s.len - 1);
		char* tempstr = new char[rlen];
		strcpy_s(tempstr, rlen, str);
		strcat_s(tempstr, strlen(tempstr) + strlen(s.str) + 1 , s.str);
		if (str != NULL)
			delete[] str;
		str = tempstr;
		return *this;
	}
	bool operator==(const String& s)
	{	
		return strcmp(str, s.str) ? false : true;
	}
	String operator+(const String& s)
	{
		char* tempstr = new char[len + s.len - 1];
		strcpy_s(tempstr, len + s.len - 1, str);
		strcat_s(tempstr, strlen(tempstr) + strlen(s.str) + 1, s.str);

		String temp(tempstr);
		delete[]tempstr;

		return temp;
	}

	friend std::ostream& operator << (std::ostream& os, const String& s);
	friend std::istream& operator >>(std::istream& is, String& s);
};

std::ostream& operator << (std::ostream& os, const String& s)
{
	os << s.str;
	return os;
}
std::istream& operator >> (std::istream& is, String& s)
{
	char str[100];
	is >> str;;
	s = String(str);
	return is;
}


int main(void)
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	//std::cout << str3 << std::endl;

	str1 += str2;
	if (str1 == str3)
		std::cout << "같음 !" << std::endl;
	else
		std::cout << "다름 !" << std::endl;
	String str4;
	std::cout << "문자열 입력 : ";
	std::cin >> str4;
	std::cout << "입력한 문자열 : " << str4 << std::endl;
	return 0;
}
*/