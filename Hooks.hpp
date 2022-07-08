#pragma once
#include "Packets/Packets.hpp"

namespace Hooks
{
	struct HOOK {
		DWORD dwAddress;
		DWORD dwReturn;
		char* szOriginalBytes;
		INT nSize;
	};

	BOOL WriteHookBytes(HOOK hkHook, VOID* lpvHook, BOOL bEnable);

	const HOOK hPacketOut = { Constants::LogSendPacket, Constants::LogSendPacket + 5, "\x8B\xF0\x89\x45\xFC", 5 };
	void _CallbackSendHook();

//	const HOOK hPacketOut = { Constants::ReduceCPU, Constants::ReduceCPU + 5, "\x8B\xF0\x89\x75\x08", 5 };
	void CPUReducerHook();
}
