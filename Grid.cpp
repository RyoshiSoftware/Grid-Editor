#include "Grid.h"

Grid::Grid(float gridWidth, float gridHeight) :
width(gridWidth), height(gridHeight)
{
    currentGridPos = Vector2{gridRect.x, gridRect.y};
    topRight = gridRect.x + width;
}

void Grid::tick()
{
    DrawRectangle(gridRect.x, gridRect.y, gridRect.width, gridRect.height, RED);

    for(int i = 0; i < CalculateCellCount(); i++)
    {
        DrawRectangle(cellRects[i].x, cellRects[i].y, cellRects[i].width, cellRects[i].height, BLUE);
    }
}

int Grid::CalculateCellCount()
{
    cellTotal = static_cast<int>((width * height) / (16.f * 16.f));
    return static_cast<int>(cellTotal);
}

void Grid::createCells()
{
    for(int i = 0; i < CalculateCellCount(); i++)
    {
        cellRects[i] = Rectangle{currentGridPos.x, currentGridPos.y, 16.f, 16.f};
        currentGridPos.x += 16.f;
        if (currentGridPos.x > topRight - 16.f)
        {
            currentGridPos.x = gridRect.x;
            currentGridPos.y += 16.f;
        }
    }
}