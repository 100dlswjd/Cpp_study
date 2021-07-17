#include <iostream>

int main(void)
{
    int num = 20;
    std::cout << "Hello World!" << std::endl; // end1은 개행
    std::cout << "Hello " ; // 연이은 표현
    std::cout << "World!" << std::endl;
    std::cout << num << ' ' << 'A';
    std::cout << ' ' << 3.14 << std::endl;
    return 0;
}