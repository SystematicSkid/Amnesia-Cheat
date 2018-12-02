#pragma once


class Player
{
public:
	char pad_0000[84]; //0x0000
	class CharacterBodyNewton* m_pCharacterNewton; //0x0054
	char pad_0058[44]; //0x0058
	float m_fHealth; //0x0084
	float m_fSanity; //0x0088
	float m_fOil; //0x008C
	char pad_0090[8]; //0x0090
	int32_t m_iTinderBoxes; //0x0098
	bool m_bIsInWater; //0x009C
	bool m_bIsRunning; //0x009D
	bool m_bIsJumping; //0x009E
	char pad_009F[37]; //0x009F
	float m_fLookSensitivity; //0x00C4
	float m_fHurtMoveSpeedMul; //0x00C8
	float m_fInsanityCollapseSpeedMul; //0x00CC
	char pad_00D0[12]; //0x00D0
	float m_fSpeedGain; //0x00DC
	float m_fSpeed; //0x00E0
	float m_fJumpHeight; //0x00E4
};
