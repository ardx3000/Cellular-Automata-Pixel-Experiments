#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define CELL_SIZE 10  // Increase this value to make the sand particles bigger

typedef enum {
    ELEMENT_NONE,
    ELEMENT_SAND,
    ELEMENT_WATER
} ElementType;

typedef struct cell {
    ElementType type;
} Cell;

void InitializeGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]);
void DropElement(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE], int mouseX, int mouseY, ElementType type);



#endif