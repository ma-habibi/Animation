#include "map.h"
#include <math.h>

#include <iostream>

/* Initialize map, Set width and height */
Map::Map(int w, int h) {
    width = w;
    height = h;

    // Init. the draw loop variables
    max_spiral = (double) height/1000.0;
    dt = 0.005; // Step: tf - ti
    amp = 1.0;
    rotate = false;
    rotated = 0.0;
    resize_dir = false;
}

/* Free memory */
Map::~Map() {}

/* Updates rotated and max_spiral variables */
void Map::put_next_frame_vars() {
    // Stop rotation, start resize
    if (rotated >= 3.14159265)
        rotate = false;

    if (rotate) // Rotate
        rotated += 0.005;
    else {
        // Resize
        max_spiral += (resize_dir)? 1.0: -1.0;
        // Set direction
        if (max_spiral >= (double)height) {
            resize_dir = false;
            rotated = 0.0;
            rotate = true;
        }
        if (max_spiral <= (double)height/1000.0) {
            resize_dir = true;
        }

    }
}

/* Draw the spiral background */
void Map::draw_map(SDL_Renderer *renderer) {
    double t, x_offset, y_offset;

    // Get the spiral in the middle
    x_offset = (double) width / 2.0;
    y_offset = (double) height / 2.0;

    put_next_frame_vars();

    for (t = 0.0; t < max_spiral; t += dt)
        // Distribute the amp. , Apply offsets and Draw spiral
        SDL_RenderDrawPointF(renderer, 
        x_offset + amp*(t*cos(t+rotated)),
        y_offset + amp*(t*sin(t)));
}