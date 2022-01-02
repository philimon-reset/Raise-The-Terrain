#ifndef RAISE_H
#define RAISE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>

int random_N(int n_min, int n_max);
int random_color();
void random_points(int n_points, bool randomized_color, SDL_Renderer *renderer);
void draw_random_lines(int nr_lines, bool randomizecolor, SDL_Renderer *renderer);

#endif /*RAISE_H*/