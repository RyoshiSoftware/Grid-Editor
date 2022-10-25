#include "raylib.h"
#include "Preloader.h"
#include "Grid.h"
#include "stdio.h"

int main()
{
    int windowWidth{860};
    int windowHeight{540};

    InitWindow(windowWidth, windowHeight, "Grid Prototype");

    Preloader levelPreloader{};

    Texture2D levelTex = levelPreloader.GetLevelTexture();
    float levelPosX = static_cast<float>(windowWidth / 2) - static_cast<float>(levelTex.width / 2);
    float levelPosY = static_cast<float>(windowHeight / 2) - static_cast<float>(levelTex.height / 2);

    Grid testGrid(levelTex.width, levelTex.height, levelPreloader.GetTileTexture());
    testGrid.createCells();
    int unusableCellSize{3};
    int unusableCells[3] = {10, 2, 3};
    testGrid.setUnusableCells(unusableCells, unusableCellSize);

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTexture(levelTex, levelPosX, levelPosY, WHITE);

        testGrid.tick();

        EndDrawing();
    }
    CloseWindow();
}