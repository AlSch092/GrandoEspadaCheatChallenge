#pragma once
#include <Windows.h>


namespace Encryption
{
	LPBYTE EncryptData(LPBYTE Data, int Length);
	void LookupKeyFromTable1();
	void LookupKeyFromTable2();
}