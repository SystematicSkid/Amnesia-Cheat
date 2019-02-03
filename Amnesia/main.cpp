#include "sdk.h"

void Init()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	if (!ints.Init())
		MessageBoxA(NULL, "Interfaces: Failed to init.", NULL, NULL);

	if (!hooks.Init())
		MessageBoxA(NULL, "Hooks: Failed to init.", NULL, NULL);

	while (true)
	{
		if (ints.address_game)
		{
			Game* game = ints.address_game;
			GameFunctions::SetFogActive(false);
			GameFunctions::SetFallDamageActive(false);
			if (game->m_pLocalPlayer)
			{
				Player* localent = game->m_pLocalPlayer;
				localent->m_fHealth = 100.f;
				localent->m_fOil = 100.f;
				localent->m_fSanity = 100.f;
				localent->m_fSpeed = 3.5f;
				localent->m_fJumpHeight = 10.f;
			}
		}
	}

}

DWORD __stdcall DllMain(HMODULE dll, DWORD callreason, void* reserved)
{
	if (callreason == DLL_PROCESS_ATTACH)
	{
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Init, NULL, NULL, NULL);
		return 1;
	}
	return 0;
}
