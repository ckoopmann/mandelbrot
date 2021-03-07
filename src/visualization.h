#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "renderer.h"

// Main class controlling the flow of execution (what is called game in other sdl projects)
class Visualization {
 public:
  void Run(Renderer &renderer);
};

#endif

