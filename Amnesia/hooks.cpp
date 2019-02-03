#include "sdk.h"
#include "PolyHook.hpp"

using fnGetEntity = char(__cdecl*)(int, int, int, int);
fnGetEntity oGetEntity;

PLH::X86Detour* GetEntityHook;

char __cdecl hkGetEntity(int a1, int a2, int a3, int a4)
{
	int v4 = a1;
	if (*(DWORD *)(v4 + 20) >= 0x10u)
		v4 = *(DWORD *)v4;
	printf("GetEnity: %s\n", v4);
	return oGetEntity(a1,a2,a3,a4);
}

bool Hooks::Init()
{
	GetEntityHook = new PLH::X86Detour();
	GetEntityHook->SetupHook((BYTE*)((DWORD)GetModuleHandle(0) + 0xD5D50), (BYTE*)&hkGetEntity);
	if (!GetEntityHook->Hook())
		return false;
	oGetEntity = GetEntityHook->GetOriginal<fnGetEntity>();

	return true;
}

Hooks hooks;