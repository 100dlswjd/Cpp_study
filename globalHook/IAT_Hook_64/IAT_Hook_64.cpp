// IAT_Hook_64.cpp : DLL을 위해 내보낸 함수를 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "IAT_Hook_64.h"

// 내보낸 변수의 예제입니다.
IATHOOK64_API int nIATHook64=0;

// 내보낸 함수의 예제입니다.
IATHOOK64_API int fnIATHook64(void)
{
    return 0;
}

// 내보낸 클래스의 생성자입니다.
CIATHook64::CIATHook64()
{
    return;
}
