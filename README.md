# mandelbrot
Interactive C++ based visualization of the mandelbrot set.
![screenshot](screenshot.png)
## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Mandelbrot`.

## Expected behaviour.

After starting the program a view of the mandelbrot set using a smooth coloring scheme should be visualized.

The user can interact with the visualization pressing the following keys:
- `i`: Zoom in
- `o`: Zoom out
- Arrow Keys: Move the window to visualize different parts of the mandelbrot set.

Since the visualization is rendered in full upon each of these actions the user can inspect
the phenomenon in unlimited precision.

## Structure

The source code (found in the [src](src) directory) is structured in to the following files / classes:
- [main.cpp](src/main.cpp): Main file that serves as entrypoint of the execution and triggers running the visualization.
- [controller.h](src/controller.h) / [controller.cpp](src/controller.cpp): Class waiting for and handling above described user actions.
- [position.h](src/position.h) / [position.cpp](src/position.cpp): Class keeping track of the position / zoom level currently to be rendered.
- [renderer.h](src/renderer.h) / [renderer.cpp](src/renderer.cpp): Class rendering each pixel when the position changes including helper functions to calculate color of each pixel based on position / zoom level.
- [visualization.h](src/visualization.h) / [visualization.cpp](src/visualization.cpp): Class containing the main render / update loop.

## Rubric Points Addressed

### README
See this file to verify that the given points were adressed

### Compiling and Testing
Check above mentioned build / run steps in project workspace to verify that the project compiles / tests as required.

### Loops, Functions, I/O:
- __The project demonstrates an understanding of C++ functions and control structures.__:  In the implementation [while](https://github.com/ckoopmann/mandelbrot/blob/main/src/visualization.cpp#L19), [for](https://github.com/ckoopmann/mandelbrot/blob/main/src/renderer.cpp#L93), [switch](https://github.com/ckoopmann/mandelbrot/blob/main/src/controller.cpp#L20) and [if/else](https://github.com/ckoopmann/mandelbrot/blob/main/src/controller.cpp#L16) statements are all used. Functions are used throughout the code to provide structure.

- __The project accepts user input and processes the input.__: As described above the user can control the behaviour of the program by pressing different keys

### Object Oriented Programming:
-- __The project uses Object Oriented Programming techniques__: As above described the functionality is split across various different classes that controll different aspects of the behaviour / data.

-- __Classes use appropriate access specifiers for class members.__: Member Attributes are all set to private. See [position.h](src/position.h) for examples.

-- __Classes abstract implementation details from their interfaces.__: Again see [position.h](src/position.h) for clearly defined / self documenting function names and abstraction of implementation details. The other classes mostly follow the example of the SDL starter code.

-- __Classes encapsulate behavior__: Again the `position` class is an example of behaviour that fulfils this requirment.





