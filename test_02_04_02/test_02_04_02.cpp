#include<iostream>
#include<ctime>
#include<cstdlib>

int main(void) {
	int num[5];

	for (int i = 0; i < 5; i++) {
		num[i] = rand() % 100 + 1;
		std::cout << num[i] << std::endl;
	}
}