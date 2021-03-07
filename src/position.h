#ifndef POSITION_H
#define POSITION_H


// Keeps track of the position in the mandelbrot set including the zoom level
class Position {
 public:
  Position(double x, double y, double zoomFactor);
  void MoveUp();
  void MoveDown();
  void MoveRight();
  void MoveLeft();

  void ZoomIn();
  void ZoomOut();

  double GetX();
  double GetY();
  double GetZoomFactor();

 private:
  double _x;
  double _y;
  double _zoomFactor;

};

#endif
