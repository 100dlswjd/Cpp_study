#include<iostream>

int BoxVolume(int lenght, int width, int heght) {
	return lenght * width * heght;
}
int BoxVolume(int lenght, int width) {
	return lenght * width;
}
int BoxVolume(int lenght) {
	return lenght;
}

int main(void) {
	std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
	std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;
	return 0;
}