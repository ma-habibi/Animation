#include "game_object.h"
#include "game.h"
#include "texture_manager.h"

#include <stdexcept>

#include <SDL2/SDL.h>

GameObject::GameObject(SDL_Renderer *renderer, const char *texture_sheet, int x,
                       int y) {
  obj_texture = TextureManager::load_texture(renderer, texture_sheet);
  if (!obj_texture) // Check for loaded texture
    throw std::runtime_error(SDL_GetError());

  // Put default width and height
  SDL_QueryTexture(obj_texture, nullptr, nullptr, &w, &h);

  // Init object position
  xpos = x;
  ypos = y;
}

/* Set object size and pos */
void GameObject::update() {
  src_rect.x = 0;
  src_rect.y = 0;
  src_rect.w = w; // Set default width and height
  src_rect.h = h;

  dst_rect.x = xpos;
  dst_rect.y = ypos;
  dst_rect.w = src_rect.w / 4;
  dst_rect.h = src_rect.h / 4;
}

/* Render Object on the scrn */
void GameObject::render(SDL_Renderer *renderer) {
  SDL_RenderCopy(renderer, obj_texture, &src_rect, &dst_rect);
}
