#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "game.h"

#include <SDL2/SDL_image.h>

class TextureManager {
  public:
    static SDL_Texture *load_texture(
        SDL_Renderer *renderer, const char *filename);
};

#endif /* TEXTURE_MANAGER_H */