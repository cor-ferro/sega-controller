#include "Stick.h"

class LeftStick : public Stick {
  public:
    void read();
    void print();
    int getX();
    int getY();
  private:
    const int offset = 512;
    const int maxOffset = 1024;
    const int normalizeStep = 32767 / offset;
    const int deadzone = 50;
    int x, y;
};
