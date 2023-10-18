#include "Window.h"

void Window::Render()
{
    SDL_Rect rect = { 0, 0, edge, edge };
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < 16 * MULTIPLIER; j++) {
            if (rend[i][j] == 0) {
                continue;
            }
            rect.x = j * edge;
            rect.y = i * edge;
            SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0x80, 0xFF);
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    for (int i = 0; i < 9 * MULTIPLIER; i++) {
        for (int j = 0; j < 16 * MULTIPLIER; j++) {
            prev[i][j] = rend[i][j];
        }
    }
}
