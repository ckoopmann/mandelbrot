#include "visualization.h"
#include "position.h"
#include "controller.h"
#include <iostream>
#include "SDL.h"

void Visualization::Run(Renderer &renderer) {
  constexpr std::size_t kFramesPerSecond{1};
  constexpr std::size_t kMsPerFrame{10000 / kFramesPerSecond};

  bool running = true;
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;

  Position position {0.0, 0.0};
  Controller controller;

  while (running) {

    renderer.Render(position);
    controller.HandleInput(running, position);

    std::cout << "Current Position: (" << position.GetX() << "," << position.GetY() <<")" << std::endl;

  }
}

