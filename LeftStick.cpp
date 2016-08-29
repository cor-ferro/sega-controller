#include "Arduino.h"
#include "LeftStick.h"

int LeftStick::getX()
{
  return x;
}

int LeftStick::getY()
{
  return y;
}

void LeftStick::read()
{
  int _x = analogRead(2);
  int _y = analogRead(3);

  x = ((offset - _x)) * normalizeStep;
  y = -(((offset - _y)) * normalizeStep);
}

void LeftStick::print()
{
  Serial.print("left stick x: ");Serial.print(getX());Serial.print("; ");
  Serial.print("left stick y: ");Serial.print(getY());Serial.print("; ");
  Serial.println(" ");
}
