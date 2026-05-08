#include <iostream>

#include <argparse/argparse.hpp>

#include "game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {
  argparse::ArgumentParser program("animation");
  program.add_argument("-a", "--animation")
      .choices("sin", "road", "spiral", "cube")
      .help("The animation to display.")
      .required();
  try {
    program.parse_args(argc, argv);
  } catch (const std::exception &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
  }
  auto animation_name = program.get<std::string>("animation");

  game = new Game();

  // Set up fps
  const int fps = 60;
  const int framedelay = 1000 / fps;
  uint32_t framestart;
  int frametime;

  game->init(animation_name.c_str(), SDL_WINDOWPOS_UNDEFINED,
             SDL_WINDOWPOS_UNDEFINED, 800, 600, false);

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