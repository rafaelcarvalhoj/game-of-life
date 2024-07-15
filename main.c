#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "src/Screen.h"
#include "src/Game.h"

const int width = 20;
const int height = 20;
extern int **matrix;

int main(int argc, char **argv)
{
    matrix = allocMap();
    printf("Game of life...\n");
    while(1)
    {
        printScreen();
        usleep(99999);
        clearScreen();
        updateMap();
    }
    return 0;
}
