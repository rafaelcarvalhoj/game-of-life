#include <stdlib.h>
#include <stdio.h>
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
        printf("Error");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < width ; i++)
    {
        newMatrix[i] = (int *)calloc(height, sizeof(int));
        if (newMatrix[i] == NULL)
        {
            printf("Error");
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

void nextStateCell(int **newMatrix, int x, int y, int adjCount)
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
    for(int x = 0 ; x < width ; x++)
        for(int y = 0 ; y < width ; y++)
            if(matrix1[x][y] != matrix2[x][y])
                return 0;
    return 1;
}

void updateMap()
{
    int **tmp = allocMap(); 
    for(int x = 0 ; x < width ; x++)
        for(int y = 0 ; y < width ; y++)
        {
            int countAdj = countLiveAdj(x, y);
            nextStateCell(tmp, x,  y, countAdj);
        }
    if(sameState(matrix, tmp))
    {
        printf("Game of Life finished\n");
        printScreen();
        sleep(5);
        exit(0);
    }
    freeMap(matrix);
    matrix = tmp;
}
