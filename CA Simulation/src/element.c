#include "elements.h"

void InitializeGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE])
{
    // Initialize all cells to false
    for (int i = 0; i < SCREEN_HEIGHT / CELL_SIZE; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH / CELL_SIZE; j++)
        {
            grid[i][j].type = ELEMENT_NONE;
        }
    }
}

void DropElement(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE], int mouseX, int mouseY, ElementType type)
{
    int gridX = mouseX / CELL_SIZE;
    int gridY = mouseY / CELL_SIZE;

    if (gridX >= 0 && gridX < SCREEN_WIDTH / CELL_SIZE && gridY >= 0 && gridY < SCREEN_HEIGHT /CELL_SIZE){
        
        grid[gridY][gridX].type = type;
    }
}