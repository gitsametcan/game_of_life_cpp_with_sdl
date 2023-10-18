#pragma once
#include <array>
#include <string>
#include <fstream>
#include "Constants.h"

class TakeInput
{
public:
	TakeInput(const std::string& input);
	~TakeInput();

	std::array<std::array<bool, width>, height>& GetInput();

private:
	std::array<std::array<bool, width>, height> inputArray;
};

