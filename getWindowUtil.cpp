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

//HWND FindMainWindow(unsigned int processID)
//{
//	struct HANDLE_DATA {
//		unsigned int processID;
//		HWND handle;
//	} data;
//	data.processID = processID;
//	data.handle = 0;
//
//	static auto IsMainWindow = [](HWND handle)->BOOL
//	{
//		return GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle);
//	};
//
//	static auto EnumWindowsCallback = [](HWND handle, LPARAM lParam)
//	{
//		HANDLE_DATA& data = *(HANDLE_DATA*)lParam;
//		unsigned long process_id = 0;
//		GetWindowThreadProcessId(handle, &process_id);
//		if (data.processID != process_id || !IsMainWindow(handle)) {
//			return TRUE;
//		}
//		data.handle = handle;
//		return FALSE;
//	};
//
//	EnumWindows(EnumWindowsCallback, (LPARAM)&data);
//
//	return data.handle;
//}
//
//DWORD GetProcessID(const char* ProcessName)
//{
//	PROCESSENTRY32 pe32;
//	pe32.dwSize = sizeof(PROCESSENTRY32);
//
//	//获取进程快照
//	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//	if (hProcessSnap == INVALID_HANDLE_VALUE)
//	{
//		//   qDebug("CreateToolhelp32Snapshot 调用失败.");
//		return -1;
//	}
//
//	//遍历进程快照，轮流显示每个进程的信息
//	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
//	while (bMore)
//	{
//		// qDebug("进程名称：%ls", pe32.szExeFile); //这里得到的应该是宽字符，用%ls,不然无法正常打印
//		// qDebug("进程ID：%u", pe32.th32ProcessID);
//		if (QString(pe32.szExeFile) == (ProcessName))
//		{
//			qDebug("进程名称：%ls", pe32.szExeFile);
//			qDebug("进程ID：%u", pe32.th32ProcessID);
//			qDebug("pcPriClassBase ：%u", pe32.pcPriClassBase);
//			qDebug("th32ParentProcessID ：%u", pe32.th32ParentProcessID);
//			qDebug("cntThreads ：%u", pe32.cntThreads);
//			break;
//		}
//
//		bMore = ::Process32Next(hProcessSnap, &pe32);
//	}
//
//	//不要忘记清除掉snapshot对象
//	::CloseHandle(hProcessSnap);
//
//	return pe32.th32ProcessID;
//}