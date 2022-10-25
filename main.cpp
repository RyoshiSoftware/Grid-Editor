#include "raylib.h"
#include "Grid.h"

int main()
{
    int windowWidth{860};
    int windowHeight{540};

    InitWindow(windowWidth, windowHeight, "Grid Prototype");

    Grid testGrid(256, 256);
    testGrid.createCells();

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        testGrid.tick();

        EndDrawing();
    }
    CloseWindow();
}