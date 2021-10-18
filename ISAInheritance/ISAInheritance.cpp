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
		std::cout << "��û ������ ����մϴ�." << std::endl;
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
			std::cout << "������ �ʿ��մϴ�." << std::endl;
			return;
		}
		std::cout << "�̵��ϸ鼭"<< std::endl;
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
			std::cout << "������ �ʿ��մϴ�." << std::endl;
			return;
		}

		if (strcmp(regstPenModel, penInfo) != 0)
		{
			std::cout << "��ϵ� ���� �ƴմϴ�." << std::endl;
		}
		std::cout << " �ˤ�����" << std::endl;
		UseBattery();
	}
};

int main(void)
{
	NotebookComp nc("�̼���", 5);
	TabletNotebook tn("������", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
	return 0;
}