#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "position.h"

class Controller {
 public:
  void HandleInput(bool &running, Position &position) const;

};

#endif
