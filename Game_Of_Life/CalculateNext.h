#pragma once
#include "array"

constexpr int height = 900;

constexpr int width = 1600;

class CalculateNext
{
public:
	CalculateNext(std::array<std::array<bool, height>, width>& prev);
	~CalculateNext();
private:
	std::array<std::array<bool, height>, width> currentArray;
};

