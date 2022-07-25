# GrandoEspadaCheatChallenge
As a challenge I decided to see how quickly I could reverse engineer and develop a network packet sender + logger for this game, which was completed in approximately 3 hours

I've extended the program to fully encrypt and decrypt packets, which will allow us to make a clientless bot/headless.

This game uses a custom crypto made by iMC games, and has a call stack of..
ImcCrypt::NetCrypt
ImcCrypt::Crypt
ImcCrypt::_cb_encrypt
ImcCrypt::_ecb_encrypt

You can call Crypt to successfully encrypt packets. The game uses a static key of 4096 bytes, which does not change after patches. Similar to dragonnest, this game selects a key index based on packet length & opcode. We can rip the assembly code for each of the functions and use it in our own programs. This part was finished in about 3 hours.
