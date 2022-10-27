#include "Grid.h"

Grid::Grid(float gridWidth, float gridHeight, Texture2D cellTex) :
width(gridWidth), height(gridHeight), tileTex(cellTex)
{
    currentGridPos = Vector2{gridRect.x, gridRect.y};
    topRight = gridRect.x + width;
}

void Grid::tick()
{
    for(int i = 0; i < CalculateCellCount(); i++)
    {
        cells[i].tick();
    }
}

int Grid::CalculateCellCount()
{
    int cellTotal{static_cast<int>((width * height) / (16.f * 16.f))};
    return static_cast<int>(cellTotal);
}

void Grid::createCells()
{
    for(int i = 0; i < CalculateCellCount(); i++)
    {
        cellRect = Rectangle{currentGridPos.x, currentGridPos.y, 16.f, 16.f};
        cells[i].setRect(cellRect);
        cells[i].setTex(tileTex);
        currentGridPos.x += 16.f;
        if (currentGridPos.x > topRight - 16.f)
        {
            currentGridPos.x = gridRect.x;
            currentGridPos.y += 16.f;
        }
    }
}

void Grid::setUnusableCells(int cellIndex)
{
    for (int i = 0; i < cellCount; i++)
    {
        if (cellIndex == i)
        {
            cells[i].setUsable(false);
        }
    }
}