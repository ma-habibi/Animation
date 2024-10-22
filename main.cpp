#include "game.h"

Game *game = nullptr;

int main() {
  game = new Game();

  // Set up fps
  const int fps = 60;
  const int framedelay = 1000 / fps;
  uint32_t framestart;
  int frametime;

  game->init("Spiral", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800,
             600, false);

  while (game->is_running()) {
    // Get current timing in ms
    framestart = SDL_GetTicks();

    game->handle_events();

    game->update();

    game->render();

    // Obtain dt
    frametime = SDL_GetTicks() - framestart;

    // Limit fps
    if (framedelay > frametime) {
      SDL_Delay(framedelay - frametime);
    }
  }

  game->quit();

  return 0;
}