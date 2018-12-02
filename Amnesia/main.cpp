#include "sdk.h"

void Init()
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	if (!ints.Init())
		MessageBoxA(NULL, "Interfaces: Failed to init.", NULL, NULL);

	printf("Initialized\n");

	while (true)
	{
		if (ints.address_game)
		{
			Game* game = ints.address_game;
			if (game->m_pLocalPlayer)
			{
				Player* localent = game->m_pLocalPlayer;
				localent->m_fHealth = 100.f;
				localent->m_fOil = 100.f;
				localent->m_fSanity = 100.f;
				localent->m_fSpeed = 3.5f;
				localent->m_fJumpHeight = 10.f;
			}
			if (game->m_pMapHandler)
			{
				MapHandler* map_handler = game->m_pMapHandler;
				if (map_handler->m_CurrentMap)
				{
					Map* current_map = map_handler->m_CurrentMap;
					if (current_map->m_pEntities)
					{
						EnemyContainer* enemy_container = current_map->GetEnemyContainer();
						Enemy* current_enemy = enemy_container->m_pEnemy;
						if (current_enemy)
						{
							/*printf("Anim: %s\n", current_enemy->m_szIdleAnim);
							printf("Name: %s\n", (current_enemy + 0x4));*/
							//current_enemy->m_fSpeed = 0.f;
						}
						

					}
				}
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
