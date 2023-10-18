#include "CalculateNext.h"

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
			prev[i][j] = LifeOrDeath(LivingNeighbour(temp,i,j), temp[i][j]);
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

	int prev_x = -1, next_x = -1, prev_y = -1, next_y = -1;

	if (x == 0) prev_x = 0;

	if (x == width - 1) prev_x = 0;

	if (y == 0) prev_y = 0;

	if (y == height - 1) prev_y = 0;

	for (int i = prev_x; i <= prev_x; i++) {
		for (int j = prev_y; j <= prev_y; j++) {
			if (i != 0 && j != 0) {
				if (temp[x + i][y + j] == 1) livingNeighbour++;
			}
		}
	}

	return livingNeighbour;
}
