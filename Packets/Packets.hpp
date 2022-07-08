#pragma once
#include "PacketWriter.hpp"
#include "../Constants.hpp"

unsigned char* convertStringToPacketFormat(char* convertStr);
char* convertPacketFormatToString(unsigned char* packetStr, int byteLength);
int getPacketLength(char* grabbedTextPacket);

BOOL CreatePacket(LPBYTE data, DWORD length);

void SendPacket(uint32_t Length, LPBYTE inBuffer);