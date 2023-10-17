#include "TakeInput.h"




TakeInput::TakeInput(const std::string& input)
{
	std::ifstream ifile(input);

	for (int i = 0; i < height;i++) {
		for (int j = 0;j < width; j++) {
			inputArray[i][j] = 0;
		}
	}

	std::string line;
	for (int i = 0; i < height;i++) {
		std::getline(ifile, line);
		for (int j = 0;j < width;j++) {
			inputArray[i][j] = (line[j]) - ((int)'0');
		}
		line.clear();
	}
}

TakeInput::~TakeInput()
{
}

std::array<std::array<bool, height>, width>& TakeInput::GetInput()
{
	return inputArray;
}

