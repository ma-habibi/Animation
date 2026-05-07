#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>

class Animation {
protected:
  /* 3D vector. */
  typedef struct {
    float x, y, z;
  } Vec3;

public:
  virtual ~Animation() {};

  virtual void draw(SDL_Renderer *renderer) = 0;

  virtual void init() = 0;

  virtual void update() = 0;

  double width, height;
};

#endif
