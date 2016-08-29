#include "Arduino.h"

#define HMC_ADDR 0x1E

class Hmc {
public:
  void read();
  void print();
  static void init();
private:
  int axisX = 0;
  int axisY = 0;
  int axisZ = 0;
};

