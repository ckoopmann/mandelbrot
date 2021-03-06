#include <iostream>
#include "SDL.h"
#include "position.h"

Position::Position(double x, double y) {
    _x = x;
    _y = y;
};
void Position::MoveUp() {
    _y += 0.1;
}

void Position::MoveDown() {
    _y -= 0.1;
}

void Position::MoveLeft() {
    _x -= 0.1;
}

void Position::MoveRight() {
    _x += 0.1;
}

double Position::GetX(){
    return _x;
}

double Position::GetY(){
    return _y;
}
