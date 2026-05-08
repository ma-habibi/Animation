#ifndef CUBE_H
#define CUBE_H

#include <vector>

#include <SDL2/SDL.h>

#include "animation.h"

class Cube_animation : public Animation {
public:
  Cube_animation(int w, int h);

  void draw(SDL_Renderer *renderer) override;

  void init() override {};

  void update() override;

  static SDL_FPoint project(Vec3);

  [[nodiscard]] SDL_FPoint normalize(SDL_FPoint) const;

private:
  float angle;
  float delta_z;
  std::vector<Vec3> vertices;
  std::vector<std::vector<int>> faces;
};

#endif // CUBE_H
