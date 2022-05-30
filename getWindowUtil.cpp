#include "getWindowUtil.h"

struct handle_data {
	unsigned long process_id;
	HWND best_handle;
};

BOOL IsMainWindow(HWND handle)
{
	return GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle);
}

BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam)
{
	handle_data& data = *(handle_data*)lParam;
	unsigned long process_id = 0;
	GetWindowThreadProcessId(handle, &process_id);
	if (data.process_id != process_id || !IsMainWindow(handle)) {
		return TRUE;
	}
	data.best_handle = handle;
	return FALSE;
}


//通过进程id号获取主窗口句柄
HWND FindMainWindow(unsigned long process_id)
{
	handle_data data;
	data.process_id = process_id;
	data.best_handle = 0;
	BOOL ii =   EnumWindows(EnumWindowsCallback, (LPARAM)&data);
	return data.best_handle;
}


DWORD GetProcessidFromName(const char* name)
{
	DWORD id = 0;
	HANDLE    hToolHelp32Snapshot;
	hToolHelp32Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32    pe = { sizeof(PROCESSENTRY32) };
	BOOL  isSuccess = Process32First(hToolHelp32Snapshot, &pe);
	while (isSuccess)
	{
		size_t len = WideCharToMultiByte(CP_ACP, 0, pe.szExeFile, wcslen(pe.szExeFile), NULL, 0, NULL, NULL);
		char* des = (char*)malloc(sizeof(char) * (len + 1));
		WideCharToMultiByte(CP_ACP, 0, pe.szExeFile, wcslen(pe.szExeFile), des, len, NULL, NULL);
		des[len] = '\0';
		if (!strcmp(des, name))
		{
			id = pe.th32ProcessID;
			break;
		}
		free(des);
		isSuccess = Process32Next(hToolHelp32Snapshot, &pe);
	}
	CloseHandle(hToolHelp32Snapshot);
	return id;
}