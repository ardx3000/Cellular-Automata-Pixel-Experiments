#include "raylib.h"
#include <stdbool.h>
#include <stdlib.h>

#include "elements.h"
#include "physics.h"
#include "render.h"

int main (void){

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cellular Automaton - Particle Simulation");

    const int rows = SCREEN_HEIGHT / CELL_SIZE;
    const int cols = SCREEN_WIDTH / CELL_SIZE;

    Cell grid[rows][cols];
    InitializeGrid(grid);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateGrid(grid);

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();
            DropElement(grid, mouseX, mouseY, ELEMENT_SAND);
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawMyGrid(grid);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}