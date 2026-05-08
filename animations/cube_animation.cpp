#include "cube_animation.h"

#include <iostream>
#include <numbers>

Cube_animation::Cube_animation(int w, int h) {
  width = static_cast<double>(w);
  height = static_cast<double>(h);
  angle = 1.0f;
  delta_z = 2.0f;
  vertices = {
      {+0.25, +0.25, -0.25}, {-0.25, +0.25, -0.25},
      {-0.25, -0.25, -0.25}, {+0.25, -0.25, -0.25},

      {+0.25, +0.25, +0.25}, {-0.25, +0.25, +0.25},
      {-0.25, -0.25, +0.25}, {+0.25, -0.25, +0.25},
  };
  faces = {
      {0, 1, 2, 3}, {4, 5, 6, 7}, {0, 4}, {1, 5}, {2, 6}, {3, 7},
  };
}

SDL_FPoint Cube_animation::project(Vec3 vec) {
  return SDL_FPoint{vec.x / vec.z, vec.y / vec.z};
}

SDL_FPoint Cube_animation::normalize(SDL_FPoint p) const {
  return SDL_FPoint{(p.x + 1.0f) / 2.0f * static_cast<float>(width),
                    (1.0f - (p.y + 1.0f) / 2.0f) * static_cast<float>(height)};
}

void Cube_animation::update() { angle += std::numbers::pi * (1.0f / 60.0f); }

void Cube_animation::draw(SDL_Renderer *renderer) {
  for (auto &face : faces) {
    for (int i = 0; i < face.size(); ++i) {
      SDL_FPoint point_src = normalize(project(vec3_translate(
          vec3_rotate_xz(vertices[face[i]], angle), Vec3{0.0f, 0.0f, 1.0f})));

      SDL_FPoint point_dst = normalize(project(vec3_translate(
          vec3_rotate_xz(vertices[face[(i + 1) % face.size()]], angle),
          Vec3{0.0f, 0.0f, 1.0f})));

      SDL_RenderDrawLineF(renderer, point_src.x, point_src.y, point_dst.x,
                          point_dst.y);
    }
  }
  update();
}
