#include "CalculateNext.h"

#include <iostream>

CalculateNext::CalculateNext(std::array<std::array<bool, width>, height>& prev)
{
	std::array<std::array<bool, width>, height> temp;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width;j++) {
			temp[i][j] = prev[i][j];
		}
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width;j++) {
			prev[i][j] = LifeOrDeath(LivingNeighbour(temp,j,i), temp[i][j]);
		}
	}
}

CalculateNext::~CalculateNext()
{
}


bool CalculateNext::LifeOrDeath(int livingNeighbour, bool currentState)
{
	if (currentState) {
		if (livingNeighbour < 2) return false;
		else if (livingNeighbour > 3) return false;
		else return true;
	}
	else {
		if (livingNeighbour == 3) return true;
		else return false;
	}
}

int CalculateNext::LivingNeighbour(std::array<std::array<bool, width>, height>& temp, int x, int y)
{
	int livingNeighbour = 0;

	int prev_x = -1, next_x = 1, prev_y = -1, next_y = 1;

	if (x == 0) prev_x = 0;

	if (x == width - 1) next_x = 0;

	if (y == 0) prev_y = 0;

	if (y == height - 1) next_y = 0;

	for (int j = prev_y; j <= next_y; j++) {
		for (int i = prev_x; i <= next_x; i++) {
			if (i == 0 && j == 0) continue;
			if (temp[y + j][x + i] == 1) livingNeighbour++;
		}
	}

	return livingNeighbour;
}
