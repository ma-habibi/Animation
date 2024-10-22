#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "game.h"

class GameObject {
public:
  GameObject(SDL_Renderer *renderer, const char *texture_sheet, int x, int y);

  ~GameObject();

  void update();

  void render(SDL_Renderer *renderer);

private:
  int xpos, ypos, w, h;
  SDL_Texture *obj_texture;
  SDL_Rect src_rect, dst_rect;
};

#endif /* GAME_OBJECT_H */
