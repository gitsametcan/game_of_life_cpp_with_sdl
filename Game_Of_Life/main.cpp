#include <SDL.h>
#include "TakeInput.h"
#include "Window.h"


int main(int argc, char* argv[]) {

	TakeInput takeInput("input.txt");
	Window window(takeInput.GetInput());


	return 0;
}
