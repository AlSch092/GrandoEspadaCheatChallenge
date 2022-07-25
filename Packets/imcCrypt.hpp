#pragma once
#include <Windows.h>


namespace imcCrypt
{
	typedef BYTE bf_key_st;

  static int GetNumBlock(const int dataLen);
  
	static int Encrypt(const unsigned __int8 *pDataIn, unsigned __int8 *pDataOut, const int dataLen, const bf_key_st *key); //returns # of bytes encrypted
	static void Decrypt(const unsigned __int8 *pDataIn, unsigned __int8 *pDataOut, const int dataLen, const bf_key_st *key); //this one doesnt return a length

	static UINT16 _BF_ebc_encrypt(LPBYTE data, int Length, LPVOID key, bool DecryprOrEncrypt); //same symbol names as from official source code.. this function is called by Decrypt as well as Encrypt, and the 4th parameter changes from 0 to 1 respectively
	
	static UINT16 _BF_encrypt(LPVOID, LPVOID);
	static UINT16 _BF_decrypt(LPVOID, LPVOID);
  
  static const BYTE key[] = { insert key as array here... };
}
