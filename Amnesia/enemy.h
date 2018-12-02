#pragma once

class EnemyPathFinder
{
public:
	char pad_0000[24]; //0x0000
	Vector m_vTo; //0x0018
}; 

class Enemy
{
public:
	char pad_0000[348]; //0x0000
	float m_fSpeed; //0x015C
	char pad_0160[736]; //0x0160
	char* m_szIdleAnim; //0x0440
	char pad_0444[260]; //0x0444
	class CharacterBodyNewton* m_pCharacterNewton; //0x0548
	char pad_054C[68]; //0x054C
	class EnemyPathFinder* m_pPathFinder; //0x0590
}; //Size: 0x09C0



class EnemyContainer
{
public:
	class EnemyContainer* m_pNext; //0x0000
	char pad_0004[4]; //0x0004
	class Enemy* m_pEnemy; //0x0008
};
