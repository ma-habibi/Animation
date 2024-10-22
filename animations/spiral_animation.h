#ifndef SPIRAL_ANIMATION_H
#define SPIRAL_ANIMATION_H

#include "animation.h"

class Spiral_animation : public Animation {
public:
  Spiral_animation(int w, int h);

  void draw(SDL_Renderer *renderer);

  void init();

  void update();

private:
  double max_spiral, dt, amp, rotated, d_resize, d_rotate, min_resize,
      max_resize;
  bool rotate, resize_dir;
};

#endif // SPIRAL_ANIMATION_H