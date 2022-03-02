// Dll_test.cpp : DLL을 위해 내보낸 함수를 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "Dll_test.h"


// 내보낸 변수의 예제입니다.
DLLTEST_API int nDlltest=0;

// 내보낸 함수의 예제입니다.
DLLTEST_API int fnDlltest(void)
{
    return 0;
}

int add(int a, int b) {
    return a + b;
}
int add2(int a, int b) {
    return a + b;
}


// 내보낸 클래스의 생성자입니다.
CDlltest::CDlltest()
{
    return;
}
