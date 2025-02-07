#ifndef LIGHTNING_H
#define LIGHTNING_H

#include "animation.h"
#include <SDL2/SDL.h>

class Lightning_animation : public Animation {
public:
  Lightning_animation(int w, int h);

  void draw(SDL_Renderer *renderer) {};

  void init() {}

  void update() {}
};

#endif // LIGHTNING_H
