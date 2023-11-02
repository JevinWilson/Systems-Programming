#include "game_of_life.h"

int main()
{
    unsigned char B[BOARD_WIDTH * BOARD_HEIGHT];
    //init_board(B, 300);
    init_board_special(B, "oscillators");
    //init_board_special(B, "gosper");
    display_board(B);
    while (1)
    {
        char prompt[100];
        printf(">> ");
        fgets(prompt, 99, stdin);

        // I thought it was supposed to removed this, but...it appears as if fgets stops
        // reading characters once it sees the newline character (when we press enter), but...
        // it keeps the newline in there.  This code should remove the trailing newling
        prompt[strlen(prompt) - 1] = '\0';

        if (!strcmp(prompt, "quit") || !strcmp(prompt, "exit") || !strcmp(prompt, "q"))
            break;

        next_generation(B);
        display_board(B);
    }

    return 0;
}
