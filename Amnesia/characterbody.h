#pragma once

class CharacterBodyNewton
{
public:
	char pad_0000[32]; //0x0000
	float m_fFallSpeed; //0x0020
	char pad_0024[16]; //0x0024
	float m_fMaybeGravity; //0x0034
	char pad_0038[4]; //0x0038
	Vector m_fGravity; //0x003C
	Vector m_vOrigin; //0x0048
	char pad_0054[52]; //0x0054
}; //Size: 0x0088
