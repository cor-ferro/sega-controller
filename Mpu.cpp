#include <Wire.h>
#include "Mpu.h"

#define MPU_ADDR 0x68
#define K 0.85
#define K1 1-K

#define TIME_DIFF 0.01

#define AC_SCALE 16384.0
#define GY_SCALE 131.0

void Mpu::init()
{
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

double Mpu::dist(double a, double b)
{
  return sqrt((a * a) + (b * b));
}

double Mpu::getXRotation(double x, double y, double z)
{
  double radians = atan2(y, Mpu::dist(x,z));
  return degrees(radians);
}

double Mpu::getYRotation(double x, double y, double z)
{
  double radians = atan2(x, Mpu::dist(y,z));
  return -degrees(radians);
}

double Mpu::getAngleX() {
  return angleX;
}
double Mpu::getAngleY() {
  return angleY;
}

MpuData Mpu::getData()
{
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);

  MpuData data = {
    .AcX = Wire.read() << 8 | Wire.read(),
    .AcY = Wire.read() << 8 | Wire.read(),
    .AcZ = Wire.read() << 8 | Wire.read(),
    .Tmp = Wire.read() << 8 | Wire.read(),
    .GyX = Wire.read() << 8 | Wire.read(),
    .GyY = Wire.read() << 8 | Wire.read(),
    .GyZ = Wire.read() << 8 | Wire.read()
  };

  return data;
}

void Mpu::read()
{
  MpuData data = getData();

  filterRaw(&data);
}

void Mpu::initRead()
{
  offsetData = getData();
}

void Mpu::filterRaw(MpuData *data)
{
  double gyroXDelta = ((data->GyX / GY_SCALE) * TIME_DIFF);
  double gyroYDelta = ((data->GyY / GY_SCALE) * TIME_DIFF);

  double rotationX = Mpu::getXRotation(data->AcX / AC_SCALE, data->AcY / AC_SCALE, data->AcZ / AC_SCALE);
  double rotationY = Mpu::getYRotation(data->AcX / AC_SCALE, data->AcY / AC_SCALE, data->AcZ / AC_SCALE);

  angleX = K * (angleX + gyroXDelta) + (K1 * rotationX);
  angleY = K * (angleY + gyroYDelta) + (K1 * rotationY);
}
