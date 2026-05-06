#include "road_animation.h"

#include <algorithm>
#include <iostream>

Road_animation::Road_animation(int w, int h) {
  width = (double)w;
  height = (double)h;
  init();
}

/*
 * Initialize the vector of horizontal points two at a time
 * each pair representing a line segment.
 */
void Road_animation::init() {
  first_line_y_pos = static_cast<int>(height);
  number_of_lines = 32;
  for (int i = 0, y_pos = first_line_y_pos; i < number_of_lines; ++i) {
    vect_horizontal_points.push_back(SDL_Point{0, y_pos});
    vect_horizontal_points.push_back(SDL_Point{static_cast<int>(width), y_pos});
    y_pos -= y_pos / 5;
  }
}

/*
 * Move each line horizontal toward the bottom of the screen, while calculating
 * the space between lines with the respect to their current positions in each
 * iteration of the applications loop. The proportionate spacing makes the
 * perspective (3 dimension illusion). When time a horizontal line crossed the
 * bottom of the screen, pop its points (line segment connecting points v[0] and
 * v[1]), shift vector to left by two, and insert two new points at the top of
 * the screen.
 */
void Road_animation::update() {
  if (first_line_y_pos >= static_cast<int>(height)) {
    std::shift_left(vect_horizontal_points.begin(),
                    vect_horizontal_points.end(), 2);

    vect_horizontal_points[vect_horizontal_points.size() - 2] =
        SDL_Point{0, static_cast<int>(height)};
    vect_horizontal_points[vect_horizontal_points.size() - 1] =
        SDL_Point{static_cast<int>(width), static_cast<int>(height)};
    first_line_y_pos = vect_horizontal_points.at(0).y;
  }
  first_line_y_pos += height / 256.0;

  int y_pos = first_line_y_pos;
  for (int i = 0; i < number_of_lines * 2;) {
    vect_horizontal_points.at(i++).y = y_pos;
    vect_horizontal_points.at(i++).y = y_pos;
    y_pos -= y_pos / 4;
  }
}

/*
 * Draw vertical and horizontal line segments. Then, call update.
 */
void Road_animation::draw(SDL_Renderer *renderer) {
  for (int i = 0; i < number_of_lines * 2 - 1; i += 2) {
    SDL_RenderDrawLine(
        renderer, vect_horizontal_points[i].x, vect_horizontal_points[i].y,
        vect_horizontal_points[i + 1].x, vect_horizontal_points[i + 1].y);
  }

  auto god = SDL_FPoint{static_cast<float>(width) / 2.0f,
                        -static_cast<float>(height) / 8.0f};

  std::vector<float> vec_vertical_coefficients;
  for (float i = -4.0f; i < 4.0f; i += (1.0f / 4.0f))
    vec_vertical_coefficients.push_back(i);

  for (auto &coef : vec_vertical_coefficients)
    SDL_RenderDrawLineF(renderer, width * coef, height, god.x, god.y);

  update();
}
