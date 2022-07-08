#include <Windows.h>

extern int Main();

VOID Startup()
{
	Main(); //GUI
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	switch (dwReason) {
	case DLL_PROCESS_ATTACH: {
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&Startup, 0, 0, 0);
	}break;

	case DLL_PROCESS_DETACH:
		break;
	};

	return TRUE;
}