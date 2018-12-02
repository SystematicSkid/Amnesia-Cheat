#pragma once
class Map
{
public:
	char pad_0000[348]; //0x0000
	class EnemyContainer** m_pEntities; //0x015C
	char pad_0160[36]; //0x0160

	EnemyContainer* GetEnemyContainer()
	{
		return **(EnemyContainer***)(this + 0x15C);
	}
}; //Size: 0x0184

class MapHandler
{
public:
	char pad_0000[96]; //0x0000
	class Map* m_CurrentMap; //0x0060
	char pad_0064[32]; //0x0064
}; //Size: 0x0084
