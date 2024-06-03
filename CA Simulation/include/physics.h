#ifndef PHYSICS_H
#define PHYSICS_H

#include "elements.h"
#include "menu.h"

void UpdateGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]);
void ResetMyGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]);

#endif