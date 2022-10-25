#ifndef GRID_H
#define GRID_H

#include "raylib.h"
#include "Cell.h"

class Grid
{
public:
    Grid(float gridWidth, float gridHeight, Texture2D cellTex);
    void tick();
    int CalculateCellCount();
    void createCells();
    void setUnusableCells(int cellIndexes[], int size);

private:
    float width{};
    float height{};
    Texture2D tileTex{};
    float topRight{};
    const int cellCount = CalculateCellCount();
    Rectangle gridRect{(430.f - width/2), (270.f - height/2), width, height};
    Rectangle cellRect{};
    Cell *cells = new Cell[cellCount];
    Vector2 currentGridPos{};
    int currentVal{100};
};

#endif