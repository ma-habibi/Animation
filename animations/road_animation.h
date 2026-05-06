#ifndef ROAD_H
#define ROAD_H

#include <vector>

#include "animation.h"
#include <SDL2/SDL.h>

class Road_animation : public Animation {
public:
  Road_animation(int w, int h);

  void draw(SDL_Renderer *renderer);

  void init();

  void update();

private:
  int first_line_y_pos, number_of_lines;
  std::vector<SDL_Point> vect_horizontal_points{};
};

#endif // ROAD_H
