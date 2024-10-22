#include "texture_manager.h"

#include <stdexcept>

/* Create surface from the filename */
SDL_Texture *TextureManager::load_texture(
    SDL_Renderer *renderer,
    const char *filename) {

  SDL_Surface *tmp = IMG_Load(filename);
  if (!tmp)
    throw std::runtime_error(SDL_GetError());

  SDL_Texture *tex = SDL_CreateTextureFromSurface(
      renderer, tmp);
  if (!tex)
    throw std::runtime_error(SDL_GetError());

  SDL_FreeSurface(tmp);

  return tex;
}