#include<iostream>
#include<cstring>

class Computer
{
private:
	char owner[50];
public:
	Computer(char* name)
	{
		strcpy(owner, name);
	}
	void Calculate()
	{
		std::cout << "요청 내용을 계산합니다." << std::endl;
	}
};

class NotebookComp : public Computer
{
private:
	int Battery;
public:
	NotebookComp(char* name, int initChag)
		: Computer(name), Battery(initChag)
	{	}
	void Charging(){ Battery += 5; }
	void UseBattery() { Battery -= 1; }
	void MovingCal()
	{
		if (GetBatteryInfo() < 1)
		{
			std::cout << "충전이 필요합니다." << std::endl;
			return;
		}
		std::cout << "이동하면서"<< std::endl;
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }
};

class TabletNotebook : public NotebookComp
{
private:
	char regstPenModel[50];
public:
	TabletNotebook(char* name, int initChag, char* Pen) : NotebookComp(name, initChag)
	{
		strcpy(regstPenModel, Pen);
	}
	void Write(char* penInfo)
	{
		if (GetBatteryInfo() < 1)
		{
			std::cout << "충전이 필요합니다." << std::endl;
			return;
		}

		if (strcmp(regstPenModel, penInfo) != 0)
		{
			std::cout << "등록된 펜이 아닙니다." << std::endl;
		}
		std::cout << " 핌ㄴㅇㄹ" << std::endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("이수종", 5);
	TabletNotebook tn("정수영", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
	return 0;
}