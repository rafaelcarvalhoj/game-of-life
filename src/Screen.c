#include <stdio.h>
#include "Screen.h"

extern int width;
extern int height;

void printScreen()
{
    printf("Printing Screen %dx%d...\n", width, height);
}

void updateScreen()
{
    printf("Updating Screen...\n");
}
