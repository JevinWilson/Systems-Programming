#include "gameoflife.h"

//start board randomly
void startGrid(int grid[game_height][game_width])
{
    for (int i = 0; i < game_height; i++)
    {
        for (int j = 0; j < game_width; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

//print the grid
void printGrid(int grid[game_height][game_width])
{
    //clear term to make cleaner
    system("cls");
    for (int i = 0; i < game_height; i++)
    {
        for (int j = 0; j < game_width; j++)
        {
            if (grid[i][j] == 0)
            {
                printf(".");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
    //sleep to control the speed
    //usleep(100000);
}

//update grid (motion effect)
void updateGrid(int grid[game_height][game_width])
{
    int newGrid[game_height][game_width];
    for (int i = 0; i < game_height; i++)
    {
        for (int j = 0; j < game_width; j++)
        {
            if (grid[i][j] == 0)
            {
                printf(".");
            }
            else
            {
                printf("#");
            }
        }
    }

    //copy new grid to original grid
    for (int i = 0; i < game_height; i++)
    {
        for (int j = 0; j < game_width; j++)
        {
            grid[i][j] = newGrid[i][j];
        }
    }    
}