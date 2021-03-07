#include <iostream>
#include "SDL.h"
#include "position.h"

Position::Position(double x, double y, double zoomFactor) {
    _x = x;
    _y = y;
    _zoomFactor = zoomFactor;
};
void Position::MoveUp() {
    _y -= 0.1/_zoomFactor;
}

void Position::MoveDown() {
    _y += 0.1/_zoomFactor;
}

void Position::MoveLeft() {
    _x -= 0.1/_zoomFactor;
}

void Position::MoveRight() {
    _x += 0.1/_zoomFactor;
}

void Position::ZoomIn() {
    _zoomFactor *= 1.1;
}

void Position::ZoomOut() {
    _zoomFactor *= 1.0/1.1;
}


double Position::GetX(){
    return _x;
}

double Position::GetY(){
    return _y;
}

double Position::GetZoomFactor(){
    return _zoomFactor;
}
