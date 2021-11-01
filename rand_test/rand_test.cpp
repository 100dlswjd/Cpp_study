#include<ctime>
#include<cstdlib>
#include<iostream>

void main()
{
	int n[5];
	
	for (int i = 0; i < 5; i++)
	{
		n[i] = rand() % 101;
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << n[i] << "  " << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		n[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << n[i] << "  " << std::endl;
	}
}