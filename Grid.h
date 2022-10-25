#ifndef GRID_H
#define GRID_H

#include "raylib.h"

class Grid
{
public:
    Grid(float gridWidth, float gridHeight);
    void tick();
    int CalculateCellCount();
    void createCells();

private:
    Texture2D tileTex = LoadTexture("assets/Tile.png");
    float width{};
    float height{};
    float topRight{};
    int cellTotal{};
    Rectangle gridRect{(430.f - width/2), (270.f - height/2), width, height};
    Rectangle *cellRects = new Rectangle[9999];
    Vector2 currentGridPos{};
};

#endif