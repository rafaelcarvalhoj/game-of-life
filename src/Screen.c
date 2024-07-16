#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "Screen.h"

int width;
int height;

extern int **matrix;

void init_dimensions() {
    initscr();
    noecho();
    curs_set(FALSE);

    getmaxyx(stdscr, height, width);

    if (width == 0 || height == 0) {
        fprintf(stderr, "Error initializing width and height\n");
        endwin();
        exit(1);
    }
}


void printScreen()
{
    clear();
    for(int y = 0 ; y < height ; y++)
    {
        for(int x = 0 ; x < width ; x++)
        {
            mvprintw(y, x, "%c", matrix[x][y] ? '*' : ' ');
        }
    }
    refresh();
}

