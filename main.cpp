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

    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawTexture(levelTex, levelPosX, levelPosY, WHITE);

        Vector2 mousePos = GetMousePosition();
        DrawCircleV(mousePos, 5.f, BLACK);

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            for (int i = 0; i < testGrid.CalculateCellCount(); i++)
            {
                if (
                    mousePos.x > testGrid.getCurrentCell(i).getRect().x 
                    && mousePos.x < testGrid.getCurrentCell(i).getRect().x + 16.f 
                    && mousePos.y > testGrid.getCurrentCell(i).getRect().y 
                    && mousePos.y < testGrid.getCurrentCell(i).getRect().y + 16.f
                )
                {
                    testGrid.setCellStatus(i, 0);
                }
            }
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            for (int i = 0; i < testGrid.CalculateCellCount(); i++)
            {
                if (
                    mousePos.x > testGrid.getCurrentCell(i).getRect().x 
                    && mousePos.x < testGrid.getCurrentCell(i).getRect().x + 16.f 
                    && mousePos.y > testGrid.getCurrentCell(i).getRect().y 
                    && mousePos.y < testGrid.getCurrentCell(i).getRect().y + 16.f
                )
                {
                    testGrid.setCellStatus(i, 1);
                }
            }
        }

        if(IsKeyDown(KEY_LEFT_CONTROL) && IsKeyDown(KEY_S)){
            testGrid.saveGridInfo("testLevelGrid.dat");
        }

        testGrid.tick();

        EndDrawing();
    }
    CloseWindow();
}