#include "Cell.h"

Cell::Cell()
{
}

void Cell::tick()
{
    if (usabilityState == 1) { DrawTexture(texture, rect.x, rect.y, WHITE); }
    else { DrawTexture(texture, rect.x, rect.y, PURPLE); }
}

void Cell::setUsable(int state)
{
    usabilityState = state;
}