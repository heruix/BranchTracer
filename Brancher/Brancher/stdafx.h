// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
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

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
