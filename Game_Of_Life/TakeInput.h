#pragma once
#include <array>
#include <string>
#include <fstream>

constexpr int height = 900;

constexpr int width = 1600;

class TakeInput
{
public:
	TakeInput(const std::string& input);
	~TakeInput();

	std::array<std::array<bool, height>, width>& GetInput();

private:
	std::array<std::array<bool, height>, width> inputArray;
};

