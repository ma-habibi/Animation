#ifndef GAME_H
#define GAME_H

#include "animations/lightning_animation.h"
#include "animations/sin_animation.h"
#include "animations/spiral_animation.h"

#include <SDL2/SDL.h>

class Game {
public:
  Game();

  ~Game();

  void init(const char *title, int xpos, int ypos, int width, int height,
            bool full_screen);

  void handle_events();

  void update();

  void render();

  bool is_running();

  void quit();

private:
  bool isrunning;

  SDL_Window *window;

  SDL_Renderer *renderer;

  Animation *animation;
};

#endif /* GAME_H */
