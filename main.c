#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <time.h>
int random_N(int, int);
int random_color();

int width = 1200;
int height = 800;

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    int a, b, WX = 0, WY = 0, WX2 = 0, WY2 = 0;
    // altitude
    int al[] = {120, 60, 40, 60, 20, -20, -80, -120, 40, 20, 30, 30, -10, -40, -90, -110, 20, 30, 10, 06, -6, -20, -26, -90, 00, -6, 10, 10, -6, -20, -20, -40, -20, -20, -18, -14, -40, -20, -20, -30, -10, -10, -10, -10, -8, -20, -20, -30, 20, 10, 10, 10, 10, 04, 10, -10, 30, 24, 24, 22, 20, 18, 14, 16};
    // Create a SDL window
    SDL_Window *window = SDL_CreateWindow("Hello, SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    // for (a = 0; a < 65; a++)
    // {
    //     al[a] = random_N(-50, 100);
    // }
    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    bool running = true;
    SDL_Event event;
    // grid main
    int ***grid = malloc(sizeof(*grid) * 8);
    for (a = 0; a < 8; a++)
    {
        grid[a] = malloc(sizeof(**grid) * 8);
        for (b = 0; b < 8; b++)
        {
            grid[a][b] = malloc(sizeof(***grid) * 3);
        }
    }
    for (a = 0; a < 8; a++)
    {
        for (b = 0; b < 8; b++)
        {
            grid[a][b][0] = (120 * b) + 750;
            grid[a][b][1] = (a * 120) - 110;
            grid[a][b][2] = al[b + (8 * a)];
        }
    }
    while (running)
    {
        // Process events
        while (SDL_PollEvent(&event))
        {
            // check event type
            switch (event.type)
            {
            case SDL_QUIT:
                // shut down
                running = false;
                break;
            case SDL_KEYDOWN:
                // test keycode
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    // shut down
                    running = false;
                    break;
                }
                break;
            }
        }
        // BACKground color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // Clear screen
        SDL_RenderClear(renderer);
        // Draw
        // line color
        SDL_SetRenderDrawColor(renderer, 200, 50, 100, 255);
        for (a = 0; a < 7; a++)
        {
            for (b = 0; b < 7; b++)
            {
                //
                WX = 0.7 * grid[a][b][0] - 0.7 * grid[a][b][1];
                WY = (1 - 0.7) * grid[a][b][0] + (1 - 0.7) * grid[a][b][1] - grid[a][b][2];
                //
                WX2 = 0.7 * grid[a][b + 1][0] - 0.7 * grid[a][b + 1][1];
                WY2 = (1 - 0.7) * grid[a][b + 1][0] + (1 - 0.7) * grid[a][b + 1][1] - grid[a][b + 1][2];
                SDL_RenderDrawLine(renderer, WX, WY, WX2, WY2);
                //
                WX2 = 0.7 * grid[a + 1][b][0] - 0.7 * grid[a + 1][b][1];
                WY2 = (1 - 0.7) * grid[a + 1][b][0] + (1 - 0.7) * grid[a + 1][b][1] - grid[a + 1][b][2];
                SDL_RenderDrawLine(renderer, WX, WY, WX2, WY2);
            }
        }
        for (a = 0; a < 7; a++)
        {
            //
            WX = 0.7 * grid[a][b][0] - 0.7 * grid[a][b][1];
            WY = (1 - 0.7) * grid[a][b][0] + (1 - 0.7) * grid[a][b][1] - grid[a][b][2];
            //
            WX2 = 0.7 * grid[a + 1][b][0] - 0.7 * grid[a + 1][b][1];
            WY2 = (1 - 0.7) * grid[a + 1][b][0] + (1 - 0.7) * grid[a + 1][b][1] - grid[a + 1][b][2];
            SDL_RenderDrawLine(renderer, WX, WY, WX2, WY2);
        }
        for (b = 0; b < 7; b++)
        {
            //
            WX = 0.7 * grid[a][b][0] - 0.7 * grid[a][b][1];
            WY = (1 - 0.7) * grid[a][b][0] + (1 - 0.7) * grid[a][b][1] - grid[a][b][2];
            //
            WX2 = 0.7 * grid[a][b + 1][0] - 0.7 * grid[a][b + 1][1];
            WY2 = (1 - 0.7) * grid[a][b + 1][0] + (1 - 0.7) * grid[a][b + 1][1] - grid[a][b + 1][2];
            SDL_RenderDrawLine(renderer, WX, WY, WX2, WY2);
        }
        //Show what was drawn
        SDL_RenderPresent(renderer);
        // SDL_Delay(200);
    };
    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// void random_points(int n_points, bool randomized_color, SDL_Renderer *renderer)
// {
//     int i;
//     for (i = 0; i < n_points; i++)
//     {
//         if (randomized_color)
//         {
//             SDL_SetRenderDrawColor(renderer, random_color(), random_color(), random_color(), 255);
//         }
//         SDL_RenderDrawPoint(renderer, random_N(0, 1000), random_N(0, 1000));
//     }
// }

// void draw_random_lines(int nr_lines, bool randomizeColor, SDL_Renderer *renderer)
// {
//     int i;
//     for (i = 0; i < nr_lines; i++)
//     {
//         if (randomizeColor)
//         {
//             SDL_SetRenderDrawColor(renderer, random_color(), random_color(), random_color(), 255);
//         }
//         SDL_RenderDrawLine(renderer, random_N(0, width), random_N(0, height), random_N(0, width), random_N(0, height));
//     }
// }

int random_N(int n_min, int n_max)
{
    static bool init = false;

    if (!init)
    {
        init = true;
        srand(time(NULL));
    }
    return rand() % n_max + n_min;
}

int random_color()
{
    return random_N(0, 255);
}