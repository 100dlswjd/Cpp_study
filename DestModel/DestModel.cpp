#include<iostream>
#include<cstring>

class Person
{
private:
	char* name;
public:
	Person(char* myname)
	{
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	~Person()
	{
		delete []name;
	}
	void WhatYourName() const
	{
		std::cout << "My name is " << name << std::endl;
	}
};

class UnivStudent : public Person
{
private:
	char* major;
public:
	UnivStudent(char* myname, char* mymajor) 
		: Person(myname)
	{
		major = new char[strlen(mymajor) + 1];
		strcpy(major, mymajor);
	}
	~UnivStudent() 
	{
		delete[]major;
	}
	void WhoAreYou() const
	{
		std::cout << "My major is" << major << std::endl << std::endl;
	}
};

int main(void)
{
	UnivStudent st1("a", "Mathematics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
	return 0;
}