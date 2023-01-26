#include <iostream>

// Ŭ���� Data�� �䳻 �� ����
typedef struct Data
{
	int data;
	void (*ShowData)(Data*);
	void (*Add)(Data*, int);
} Data;


void ShowData(Data* THIS) { std::cout << "Data : " << THIS->data << std::endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

// ������ ����� main �Լ�
/*
int main()
{
	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
}
*/