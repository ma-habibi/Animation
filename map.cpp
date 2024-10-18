#include "map.h"
#include <math.h>

/* Initialize map, Set width and height */
Map::Map(int w, int h) {
    width = w;
    height = h;

    // Init. the draw loop variables
    max_spiral = (double) height;
    dt = 0.005; // Step: tf - ti
    amp = 10.0;
}

/* Free memory */
Map::~Map() {}

/* Draw the spiral background */
void Map::draw_map(SDL_Renderer *renderer) {
    double t, x_offset, y_offset;

    // Get the spiral in the middle
    x_offset = (double) width / 2.0;
    y_offset = (double) height / 2.0;

    for (t = 0.0; t < max_spiral; t += dt)
        // Distribute the amp. , Apply offsets and Draw spiral
        SDL_RenderDrawPointF(renderer, 
        x_offset + amp*(t*cos(t)), y_offset + amp*(t*sin(t)));
}