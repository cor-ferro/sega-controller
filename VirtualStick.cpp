#include "VirtualStick.h"

#define MIN_MPU_ANGLE -400.0
#define MAX_MPU_ANGLE 400.0

#define MIN_VALUE -127.0
#define MAX_VALUE 127.0

#define STEP MAX_VALUE / MAX_MPU_ANGLE

void VirtualStick::read()
{
  mpu.read();

  double pitch = -mpu.getAngleX();
  double roll = -mpu.getAngleY(); // не совсем корректно, Y это Рысканье а не Крен

  if (pitch < MIN_MPU_ANGLE) pitch = MIN_MPU_ANGLE;
  if (pitch > MAX_MPU_ANGLE) pitch = MAX_MPU_ANGLE;

  if (roll < MIN_MPU_ANGLE) roll = MIN_MPU_ANGLE;
  if (roll > MAX_MPU_ANGLE) roll = MAX_MPU_ANGLE;

  if (isSetClamp) 
  {
    clamp(pitch * STEP, roll * STEP);
    isSetClamp = false;
  }

  setX((int)(pitch * STEP));
  setY((int)(roll * STEP));
}

void VirtualStick::initRead()
{
  mpu.initRead();
}

void VirtualStick::clampX(double x)
{
  offsetX = x;
}

void VirtualStick::clampY(double y)
{
  offsetY = y;
}

void VirtualStick::clamp(double x, double y)
{
  clampX(x);
  clampY(y);
}

void VirtualStick::setClamp()
{
  isSetClamp = true;
}

void VirtualStick::print()
{
  Serial.print("virtual x: ");Serial.print(getX());Serial.print("; ");
  Serial.print("virtual y: ");Serial.print(getY());Serial.print("; ");
  Serial.println(" ");
}

void VirtualStick::setX(int _x)
{
  x = _x;
};

void VirtualStick::setY(int _y) 
{
  y = _y;
}

int VirtualStick::getX() {
  return x;
}

int VirtualStick::getY() {
  return y;
}

