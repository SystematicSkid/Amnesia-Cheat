#pragma once

class GameFunctions
{
public:
	static void SetFogActive(bool b);
	static void SetFallDamageActive(bool b);
	static bool DoesEntityExist(std::string name);
};