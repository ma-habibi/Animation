#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "map.h"

class Game {
  public:
    Game();

    ~Game();

    void init(const char *title, int xpos, int ypos, 
        int width, int height, bool full_screen);

    void handle_events();

    void update();

    void render();

    bool is_running();

    void quit();

  private:
    bool isRunning;

    SDL_Window *window;

    SDL_Renderer *renderer;

    Map *map;
};

#endif /* GAME_H */
