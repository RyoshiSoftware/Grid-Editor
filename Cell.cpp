#include "Cell.h"

Cell::Cell()
{
}

void Cell::tick()
{
    if (isUsable) { DrawTexture(texture, rect.x, rect.y, WHITE); }
    else { DrawTexture(texture, rect.x, rect.y, PURPLE); }
}