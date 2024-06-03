#include "raylib.h"
#include <stdbool.h>
#include <stdlib.h>

#include "elements.h"
#include "physics.h"
#include "render.h"
#include "../include/menu.h"

int main (void){

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cellular Automaton - Particle Simulation");

    const int rows = SCREEN_HEIGHT / CELL_SIZE;
    const int cols = SCREEN_WIDTH / CELL_SIZE;

    Cell grid[rows][cols];
    InitializeGrid(grid);

    Menu menu;
    InitMenu(&menu);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
 
        UpdateMenu(&menu, grid);

        ElementType selectedElement = GetSelectedElement(&menu);

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();
            DropElement(grid, mouseX, mouseY, selectedElement);
        }

       UpdateGrid(grid);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawMyGrid(grid);
        DrawMyMenu(&menu);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}