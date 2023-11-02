#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#ifndef gameoflife_h
#define gameoflife_h

//grid dimension
#define game_width 10
#define game_height 20

//functions
void startGrid(int grid[game_height][game_width]);
void printGrid(int grid[game_height][game_width]);
void updateGrid(int grid[game_height][game_width]);

#endif