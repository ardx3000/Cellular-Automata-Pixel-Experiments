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
void UpdateWater(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE], int i, int j) {

    // Check if there's an empty space below, to the left, and to the right
    bool emptyBelow = (i + 1 < SCREEN_HEIGHT / CELL_SIZE) && (grid[i + 1][j].type == ELEMENT_NONE);
    bool emptyLeft = (j > 0) && (grid[i][j - 1].type == ELEMENT_NONE);
    bool emptyRight = (j < SCREEN_WIDTH / CELL_SIZE - 1) && (grid[i][j + 1].type == ELEMENT_NONE);

    // If there's an empty space below, move downwards
    if (emptyBelow) {

        grid[i][j].type = ELEMENT_NONE;
        grid[i + 1][j].type = ELEMENT_WATER;
    }
    // If there's an empty space to the left, move leftwards
    else if (emptyLeft && !emptyRight) {

        grid[i][j].type = ELEMENT_NONE;
        grid[i][j - 1].type = ELEMENT_WATER;
    }
    // If there's an empty space to the right, move rightwards
    else if (emptyRight && !emptyLeft) {

        grid[i][j].type = ELEMENT_NONE;
        grid[i][j + 1].type = ELEMENT_WATER;
    }
    // If there's no empty space below, to the left, or to the right, check diagonals
    else {

        // Check if there's an empty space diagonally left-down
        bool emptyLeftDown = (i + 1 < SCREEN_HEIGHT / CELL_SIZE) && (j > 0) && (grid[i + 1][j - 1].type == ELEMENT_NONE);
        // Check if there's an empty space diagonally right-down
        bool emptyRightDown = (i + 1 < SCREEN_HEIGHT / CELL_SIZE) && (j < SCREEN_WIDTH / CELL_SIZE - 1) && (grid[i + 1][j + 1].type == ELEMENT_NONE);

        // If there's an empty space diagonally left-down, move there
        if (emptyLeftDown) {

            grid[i][j].type = ELEMENT_NONE;
            grid[i + 1][j - 1].type = ELEMENT_WATER;
        }
        // If there's an empty space diagonally right-down, move there
        else if (emptyRightDown) {
            
            grid[i][j].type = ELEMENT_NONE;
            grid[i + 1][j + 1].type = ELEMENT_WATER;
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
                case ELEMENT_WATER:
                 UpdateWater(grid, i,j);
                 break;
                 
            default:
                break;
            }
        }
    }

}

void ResetMyGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]) {

    InitializeGrid(grid);
}