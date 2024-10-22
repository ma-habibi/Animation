#include "sin_animation.h"

/* Initialize map */
Sin_animation::Sin_animation(int w, int h) {
  width = (double)w;
  height = (double)h;
  init();
}

/* Initialize animation */
void Sin_animation::init() {
  freq = 0.010;
  amp = 100.0;
  dt = 0.01;
  d_freq = 0.0001;
}

/* Updates frequencies */
void Sin_animation::update() { freq += d_freq; }

/* Draw the sinusoid background */
void Sin_animation::draw(SDL_Renderer *renderer) {
  double t, y_offset;
  y_offset = height / 2.0;

  for (t = 0.0; t < width; t += dt)
    SDL_RenderDrawPointF(renderer, t,
                         y_offset + amp * sinf(2.0 * 3.1415 * freq * t));

  update();
}