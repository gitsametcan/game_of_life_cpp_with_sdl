#pragma once
#include <array>
#include "Constants.h"

class CalculateNext
{
public:
	CalculateNext(std::array<std::array<bool, width>, height>& prev);
	~CalculateNext();
private:
	bool LifeOrDeath(int livingNeighbour, bool currentState);
	int LivingNeighbour(std::array<std::array<bool, width>, height>& temp,int x, int y);
};

