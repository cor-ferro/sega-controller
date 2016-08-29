#include "Button.h"

#define SHIFT_ENABLE 1

class Keyboard {
public:
  void setup();
  void read();
  void print();
  Button *A = new Button(9, 'A');
  Button *B = new Button(8, 'B');
  Button *C = new Button(7, 'C');
  Button *x = new Button(6, 'x');
  Button *y = new Button(5, 'y');
  Button *z = new Button(4, 'z');
  Button *start = new Button(10, 's');
  Button *stick = new Button(A0, 'd');
  #ifdef SHIFT_ENABLE
  Button *shift = new Button(A1, 'f');
  #endif
};
