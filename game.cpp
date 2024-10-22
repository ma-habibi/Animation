#include "game_object.h"

#include <SDL2/SDL.h>

#include <iostream>
#include <stdexcept>

Game::Game()
{}
Game::~Game()
{}

/* Initialize the game and SDL subsytems */
void Game::init(const char *title, int xpos, int ypos,
        int width, int height, bool full_screen) {
  int flag; 

  // Init subsytems
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    throw std::runtime_error(SDL_GetError());
  std::cout << "Subsytems Initialized." << std::endl;

  // Create window
  flag = (full_screen)? SDL_WINDOW_FULLSCREEN: SDL_WINDOW_SHOWN;
  window = SDL_CreateWindow(title,
      xpos, ypos,
      width, height, flag);
  if (!window)
    throw std::runtime_error(SDL_GetError());

  // Create renderer
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (!renderer)
    throw std::runtime_error(SDL_GetError());

  isrunning = true;

  // Init spiral map
  spiral = new Spiral_animation(width, height);
}

/* Listen for events */
void Game::handle_events() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:
      isrunning = false;

    default:
      break;
  }
}

/* Update the game */
void Game::update() {
  return;
}

/* Render */
void Game::render() {
  // Draw map using a new renderer
  SDL_RenderClear(renderer);

  // Set renderer colors
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

  // Draw spiral background
  spiral->draw(renderer);

  // Set renderer colors
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  SDL_RenderPresent(renderer);
}

/* If the Game is running */
bool Game::is_running() {
  return isrunning;
}

/* Clean up */
void Game::quit() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();
}