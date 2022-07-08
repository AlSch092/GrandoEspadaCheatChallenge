#include "Packets.hpp"
#include <iostream>
#include <queue>

std::queue<PacketWriter*> SendPacketQueue;

short changeEndianness16(short val)
{
	return (val << 8) |          // left-shift always fills with zeros
		((val >> 8) & 0x00ff); // right-shift sign-extends, so force to zero
}

int rand_lim(int limit) {
	/* return a random number between 0 and limit inclusive.
	*/

	int divisor = RAND_MAX / (limit + 1);
	int retval;

	do {
		retval = rand() / divisor;
	} while (retval > limit);

	return retval;
}

unsigned char* convertStringToPacketFormat(char* convertStr) {

	char fixedString[4096 * 3] = { 0 };

	//strip spaces, bad text
	int i; int j = 0;

	for (i = 0; convertStr[i] != '\0'; i++) {
		if ((convertStr[i] >= 'A' && convertStr[i] <= 'F') || (convertStr[i] >= '0' && convertStr[i] <= '9') || (convertStr[i] >= 'a' && convertStr[i] <= 'f'))  {
			fixedString[j] = convertStr[i];
			j++;
		}
		else if (convertStr[i] == ' ') {

		}
		else if (convertStr[i] == '*') {

			int random = rand_lim(15);

			if (random >= 0 && random <= 9) {
				fixedString[j] = random + 0x30;
			}
			else if (random >= 9 && random <= 15) {
				fixedString[j] = random + 0x55;
			}

			j++;
		}
		else {
			MessageBoxA(0, "Bad Hex Character found in sent packet.", "TOS PE (X.)", 0);
			return NULL;
		}

	}

	unsigned char* bytestring = (unsigned char*)malloc((sizeof(char)*j * 2) + 1);
	ZeroMemory(bytestring, (sizeof(char)*j * 2) + 1);
	j = 0;

	for (i = 0; fixedString[i] != '\0'; i++) {

		if (i % 2 == 0) { //even number iterator
			if (fixedString[i] >= 'a' && fixedString[i] <= 'f') {
				bytestring[j] = ((fixedString[i] - 0x57) << 4);

				if (fixedString[i + 1] >= 'A' && fixedString[i + 1] <= 'F') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x37);
				}
				else if (fixedString[i + 1] >= '0' && fixedString[i + 1] <= '9') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x30);
				}
				else if (fixedString[i + 1] >= 'a' && fixedString[i + 1] <= 'f') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x57);
				}
				j++;
				i++;
			}
			else if (fixedString[i] >= '0' && fixedString[i] <= '9') {

				bytestring[j] = ((fixedString[i] - 0x30) << 4);

				if (fixedString[i + 1] >= 'A' && fixedString[i + 1] <= 'F') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x37);
				}
				else if (fixedString[i + 1] >= '0' && fixedString[i + 1] <= '9') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x30);
				}
				else if (fixedString[i + 1] >= 'a' && fixedString[i + 1] <= 'f') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x57);
				}
				j++;
				i++;
			}
			else if (fixedString[i] >= 'A' && fixedString[i] <= 'F') {
				bytestring[j] = ((fixedString[i] - 0x37) << 4);

				if (fixedString[i + 1] >= 'A' && fixedString[i + 1] <= 'F') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x37);
				}
				else if (fixedString[i + 1] >= '0' && fixedString[i + 1] <= '9') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x30);
				}
				else if (fixedString[i + 1] >= 'a' && fixedString[i + 1] <= 'f') {
					bytestring[j] = bytestring[j] + (fixedString[i + 1] - 0x57);
				}
				j++;
				i++;
			}
		}
	}
	return bytestring;
}

char* convertPacketFormatToString(unsigned char* packetStr, int byteLength) {

	if (byteLength < 2)
		return NULL;

	static char convertedStr[4096 * 5] = { 0 };

	char* tmpStr = (char*)calloc(sizeof(char), 4095 * 5);

	int i;
	unsigned char ch;

	for (i = 0; i < byteLength; i++) {
		ch = packetStr[i];
		sprintf(&convertedStr[i], "%.2X", ch);
		strcat(&tmpStr[i], &convertedStr[i]);
		strcat(tmpStr, " ");
	}
	return tmpStr;
}

int getPacketLength(char* grabbedTextPacket) {

	int length = 0;
	int i;

	for (i = 0; grabbedTextPacket[i] != '\0'; i++) {
		if (grabbedTextPacket[i] == ' ')
			length = length;
		else
			length++;
	}
	length = length / 2;
	return length;
}


unsigned short Opcode;
BOOL CreatePacket(LPBYTE data, DWORD length) {

	memcpy(&Opcode, (void*)&data[0], sizeof(uint16_t));

	Opcode = changeEndianness16(Opcode);

	PacketWriter* p = new PacketWriter();

	for (int i = 0; i < length; i++) {
		p->Write<byte>(data[i]);
	}

	SendPacketQueue.push(p);


	return TRUE;
}

#ifdef REGION_SERA 
uint32_t registerEDX = 0x9F1DD4;
uint32_t registerECX = 0xB51EC4;
#elif REGION_STEAM
uint32_t registerECX = 0xBFD1A8;
uint32_t registerEDX = 0xA9FF9C;
#endif

void __declspec(naked) SendPacket(uint32_t Length, LPBYTE inBuffer)
{

	__asm
	{
		mov ecx, registerECX
		mov edx, registerEDX
		push [esp+0x08]
		call Constants::_SendPacket
		ret
	}

}