#ifndef _GET_WIN_UTILS_H
#define _GET_WIN_UTILS_H
#include <Windows.h>
#include <TlHelp32.h>

BOOL IsMainWindow(HWND handle);
BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam);
HWND FindMainWindow(unsigned long process_id);//ͨ������id�Ż�ȡ�����ھ��
DWORD GetProcessidFromName(const char* name);

#endif // _GET_WIN_UTILS_H


