/*
#include <iostream>
#include <string>

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
};

template <typename T>
class SimpleDataWrapper
{
private:
	T mdata;
public:
	SimpleDataWrapper(T data) : mdata(data)
	{ }
	void ShowDataInfo(void)
	{
		std::cout << "Data : " << mdata << std::endl;
	}
};

template <>
class SimpleDataWrapper <char*>
{
private:
	char* mdata;
public:
	SimpleDataWrapper(const char* data)
	{
		int len = strlen(data) + 1;
		mdata = new char[len];
		strcpy_s(mdata, len, data);
	}
	void ShowDataInfo()
	{
		std::cout << "String : " << mdata << std::endl;
		std::cout << "Lenght : " << strlen(mdata) << std::endl;
	}
	~SimpleDataWrapper() { delete[]mdata; }
};

template <>
class SimpleDataWrapper <Point<int>>
{
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) : mdata(x, y)
	{	}
	void ShowDataInfo(void)
	{
		mdata.ShowPosition();
	}
};

int main(void)
{
	SimpleDataWrapper<int> iwrap(170);
	SimpleDataWrapper<char*> swrap("Class Tmeplate Specialization");
	SimpleDataWrapper<Point<int>> poswarp(3, 7);
	iwrap.ShowDataInfo();
	swrap.ShowDataInfo();
	poswarp.ShowDataInfo();
	return 0;
}
*/