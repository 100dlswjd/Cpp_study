#include<iostream>

void Counter()
{
	static int cnt;
	cnt++;
	std::cout << "Currnet cnt : " << cnt << std::endl;
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		Counter();
	return 0;
}