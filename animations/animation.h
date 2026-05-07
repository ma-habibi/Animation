#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>

class Animation {
protected:
  /* 3D vector. */
  typedef struct {
    float x, y, z;
  } Vec3;

  /* Translate a source vector by a given translation vector */
  static Vec3 vec3_translate(Vec3, Vec3);

  /* Rotate a source vector by a given rotation vector along the X and Z axis */
  static Vec3 vec3_rotate_xz(Vec3, float);

public:
  virtual ~Animation() {};

  virtual void draw(SDL_Renderer *renderer) = 0;

  virtual void init() = 0;

  virtual void update() = 0;

  double width, height;
};

#endif
