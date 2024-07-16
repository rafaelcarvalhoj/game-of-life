#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include "Game.h"
#include "Screen.h"

extern int width;
extern int height;
int **matrix;

int **allocMap()
{
    int **newMatrix = (int **)calloc(width, sizeof(int*));

    if (newMatrix == NULL)
    {
        endwin();
        fprintf(stderr, "Error initializing matrix\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < width ; i++)
    {
        newMatrix[i] = (int *)calloc(height, sizeof(int));
        if (newMatrix[i] == NULL)
        {
            endwin();
            fprintf(stderr, "Error initializing matrix\n");
            exit(EXIT_FAILURE);
        }
    }
    return newMatrix;
}

void freeMap(int **map)
{
    for(int i = 0; i < width ; i++)
        free(map[i]);
    free(map);
}

int countLiveAdj(int x, int y)
{
    int adjLive = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height && matrix[nx][ny])
            {
                adjLive++;
            }
        }
    }
    return adjLive;
}

void nextStateCell(int **newMatrix, int y, int x, int adjCount)
{
    /* Next State Rules
       1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
       2. Any live cell with two or three live neighbours lives on to the next generation.
       3. Any live cell with more than three live neighbours dies, as if by overpopulation.
       4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    */
    if(matrix[x][y])
    {
        if(adjCount < 2 || adjCount > 3)
            newMatrix[x][y] = 0;
        else
            newMatrix[x][y] = 1;
    }
    else
    {
        if(adjCount == 3)
            newMatrix[x][y] = 1;
        else
            newMatrix[x][y] = 0;
    }
}

int sameState(int **matrix1, int **matrix2)
{
    for(int y = 0 ; y < height ; y++)
        for(int x = 0 ; x < width ; x++)
            if(matrix1[x][y] != matrix2[x][y])
                return 0;
    return 1;
}

void updateMap()
{
    int **tmp = allocMap(); 
    for(int y = 0 ; y < height ; y++)
        for(int x = 0 ; x < width ; x++)
        {
            int countAdj = countLiveAdj(x, y);
            nextStateCell(tmp, y,  x, countAdj);
        }
    if(sameState(matrix, tmp))
    {
        printw("Game of Life finished\nPress any key to leave.");
        getchar();
        endwin();
        freeMap(matrix);
        freeMap(tmp);
        exit(0);
    }
    freeMap(matrix);
    matrix = tmp;
}
