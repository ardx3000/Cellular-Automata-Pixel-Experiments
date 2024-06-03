#ifndef MENU_H
#define MENU_H

#include "elements.h"
#include "physics.h"

typedef struct Menu {
    int selectedElement;
} Menu;

void InitMenu(Menu *menu);
void UpdateMenu(Menu *menu, Cell grid[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE]);
void DrawMyMenu(Menu *menu);
ElementType GetSelectedElement(Menu *menu);

#endif 
