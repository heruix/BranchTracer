#include <Windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
#ifdef _DEBUG
	#ifdef _WIN64
		WCHAR *target = L"C:\\Program Files\\Internet Explorer\\iexplore.exe";
		WCHAR *lib = L"Y:\\Desktop\\github\\BranchTracer\\Brancher\\x64\\Debug\\Brancher.dll";
	#else
		WCHAR *target = L"C:\\Program Files (x86)\\Internet Explorer\\iexplore.exe";
		WCHAR *lib = L"Y:\\Desktop\\github\\BranchTracer\\Brancher\\x64\\Debug\\Brancher.dll";
	#endif
#else
	WCHAR *target = L"C:\\dbg\\sample.exe";
	#ifdef _WIN64
		WCHAR *lib = L"C:\\dbg\\Brancher64.dll";
	#else
		WCHAR *lib = L"C:\\dbg\\Brancher32.dll";
	#endif
#endif

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	memset(&si, 0, sizeof(si));
	memset(&pi, 0, sizeof(pi));

	CreateProcessW(target, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi);

	HMODULE hKernel32 = LoadLibraryW(L"kernel32.dll");
	LPTHREAD_START_ROUTINE lpLoadLibraryW = (LPTHREAD_START_ROUTINE)GetProcAddress(hKernel32, "LoadLibraryW");

	SIZE_T dwLength = (wcslen(lib) + 1) * 2;
	LPVOID lpLibName = VirtualAllocEx(pi.hProcess, NULL, dwLength, MEM_COMMIT, PAGE_READWRITE);

	SIZE_T written;
	WriteProcessMemory(pi.hProcess, lpLibName, lib, dwLength, &written);

	HANDLE hThread = CreateRemoteThread(pi.hProcess, NULL, NULL, lpLoadLibraryW, lpLibName, NULL, NULL);
	WaitForSingleObject(hThread, INFINITE);

	CloseHandle(hThread);
	ResumeThread(pi.hThread);

	VirtualFreeEx(pi.hProcess, lpLibName, dwLength, MEM_RELEASE);

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	return 0;
}