#include<iostream>
#include<cstring>

class Person
{
private:
	int age;
	char name[50];
public:
	Person(int myage, char* myname) : age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName() const
	{
		std::cout << "My name is" << name << std::endl;
	}
	void HowOldAreYou() const
	{
		std::cout << " I`m" << age << "years old" << std::endl;
	}
};

class UnivStudent : public Person
{
private:
	char major[50];
public:
	UnivStudent(char* myname, int myage, char * mymajor) : Person(myage, myname)
	{
		strcpy(major, mymajor);
	}
	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		std::cout << "My major is " << major << std::endl << std::endl;
	}
};

int main(void)
{
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();

	return 0;
}