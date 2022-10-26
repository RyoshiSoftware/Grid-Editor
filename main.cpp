#include "raylib.h"
#include "Preloader.h"
#include "Grid.h"

int main()
{
    int windowWidth{860};
    int windowHeight{540};

    InitWindow(windowWidth, windowHeight, "Grid Prototype");

    Preloader levelPreloader{};

    Texture2D levelTex = levelPreloader.GetLevelTexture();
    float levelPosX = static_cast<float>(windowWidth / 2) - static_cast<float>(levelTex.width / 2);
    float levelPosY = static_cast<float>(windowHeight / 2) - static_cast<float>(levelTex.height / 2);

    Grid testGrid((levelTex.width - 48), (levelTex.height - 48), levelPreloader.GetTileTexture());
    testGrid.createCells();
    int unusableCellSize{17};
    int unusableCells[17] = {27, 28, 29, 30, 31, 47, 53, 68, 70, 72, 74, 89, 91, 93, 95, 111, 115};
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