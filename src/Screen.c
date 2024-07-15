#include <stdio.h>
#include <stdlib.h>
#include "Screen.h"

extern int width;
extern int height;

extern int **matrix;

void printScreen()
{
    for(int x = 0 ; x < width ; x++)
    {
        for(int y = 0 ; y < width ; y++)
        {
            printf("%c", matrix[x][y] ? '*' : ' ');
        }
        printf("\n");
    }
}

void clearScreen()
{
    if(system("clear"))
    {
        printf("Error cleaning screen!");
        exit(EXIT_FAILURE);
    }
}
