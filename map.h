#ifndef MAP_H
#define MAP_H

#include "texture_manager.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Map
{
public:
  Map(SDL_Renderer *renderer);

  ~Map();

  void draw(SDL_Renderer *renderer);
private:
  SDL_Texture *dust;
  SDL_Texture *bush;
};

#endif /* MAP_H */