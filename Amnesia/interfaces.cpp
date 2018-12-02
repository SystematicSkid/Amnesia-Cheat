#include "sdk.h"

bool Interfaces::Init()
{
	address_game = *(Game**)((DWORD)GetModuleHandle(0) + 0x768C54);
	if (!address_game)
		return false;
	return true;
}

Interfaces ints;