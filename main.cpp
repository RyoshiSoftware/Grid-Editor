#include "raylib.h"
#include "Grid.h"

int main()
{
    int windowWidth{860};
    int windowHeight{540};

    InitWindow(windowWidth, windowHeight, "Grid Prototype");

    Texture2D levelTex = LoadTexture("assets/LevelMap.png");
    float levelPosX = static_cast<float>(windowWidth / 2) - (levelTex.width / 2);
    float levelPosY = static_cast<float>(windowHeight / 2) - (levelTex.height / 2);

    Grid testGrid(levelTex.width, levelTex.height);
    testGrid.createCells();

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