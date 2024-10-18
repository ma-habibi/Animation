#include "map.h"

/* Initialize map, Set width and height */
Map::Map(int w, int h) {
    width = w;
    height = h;
}

/* Free memory */
Map::~Map() {}

/* Draw the spiral background */
void Map::draw_map(SDL_Renderer *renderer) {
    SDL_RenderDrawLine(renderer, 10, 10, 100, 100);
}