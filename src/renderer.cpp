#include "renderer.h"
#include <iostream>
#include <string>
#include <complex>
using namespace std::complex_literals;

int mandelbrotRGBValue ( int x, int y, int width, int height)  {
    std::complex<double> point = (((double) x/width)-1.5) + ((double)y/height-0.5)*1i;
    // we divide by the image dimensions to get values smaller than 1
    // then apply a translation
    std::complex<double> z = 0;
    unsigned int nb_iter = 0;
    while (abs (z) < 2 && nb_iter <= 34) {
        z = z * z + point;
        nb_iter++;
    }
    if (nb_iter < 34) return 255;
    else return 0;
}

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Mandelbrot", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render() {
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  for (int j = 0; j < screen_height; ++j) {
    for (int i = 0; i < screen_width; ++i) {
        int red_value = mandelbrotRGBValue(i, j, screen_width, screen_height);
        SDL_SetRenderDrawColor(sdl_renderer, red_value, 0, 0, 255);
        SDL_RenderDrawPoint(sdl_renderer, i, j);
    }
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

