#include <iostream>

int main(void)
{
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num);

	for (int i = 0; i < sizeof(num); i++)
		std::cout << static_cast<int>(*(ptr + i)) << std::endl;

	return 0;
}