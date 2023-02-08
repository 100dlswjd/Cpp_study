/*
#include <iostream>

template <typename T>

T Max(T a, T b)
{
	return a > b ? a : b;
}

template <>
char* Max(char* a, char* b)
{
	std::cout << "char * Max<char *>(char* a, char* b)" << std::endl;
	return strlen(a) > strlen(b) ? a : b;
}

template <>
const char* Max(const char* a, const char* b)
{
	std::cout << "const char * Max<char *>(const char* a, const char* b)" << std::endl;
	return strlen(a) > strlen(b) ? a : b;
}

int main(void)
{
	std::cout << Max(11, 15) << std::endl;
	std::cout << Max('T', 'Q') << std::endl;
	std::cout << Max(3.5, 7.5) << std::endl;
	std::cout << Max("Simple", "Best") << std::endl;

	char str1[] = "Simple";
	char str2[] = "Best";

	std::cout << Max(str1, str2) << std::endl;
	return 0;
}
*/