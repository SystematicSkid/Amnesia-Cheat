#pragma once

class Game
{
public:
	char pad_0000[92]; //0x0000
	class MapHandler* m_pMapHandler; //0x005C
	char pad_0060[36]; //0x0060
	class Player* m_pLocalPlayer; //0x0084
};

