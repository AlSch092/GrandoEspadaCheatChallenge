#include "Hooks.hpp"

using namespace Hooks;

BOOL Hooks::WriteHookBytes(HOOK hkHook, VOID* lpvHook, BOOL bEnable) {
	try {

		if (bEnable) {
			DWORD dwOldProt;
			if (!VirtualProtect((void*)hkHook.dwAddress, (DWORD)hkHook.dwReturn - (DWORD)hkHook.dwAddress, PAGE_EXECUTE_READWRITE, &dwOldProt))
				return false;
			*(UCHAR *)hkHook.dwAddress = 0xE9;
			*(UINT*)(hkHook.dwAddress + 1) = (DWORD)lpvHook - hkHook.dwAddress - 5;
			for (int i = 0; i < hkHook.nSize - 5; i++) {
				memcpy((VOID*)(hkHook.dwAddress + i + 5), (VOID*) "\x90", 1);
			}
		}
		else {
			DWORD dwOldProt;
			if (!VirtualProtect((void*)hkHook.dwAddress, (DWORD)hkHook.dwReturn - (DWORD)hkHook.dwAddress, PAGE_EXECUTE_READWRITE, &dwOldProt))
				return false;
			memcpy((VOID*)hkHook.dwAddress, (VOID*)hkHook.szOriginalBytes, hkHook.nSize);
		}
	}
	catch (...){
		MessageBoxA(0, "Failed to write bytes.", "Error", 0);
	}
	return true;
}

LPBYTE SendBuffer;
DWORD SendLength;

//esp+ 0x24 = buffer == edi
//length -> in EAX, if eax == 0, look at buffer[10]
void __declspec(naked) Hooks::_CallbackSendHook()
{
	__asm
	{
		push eax
		mov SendLength, eax
		mov eax, [esp+0x28]
		mov SendBuffer, eax
		pop eax
		pushad
	}

	if (SendLength > 0)
	{
		CreatePacket(SendBuffer, SendLength);
	}
	else if (SendLength == 0)
	{
		memcpy(&SendLength, &SendBuffer[10], sizeof(byte));
		CreatePacket(SendBuffer, SendLength);
	}

	__asm
	{
		popad
		mov esi, eax
		mov [ebp+0x08], esi
		jmp hPacketOut.dwReturn
	}
}

int dwSleepTime = 10;
void __declspec(naked) Hooks::CPUReducerHook()
{
	__asm
	{
		pushad
	}

	Sleep(dwSleepTime);

	__asm
	{
		popad
		//jmp hkReduceCPU.dwReturn
	}
}