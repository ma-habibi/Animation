#include "spiral_animation.h"
#include <SDL2/SDL.h>

/* Initialize map, Set width and height */
Spiral_animation::Spiral_animation(int w, int h) {
    width = (double) w;
    height = (double) h;
    init();
}

/* Initialize animation variables */
void Spiral_animation::init() {
    // Init. the draw loop variables
    max_spiral = height/1000.0;
    dt = 0.005; // Step: tf - ti
    amp = 1.0;
    rotate = false;
    rotated = 0.0;
    resize_dir = false;
    d_resize = 1.0;
    d_rotate = 0.005;
    min_resize = height / 1000.0;
    max_resize = height;

}

/* Updates rotated and max_spiral variables */
void Spiral_animation::update() {
    // Stop rotation, start resize
    if (rotated >= 3.14159265)
        rotate = false;

    if (rotate) // Rotate
        rotated += d_rotate;
    else {
        // Resize
        max_spiral += (resize_dir)? d_resize: -d_resize;
        // Set direction
        if (max_spiral >= max_resize) {
            resize_dir = false;
            rotated = 0.0;
            rotate = true;
        }
        if (max_spiral <= min_resize) {
            resize_dir = true;
        }

    }
}

/* Draw the spiral background */
void Spiral_animation::draw(SDL_Renderer *renderer) {
    double t, x_offset, y_offset;

    // Get the spiral in the middle
    x_offset = width / 2.0;
    y_offset = height / 2.0;

    update();

    for (t = 0.0; t < max_spiral; t += dt)
        // Distribute the amp. , Apply offsets and Draw spiral
        SDL_RenderDrawPointF(renderer, 
        x_offset + amp*(t*cos(t+rotated)),
        y_offset + amp*(t*sin(t)));
}