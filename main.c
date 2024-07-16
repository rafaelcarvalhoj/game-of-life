#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include "src/Screen.h"
#include "src/Game.h"

extern int **matrix;

int main(int argc, char **argv)
{
    init_dimensions();

    matrix = allocMap();

    printw("Game of life...\nPress any key to start.");
    getch();
    while(1)
    {
        printScreen();
        usleep(99999);
        updateMap();
    }
    return 0;
}
