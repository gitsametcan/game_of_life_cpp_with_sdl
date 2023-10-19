#include "Window.h"

Window::Window(std::array<std::array<bool, width>, height>& rend)
{
    window = SDL_CreateWindow(
        "Conway's Game of Life",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        s_width,
        s_height,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Uint64 prevTimer = SDL_GetTicks();

    while (!exit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                exit = true;
            }
            if (e.type == SDL_MOUSEMOTION) {
                SDL_GetMouseState(&mouseX, &mouseY);
            }

            if (e.type == SDL_MOUSEBUTTONDOWN) {
                buttondown = true;
            }
            if (e.type == SDL_MOUSEBUTTONUP) {
                buttondown = false;
            }
        }

        if (buttondown) {
            rend[mouseY / edge][mouseX / edge] = 1;
        }

        SDL_SetRenderDrawColor(renderer, 0xEF, 0xEF, 0xEF, 0xFF);
        if (counter >= 500) {
            counter = 0;
            SDL_RenderClear(renderer);
            Render(rend);
            CalculateNext calc(rend);
            calc.~CalculateNext();
        }
        SDL_RenderPresent(renderer);
        //__debugbreak();


        prevTimer = timer;
        timer = SDL_GetTicks();
        deltaTime = timer - prevTimer;
        counter += deltaTime;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
    SDL_Quit();
}

Window::~Window()
{
}

void Window::Render(std::array<std::array<bool, width>, height>& rend)
{
    SDL_Rect rect = { 0, 0, edge, edge };
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (rend[i][j] == 0) {
                continue;
            }
            rect.x = j * edge;
            rect.y = i * edge;
            SDL_SetRenderDrawColor(renderer, 0x00, 0x80, 0x80, 0xFF);
            SDL_RenderFillRect(renderer, &rect);
            
        }
    }
}
