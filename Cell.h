#ifndef CELL_H
#define CELL_H

#include "raylib.h"

class Cell
{
public:
    Cell();
    void tick();
    void setRect(Rectangle cellRect) { rect = cellRect; }

private:
    Texture2D texture = LoadTexture("assets/Tile.png");
    Rectangle rect{};
};

#endif