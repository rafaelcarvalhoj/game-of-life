#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include "src/Screen.h"
#include "src/Game.h"
#include "src/InputParser.h"

extern int **matrix;

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file_path for start state>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    init_dimensions();

    matrix = allocMap();

    processInput(input_file);

    printw("Game of life...\nPress any key to start.");
    for(int y = 2 ; y < height ; y++)
    {
        for(int x = 0 ; x < width ; x++)
        {
            mvprintw(y, x, "%c", matrix[x][y] ? '*' : ' ');
        }
    }
    refresh();
    getch();

    while(1)
    {
        printScreen();
        usleep(99999);
        updateMap();
    }
    return 0;
}
