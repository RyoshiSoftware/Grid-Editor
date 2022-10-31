#ifndef CELL_H
#define CELL_H

#include "raylib.h"
#include "Preloader.h"

class Cell
{
public:
    Cell();
    void tick();
    void setRect(Rectangle cellRect) { rect = cellRect; }
    void setTex(Texture2D cellTex) { texture = cellTex; }
    void setUsable(int state);
    int getUsable(){ return usabilityState; }
    Rectangle getRect() { return rect; }

private:
    Texture2D texture{};
    Rectangle rect{};
    int usabilityState{1};
};

#endif