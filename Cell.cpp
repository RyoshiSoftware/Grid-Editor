#include "Cell.h"

Cell::Cell()
{
}

void Cell::tick()
{
    DrawTexture(texture, rect.x, rect.y, WHITE);
}