#include<iostream>
#include<string.h>
#include<stdlib.h>

char* MakeStrAdr(int len) {
	char* str = (char*)malloc(sizeof(char) * len);
	return str;
}

int main() {
	char* str = MakeStrAdr(20);
	strcpy_s( "I am so happy~");
	std::cout << str << std::endl;
	free(str);
	return 0;
}

