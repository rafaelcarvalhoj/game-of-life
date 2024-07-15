#ifndef GAME_H
#define GAME_H

int **allocMap();

void freeMap(int **map);

int countLiveAdj(int x, int y);

void nextStateCell(int **newMatrix, int x, int y, int adjCount);

int sameState(int **matrix1, int **matrix2);

void updateMap();

#endif // GAME_H
