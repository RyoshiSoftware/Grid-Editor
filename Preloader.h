#ifndef PRELOADER_H
#define PRELOADER_H

#include "raylib.h"

class Preloader
{
public:
    Preloader();
    Texture2D GetTileTexture() { return tileTex; }
    Texture2D GetLevelTexture() { return levelTex; }

private:
    Texture2D tileTex = LoadTexture("assets/Tile.png");
    Texture2D levelTex = LoadTexture("assets/LevelMap.png");
};

#endif