#include "raylib.h"
#include "../include/menu.h"


void InitMenu(Menu *menu) {

    menu->selectedElement = ELEMENT_SAND;  // Default selected element
}

void UpdateMenu(Menu *menu, Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]) {

    if (IsKeyPressed(KEY_ONE)) {

        menu->selectedElement = ELEMENT_SAND;
    } 
    else if (IsKeyPressed(KEY_TWO)) {

        menu->selectedElement = ELEMENT_WATER;
    }
    else if (IsKeyPressed(KEY_R)){
        ResetMyGrid(grid);
    }
    // Add more elements as needed
}

void DrawMyMenu(Menu *menu) {

    DrawText("Press 1 for Sand", 8, 10, 16, (menu->selectedElement == ELEMENT_SAND) ? YELLOW : GRAY);
    DrawText("Press 2 for Water", 8, 40, 16, (menu->selectedElement == ELEMENT_WATER) ? YELLOW : GRAY);

    bool resetKeyPressed = IsKeyDown(KEY_R);

    DrawText("Press R to reset", 8, 70, 16, (resetKeyPressed) ? GREEN : GRAY);
    // Add more elements as needed
}

ElementType GetSelectedElement(Menu *menu) {
    return (ElementType) menu->selectedElement;
}
