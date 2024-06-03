#include "physics.h"


//Add more particle behavior methods and update the switch case in UpdateGrid.
void UpdateSand(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH /CELL_SIZE], int i , int j){

    if (i + 1 < SCREEN_HEIGHT / CELL_SIZE && grid[i + 1][j].type == ELEMENT_NONE){

        grid[i][j].type = ELEMENT_NONE;
        grid[i + 1][j].type = ELEMENT_SAND;
    }
    else if (i + 1 < SCREEN_HEIGHT / CELL_SIZE){

        if (j > 0 && grid[i + 1][j - 1].type == ELEMENT_NONE){

            grid[i][j].type = ELEMENT_NONE;
            grid[i + 1][j - 1].type = ELEMENT_SAND;            
        }
        else if (j < SCREEN_WIDTH / CELL_SIZE - 1 && grid[i + 1][j + 1].type == ELEMENT_NONE){

            grid[i][j].type = ELEMENT_NONE;
            grid[i + 1][j + 1].type = ELEMENT_SAND;

        }
    }
} 



void UpdateGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]){

    for (int i = SCREEN_HEIGHT / CELL_SIZE - 1; i >= 0; i--){

        for (int j = 0; j < SCREEN_WIDTH / CELL_SIZE; j++){

            switch (grid[i][j].type)
            {
                case ELEMENT_SAND:
                    UpdateSand(grid, i, j);
                    break;
                //Add more cases fore different elements
            
            default:
                break;
            }
        }
    }

}