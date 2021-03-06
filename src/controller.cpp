#include "controller.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "SDL.h"
#include "position.h"

void Controller::HandleInput(bool &running, Position &position) const {
  SDL_Event e;
  bool waiting = true;
  while (waiting) {
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) {
      running = false;
      waiting = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
            std::cout << "Moving Up" << std::endl;
            position.MoveUp();
            waiting = false;
            break;

        case SDLK_DOWN:
            std::cout << "Moving Down" << std::endl;
            position.MoveDown();
            waiting = false;
            break;

        case SDLK_LEFT:
            std::cout << "Moving Left" << std::endl;
            position.MoveLeft();
            waiting = false;
            break;

        case SDLK_RIGHT:
            std::cout << "Moving Right" << std::endl;
            position.MoveRight();
            waiting = false;
            break;

        default:
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
    }
  }
  return;
}
