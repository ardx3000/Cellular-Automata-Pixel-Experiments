#include "raylib.h"
#include <stdbool.h>
#include <stdlib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define CELL_SIZE 15  // Increase this value to make the sand particles bigger

typedef struct Cell {
    bool hasSand;
} Cell;

void InitializeGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]);
void UpdateGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]);
void DrawSandGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]);
void DropSand(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE], int mouseX, int mouseY);

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cellular Automaton - Sand Simulation");

    const int rows = SCREEN_HEIGHT / CELL_SIZE;
    const int cols = SCREEN_WIDTH / CELL_SIZE;

    Cell grid[rows][cols];
    InitializeGrid(grid);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        UpdateGrid(grid);

        // Check for mouse input to drop sand
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();
            DropSand(grid, mouseX, mouseY);
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        DrawSandGrid(grid);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void InitializeGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE])
{
    // Initialize all cells to false
    for (int i = 0; i < SCREEN_HEIGHT / CELL_SIZE; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH / CELL_SIZE; j++)
        {
            grid[i][j].hasSand = false;
        }
    }
}

void UpdateGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE])
{
    // Iterate through each cell
    for (int i = SCREEN_HEIGHT / CELL_SIZE - 1; i >= 0; i--)
    {
        for (int j = 0; j < SCREEN_WIDTH / CELL_SIZE; j++)
        {
            if (grid[i][j].hasSand)
            {
                // Check if the cell below is empty and within bounds
                if (i + 1 < SCREEN_HEIGHT / CELL_SIZE && !grid[i + 1][j].hasSand)
                {
                    // Move the sand particle down
                    grid[i][j].hasSand = false;
                    grid[i + 1][j].hasSand = true;
                }
                else 
                {
                    //Check if sand can fall left
                    if(j > 0 && !grid[i][j - 1].hasSand && !grid[i + 1][j - 1].hasSand)
                    {
                        grid[i][j].hasSand = false;
                        grid[i + 1][j - 1].hasSand = true;
                    }
                    //Check if sand can fall right
                    else if( j < SCREEN_WIDTH / CELL_SIZE - 1 && !grid[i][j +1].hasSand && !grid[i + 1][j + 1].hasSand)
                    {
                        grid[i][j].hasSand = false;
                        grid[i + 1][j + 1].hasSand = true;
                    }
                }
            }
        }
    }
}

void DrawSandGrid(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE])
{
    for (int i = 0; i < SCREEN_HEIGHT / CELL_SIZE; i++)
    {
        for (int j = 0; j < SCREEN_WIDTH / CELL_SIZE; j++)
        {
            if (grid[i][j].hasSand)
            {
                // Draw a rectangle for each sand particle
                DrawRectangle(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE, BROWN);
            }
        }
    }
}

void DropSand(Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE], int mouseX, int mouseY)
{
    // Convert mouse coordinates to grid indices
    int gridX = mouseX / CELL_SIZE;
    int gridY = mouseY / CELL_SIZE;

    // Drop sand at the clicked position
    if (gridX >= 0 && gridX < SCREEN_WIDTH / CELL_SIZE && gridY >= 0 && gridY < SCREEN_HEIGHT / CELL_SIZE)
    {
        grid[gridY][gridX].hasSand = true;
    }
}
