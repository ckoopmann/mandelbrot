#ifndef POSITION_H
#define POSITION_H


class Position {
 public:
  Position(double x, double y);
  void MoveUp();
  void MoveDown();
  void MoveRight();
  void MoveLeft();

  double GetX();
  double GetY();

 private:
  double _x;
  double _y;

};

#endif
