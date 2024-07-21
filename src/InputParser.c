#include "InputParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

extern int **matrix;
extern int width;
extern int height;


void processInput(FILE* input_path)
{
    if (input_path == NULL)
    {
        endwin();
        fprintf(stderr, "Error initializing matrix\n");
        exit(EXIT_FAILURE);
    }
    
    char **content = malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        content[i] = malloc(width * sizeof(char));
    }
    
    int i = 0, j = 0;
    while (fgets(content[j], width, input_path) != NULL && j < height)
    {
        i = MAX(i, strlen(content[j]));
        j++;
    }
    --i;
     
    if (i < width && j < height)
    {
        int startWidth = (width - i) / 2;
        int startHeight = (height - j) / 2;

        printw("Content read from the file:\n");
        for (int y = 0; y < j; y++) {
            printw("%s", content[y]);
        }
        printw("INIT STATE SIZE: %dx%d\n", i, j);
        refresh();
        for (int y = 0; y < j; y++)
        {
            for (int x = 0; x < strlen(content[y]); x++)
            {
                if (content[y][x] == '*')
                {
                    matrix[startWidth + x][startHeight + y] = 1;
                }
            }
        }
        sleep(1);
        printw("1 ");
        refresh();
        sleep(1);
        printw("2 ");
        refresh();
        sleep(1);
        printw("3...\n");
        refresh();
        sleep(1);
        clear();
    }

    for (int i = 0; i < height; i++) {
        free(content[i]);
    }
    free(content);
    fclose(input_path);
}
