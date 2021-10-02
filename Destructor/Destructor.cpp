#include<iostream>
#include<cstring>

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		std::cout << "�̸� : " << name << std::endl;
		std::cout << "���� : " << age << std::endl;
	}
	~Person()
	{
		delete []name;
		std::cout << "called destructorl!" << std::endl;
	}
};

int main(void)
{
	Person man1("Lee dong Woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}