#ifndef GRID_H
#define GRID_H

#include "raylib.h"
#include "Cell.h"
#include <string>

class Grid
{
public:
    Grid(float gridWidth, float gridHeight, Texture2D cellTex);
    void tick();
    int CalculateCellCount();
    void createCells();
    void setCellStatus(int cellIndex, int cellState);
    Cell getCurrentCell(int cellIndex) { return cells[cellIndex]; }
    void saveGridInfo(std::string fileName);

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
};

#endif