#include "renderer.h"
#include "position.h"
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <tuple>
using namespace std::complex_literals;

// Returns the number of iterations it took the mandelbrot series to diverge
// relative to the total number of iterations
// Return value will be between 0.0 (the original point has already magnitude >2)
// and 1.0 (the series has not diverged within the maximum number of iterations)
// The quotient is smoothed for nicer visualization based on: https://stackoverflow.com/questions/369438/smooth-spectrum-for-mandelbrot-set-rendering
double mandelbrotIterationQuotient(int x, int y, int width, int height, Position &position){
    // Convert x / y coordinates to real and imaginary values based on screen position and zoom level
    double realPart = ((((double) x/width)-1.5)/position.GetZoomFactor() + position.GetX());
    double imaginaryPart = (((double)y/height-0.5)/position.GetZoomFactor() + position.GetY());
    std::complex<double> point = realPart + imaginaryPart*1i ;
    std::complex<double> z = 0;
    unsigned int max_iter = 51;
    unsigned int iter = 0;
    while (abs (z) < 2 && iter < max_iter) {
        z = z * z + point;
        iter++;
    }
    double quotient = 1.0;
    if(iter < max_iter){
        double smoothedIter = iter + 1 - log(log(abs(z)))/log(2);
        quotient = smoothedIter / max_iter;
    }
    return quotient;
}

// Returns a tuple containing the RGB values for the respective pixel based on the iteration quotient
// relative to the total number of iterations
std::tuple<int, int, int> mandelbrotRGBValue ( int x, int y, int width, int height, Position &position)  {
    double quotient = mandelbrotIterationQuotient(x, y, width, height, position);
    if (quotient == 1.0){
        return std::make_tuple(0, 0, 0);
    }
    else if (quotient > 0.5) {
        return std::make_tuple((int) (quotient*255), 255, (int) (quotient*255));
    }
    else {
        return std::make_tuple(0, (int) (quotient*255), 0);
    }

}



Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height){
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

void Renderer::Render(Position &position) {
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  int red, green, blue;
  // Loop through all pixels, get rgb value based on mandelbrot calculation and draw it
  for (int j = 0; j < screen_height; ++j) {
    for (int i = 0; i < screen_width; ++i) {
        std::tie(red, green, blue)  = mandelbrotRGBValue(i, j, screen_width, screen_height, position);
        SDL_SetRenderDrawColor(sdl_renderer, red, blue, green, 255);
        SDL_RenderDrawPoint(sdl_renderer, i, j);
    }
  }

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

