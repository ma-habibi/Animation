#include "map.h"
#include <math.h>

/* Initialize map, Set width and height */
Map::Map(int w, int h) {
    width = w;
    height = h;
}

/* Free memory */
Map::~Map() {}

/* Draw the spiral background */
void Map::draw_map(SDL_Renderer *renderer) {
    double t, x_offset, y_offset;

    // Get the spiral in the middle
    x_offset = (double) width / 2.0;
    y_offset = (double) height / 2.0;

    for (t = 0.0; t < 100.0; t += 0.01)
        SDL_RenderDrawPointF(renderer, 
        x_offset + (t*cos(t)), y_offset + (t*sin(t)));
}