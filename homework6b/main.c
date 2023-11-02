#include "gameoflife.h"

int main()
{
    int grid[game_height][game_width];
    int updateFlag = 1;

    //random num gen
    srand(time(NULL));
    //initialize the grid
    startGrid(grid);
    //game loop
    while (1)
    {
        printGrid(grid);
        if (updateFlag)
        {
            updateGrid(grid);
            updateFlag = 0;
        }
        //check enter key is pressed
        if (getchar() == '\n')
        {
            updateFlag = 1;
        }
    }
    return 0;
    
}