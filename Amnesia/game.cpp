#include "sdk.h"

void GameFunctions::SetFogActive(bool b)
{
	using fnFunction = int(__stdcall*)(bool a1);
	fnFunction Function = (fnFunction)((DWORD)GetModuleHandle(0) + 0xD1000); // 55 8B EC A1 ? ? ? ? 8B 48 5C 8B 51 60 8B 42 5C 
	Function(b);
}

void GameFunctions::SetFallDamageActive(bool b)
{
	using fnFunction = int(__stdcall*)(bool a1);
	fnFunction Function = (fnFunction)((DWORD)GetModuleHandle(0) + 0xD1950); // 55 8B EC A1 ? ? ? ? 8B 88 ? ? ? ? 8A 55 08 88 51 78 	
	Function(b);
}

bool GameFunctions::DoesEntityExist(std::string name)
{
	using fnFunction = bool(__stdcall*)(std::string a1);
	fnFunction Function = (fnFunction)((DWORD)GetModuleHandle(0) + 0xD1F10); 
	return Function(name);
}
