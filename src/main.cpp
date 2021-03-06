#include <iostream>
#include <complex>
#include "renderer.h"
#include "visualization.h"
using namespace std;

int main() {
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    Renderer renderer(kScreenWidth, kScreenHeight);

    Visualization visualization;
    visualization.Run(renderer);
}
