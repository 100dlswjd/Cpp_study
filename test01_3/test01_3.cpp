// ���ڸ� �ϳ� �Է� �޾Ƽ� �� ���ڿ� �ش��ϴ� �������� ����ϴ� ���α׷��� �ۼ��غ���
// ���� �� ����ڰ� 5�� �Է��Ѵٸ� �����ܿ��� 5���� ��� �ؾ� �Ѵ�.
#include<iostream>

int main(void) {
	int num;

	std::cout << "����� ����ұ��? : ";
	std::cin >> num;

	for (int i = 1; i < 10; i++) {
		std::cout << num << "*" << i << "=" << num * i << std::endl;
	}
}