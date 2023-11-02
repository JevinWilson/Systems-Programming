#ifndef GAME_OF_LIFE_H_INCLUDED
#define GAME_OF_LIFE_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BOARD_WIDTH 100
#define BOARD_HEIGHT 27

void init_board(unsigned char* board, int num_alive);
void init_board_special(unsigned char* board, const char* name);
void display_board(unsigned char* board);
int num_neighbors(unsigned char* board, int x, int y);
int next_state(unsigned char* board, int x, int y);
void next_generation(unsigned char* board);

#endif // GAME_OF_LIFE_H_INCLUDED
