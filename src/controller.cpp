#include "controller.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "SDL.h"
#include "position.h"

void Controller::HandleInput(bool &running, Position &position) const {
  SDL_Event e;
  bool waiting = true;
  while (SDL_WaitEvent(&e) && waiting) {
    if (e.type == SDL_QUIT) {
      running = false;
      waiting = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
            position.MoveUp();
            waiting = false;

        case SDLK_DOWN:
            position.MoveDown();
            waiting = false;

        case SDLK_LEFT:
            position.MoveLeft();
            waiting = false;

        case SDLK_RIGHT:
            position.MoveRight();
            waiting = false;
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  return;
}
