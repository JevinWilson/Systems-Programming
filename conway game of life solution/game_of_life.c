#include "game_of_life.h"


// We'll talk about this a bit later, but declaring a function as static like this
// makes it so we can only see it in this file (kind of a "hidden" function)
static int point_to_index(int x, int y)
{
    return y * BOARD_WIDTH + x;
}

void init_board(unsigned char* board, int num_alive)
{
    // Clear the board
    memset(board, 0, sizeof(char) * BOARD_HEIGHT * BOARD_WIDTH);

    int num_placed = 0;

    if (num_alive > BOARD_WIDTH * BOARD_HEIGHT)
        num_alive = BOARD_WIDTH * BOARD_HEIGHT;

    while (num_placed < num_alive)
    {
        int x = rand() % BOARD_WIDTH;
        int y = rand() % BOARD_HEIGHT;
        int index = point_to_index(x, y);

        if (board[index] == 0)
        {
            board[index] = 1;
            num_placed++;
        }
    }
}


void init_board_special(unsigned char* board, const char* name)
{
    init_board(board, 0);

    if (!strcmp(name, "oscillators"))
    {
        int x1 = BOARD_WIDTH / 4;
        int x2 = BOARD_WIDTH / 2;
        int x3 = BOARD_WIDTH * 3 / 4;
        int y1 = BOARD_HEIGHT / 4;
        int y2 = BOARD_HEIGHT / 2;
        int y3 = BOARD_HEIGHT * 3 / 4;

        // blinker in upper-left
        board[point_to_index(x1 - 1, y1)] = 1;
        board[point_to_index(x1, y1)] = 1;
        board[point_to_index(x1 + 1, y1)] = 1;

        // blinker in middle-left
        board[point_to_index(x1, y2 - 1)] = 1;
        board[point_to_index(x1, y2)] = 1;
        board[point_to_index(x1, y2 + 1)] = 1;

        // toad in lower-left
        board[point_to_index(x1 + 1, y3 + 2)] = 1;
        board[point_to_index(x1 + 1, y3 + 3)] = 1;
        board[point_to_index(x1 + 2, y3 + 4)] = 1;
        board[point_to_index(x1 + 3, y3 + 1)] = 1;
        board[point_to_index(x1 + 4, y3 + 2)] = 1;
        board[point_to_index(x1 + 4, y3 + 3)] = 1;

        // pulsar in middle-top (this one was kind of long, so I tried another approach)
        int pulsar_values[] = {0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
                               1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
                               1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
                               0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0,
                               1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
                               1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
                               1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0};
        for (int y = 0, offset = 0; y < 13; y++)
        {
            for (int x = 0; x < 13; x++, offset++)
                board[point_to_index(x2 + x, y1 + y)] = pulsar_values[offset];
        }

        int pentadecahedron[] = {0, 0, 0, 1, 1, 1, 0, 0, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 1, 0, 0, 0, 0, 0, 1, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 1, 0, 0, 0, 0, 0, 0, 0, 1,
                                 1, 0, 0, 0, 0, 0, 0, 0, 1,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 1, 0, 0, 0, 0, 0, 1, 0,
                                 0, 0, 1, 0, 0, 0, 1, 0, 0,
                                 0, 0, 0, 1, 1, 1, 0, 0, 0};
        for (int y = 0, offset = 0; y < 10; y++)
        {
            for (int x = 0; x < 9; x++, offset++)
                board[point_to_index(x3 + x, y2 + y)] = pentadecahedron[offset];
        }
    }
    else if (!strcmp(name, "gosper"))
    {
        // left sqaure
        board[point_to_index(1, 5)] = 1;
        board[point_to_index(2, 5)] = 1;
        board[point_to_index(1, 6)] = 1;
        board[point_to_index(2, 6)] = 1;

        // right square
        board[point_to_index(35, 3)] = 1;
        board[point_to_index(36, 3)] = 1;
        board[point_to_index(35, 4)] = 1;
        board[point_to_index(36, 4)] = 1;

        // circle-y thing in the middle-left
        board[point_to_index(14, 3)] = 1;
        board[point_to_index(13, 3)] = 1;
        board[point_to_index(12, 4)] = 1;
        board[point_to_index(11, 5)] = 1;
        board[point_to_index(11, 6)] = 1;
        board[point_to_index(11, 7)] = 1;
        board[point_to_index(12, 8)] = 1;
        board[point_to_index(13, 9)] = 1;
        board[point_to_index(14, 9)] = 1;
        board[point_to_index(16, 4)] = 1;
        board[point_to_index(17, 5)] = 1;
        board[point_to_index(17, 6)] = 1;
        board[point_to_index(17, 7)] = 1;
        board[point_to_index(18, 6)] = 1;
        board[point_to_index(16, 8)] = 1;
        board[point_to_index(15, 6)] = 1;

        // glider thing in the middle-right
        board[point_to_index(25, 1)] = 1;
        board[point_to_index(25, 2)] = 1;
        board[point_to_index(23, 2)] = 1;
        board[point_to_index(23, 6)] = 1;
        board[point_to_index(25, 6)] = 1;
        board[point_to_index(25, 7)] = 1;
        board[point_to_index(21, 3)] = 1;
        board[point_to_index(22, 3)] = 1;
        board[point_to_index(21, 4)] = 1;
        board[point_to_index(22, 4)] = 1;
        board[point_to_index(21, 5)] = 1;
        board[point_to_index(22, 5)] = 1;
    }
}


void display_board(unsigned char* board)
{
    int offset = 0;

    // First decorative row
    printf("+");
    for (int i = 0; i < BOARD_WIDTH; i++)
        printf("=");
    printf("+\n");

    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        printf("|");
        for (int j = 0; j < BOARD_WIDTH; j++, offset++)
        {
            if (board[offset] == 1)
                printf("X");
            else
                printf(".");
        }
        printf("|\n");
    }

    // Last decorative row
    printf("+");
    for (int i = 0; i < BOARD_WIDTH; i++)
        printf("=");
    printf("+\n");
}


int num_neighbors(unsigned char* board, int x, int y)
{
    // These two arrays are the x/y coordinates of the neighbors of the given
    // cell where the indices are as follows:
    // 0 1 2
    // 3 - 4
    // 5 6 7
    // Warning: these values could be off the map!
    int neighbor_x[] = {x - 1, x,     x + 1, x - 1, x + 1, x - 1, x,     x + 1};
    int neighbor_y[] = {y - 1, y - 1, y - 1, y,     y,     y + 1, y + 1, y + 1};

    int num_alive = 0;
    for (int i = 0; i < 8; i++)
    {
        // I'm taking advantage of something called SHORT-CIRCUIT evaluation of booleans
        // here.  If an and statement condition is false, remaining clauses are ignored.
        // That's a good thing in this case because I'm checking to make sure it's a valid
        // position first and THEN checking the value at the board
        if (neighbor_x[i] >= 0 && neighbor_x[i] < BOARD_WIDTH &&
            neighbor_y[i] >= 0 && neighbor_y[i] < BOARD_HEIGHT &&
            board[point_to_index(neighbor_x[i], neighbor_y[i])] == 1)
            num_alive++;

    }

    return num_alive;
}


int next_state(unsigned char* board, int x, int y)
{
    int alive_neighbors = num_neighbors(board, x, y);
    int my_index = point_to_index(x, y);
    if (board[my_index] == 1)
    {
        if (alive_neighbors < 2 || alive_neighbors > 3)
            return 0;
        else
            return 1;
    }
    else if (alive_neighbors == 3)
        return 1;
    else
        return 0;
}


void next_generation(unsigned char* board)
{
    // Super important -- we have to make a copy of the board and work from that.
    // I chose to make the copy of the current state, but make changes to the current
    unsigned char old_board[BOARD_WIDTH * BOARD_HEIGHT];
    memcpy(old_board, board, sizeof(char) * BOARD_WIDTH * BOARD_HEIGHT);

    // Now, go through each cell in the OLD board, get its new state and change that
    // in the CURRENT board
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            int index = point_to_index(x, y);
            board[index] = next_state(old_board, x, y);
        }
    }
}
