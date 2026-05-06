#include "road_animation.h"

#include <algorithm>
#include <iostream>

Road_animation::Road_animation(int w, int h) {
  width = (double)w;
  height = (double)h;
  init();
}

void Road_animation::init() {
  first_line_y_pos = static_cast<int>(height);
  number_of_lines = 100;

  for (int i = 0, y_pos = first_line_y_pos; i < number_of_lines; ++i) {
    SDL_Point src{0, y_pos};
    SDL_Point dst{static_cast<int>(width), y_pos};
    vect_horizontal_points.push_back(src);
    vect_horizontal_points.push_back(dst);
    y_pos -= y_pos / 5;
  }
}

void Road_animation::update() {

  if (first_line_y_pos >= static_cast<int>(height)) {
    std::shift_left(vect_horizontal_points.begin(),
                    vect_horizontal_points.end(), 2);
    vect_horizontal_points[vect_horizontal_points.size() - 2] =
        SDL_Point{0, static_cast<int>(height) - 50};
    vect_horizontal_points[vect_horizontal_points.size() - 1] =
        SDL_Point{static_cast<int>(width), static_cast<int>(height) - 50};
    first_line_y_pos = vect_horizontal_points.at(0).y;
  }
  first_line_y_pos += 2;

  int y_pos = first_line_y_pos;
  for (int i = 0; i < number_of_lines * 2;) {
    vect_horizontal_points.at(i++).y = y_pos;
    vect_horizontal_points.at(i++).y = y_pos;
    y_pos -= y_pos / 4;
  }
}

void Road_animation::draw(SDL_Renderer *renderer) {
  for (int i = 0; i < number_of_lines * 2 - 1; i += 2) {
    SDL_RenderDrawLine(
        renderer, vect_horizontal_points[i].x, vect_horizontal_points[i].y,
        vect_horizontal_points[i + 1].x, vect_horizontal_points[i + 1].y);
  }

  SDL_FPoint god = SDL_FPoint{static_cast<float>(width) / 2.0f, 3.0f};

  std::vector<float> vec_vertical_coefficients;
  for (float i = -100.0f; i < 100.0f; i += (1.0f / 8.0f)) {
    vec_vertical_coefficients.push_back(i);
  }
  for (auto &coef : vec_vertical_coefficients)
    SDL_RenderDrawLineF(renderer, width * coef, height, god.x, god.y);

  update();
}
