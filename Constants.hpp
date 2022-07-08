#pragma once
#include <Windows.h>
#include <stdint.h>

#define REGION_STEAM 1

struct OutPacket
{
	uint16_t _Opcode;
	uint32_t _Count;
	uint16_t _CommandOpcode;
	uint16_t _zero_pad;
	uint32_t _FullPacketLength;
	LPBYTE _Data;
};

namespace Constants
{
#ifdef REGION_STEAM
	const uint32_t _SendPacket = 0x0081460B;
	const uint32_t LogSendPacket = _SendPacket + 0x26; //_sendpacket + 0x26
#endif
	const uint32_t ReduceCPU = 0x0; //will find a hook spot for this later
}

namespace Functions
{
	typedef int (*SendPacket)(uint32_t Length, LPBYTE inBuffer, LPBYTE outBuffer);
}

