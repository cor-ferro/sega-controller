#include <Wire.h>
#include "Hmc.h"

void Hmc::init()
{
  Wire.beginTransmission(HMC_ADDR);
  Wire.write(0x02);
  Wire.write(0x00);
  Wire.endTransmission(true);
}

void Hmc::read()
{
  Wire.beginTransmission(HMC_ADDR);
  Wire.write(0x03);
  Wire.endTransmission();

  Wire.requestFrom(HMC_ADDR, 6);

  if (6 <= Wire.available()) {
    axisX = Wire.read() << 8;
    axisX |= Wire.read();
    axisZ = Wire.read() << 8;
    axisZ |= Wire.read();
    axisY = Wire.read() << 8;
    axisY |= Wire.read();

//    print();
  }
}

void Hmc::print()
{
  Serial.print("hmc x: ");Serial.print(axisX);Serial.print("; ");
  Serial.print("hmc y: ");Serial.print(axisY);Serial.print("; ");
  Serial.print("hmc z: ");Serial.print(axisZ);Serial.print("; ");
  Serial.println(" ");
}

