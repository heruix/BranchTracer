// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>
#include <stdio.h>

#define MAX_FILE_PATH 512

#ifdef _WIN64
typedef DWORD64 CDWORD;

#define CustomAx Rax
#define CustomCx Rcx
#define CustomDx Rdx
#define CustomBx Rbx
#define CustomSp Rsp
#define CustomBp Rbp
#define CustomSi Rsi
#define CustomDi Rdi
#define CustomIp Rip

#else
typedef DWORD CDWORD;

#define CustomAx Eax
#define CustomCx Ecx
#define CustomDx Edx
#define CustomBx Ebx
#define CustomSp Esp
#define CustomBp Ebp
#define CustomSi Esi
#define CustomDi Edi
#define CustomIp Eip

#endif

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
