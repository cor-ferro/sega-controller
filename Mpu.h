#include "Arduino.h"

struct MpuData {
  int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
};

class Mpu {
  public:
    void read();
    void initRead();
    MpuData getData();
    MpuData offsetData;
    void filterRaw(MpuData *data);
    double getAngleX();
    double getAngleY();
    static void init();
    static double dist(double a, double b);
    static double getXRotation(double x, double y, double z);
    static double getYRotation(double x, double y, double z);
  private:
    double angleX = 0;
    double angleY = 0;
};
