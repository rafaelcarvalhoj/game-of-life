#include "Game.h"
#include <stdlib.h>
#include <stdio.h>

void allocMap(int **matrix, int width, int height)
{
   matrix = (int **)calloc(width, sizeof(int*));

   if (matrix == NULL)
   {
      printf("Error");
      exit(EXIT_FAILURE);
   }

   for(int i = 0; i < width ; i++)
   {
      matrix[i] = calloc(height, sizeof(int*));
      if (matrix[i] == NULL)
      {
         printf("Error");
         exit(EXIT_FAILURE);
      }
   }
}

void freeMap(int **matrix, int width)
{
   for(int i = 0; i < width ; i++)
      free(matrix[i]);
   free(matrix);
}
