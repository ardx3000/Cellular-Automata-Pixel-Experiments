#include "render.h"

void DrawMyGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]){

    for (int i = 0; i < SCREEN_HEIGHT / CELL_SIZE; i++){

        for (int j = 0; j < SCREEN_WIDTH / CELL_SIZE ; j++){

            switch (grid[i][j].type)
            {
                case ELEMENT_SAND:
                    DrawRectangle(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE, BROWN);
                    break;
                case ELEMENT_WATER:
                    DrawRectangle(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE, BLUE);
                    break;
            
            default:
                break;
            }
        }
    }
}