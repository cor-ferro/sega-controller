#include "Stick.h"
#include "Mpu.h"

class VirtualStick : public Stick {
public:
  void read();
  void initRead();
  void clampX(double x);
  void clampY(double y);
  void clamp(double x, double y);
  void setClamp();
  void print();
  void setX(int);
  void setY(int);
  int getX();
  int getY();
  Mpu mpu;
private:
  boolean isSetClamp = false;
  double offsetX = 0.0;
  double offsetY = 0.0;
  int x, y;
};

