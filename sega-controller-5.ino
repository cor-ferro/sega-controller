#include <math.h>
#include <Wire.h>

//#define DEBUG

#include "Gamepad.h"
#include "VirtualStick.h"
#include "LeftStick.h"
#include "Keyboard.h"
//#include "Hmc.h"

#define TIME_DIFF 0.01
#define DELAY_TIME TIME_DIFF * 1000

LeftStick leftStick;
VirtualStick rightStick;
Keyboard keyboard;
Gamepad gamepad;

//Hmc hmc;

void setup()
{
  keyboard.setup();
  #ifdef DEBUG
  Serial.begin(9600);
  #endif

  Wire.begin();
  Mpu::init();
//  Hmc::init();
  rightStick.initRead();
  gamepad.init();
}

void loop()
{
  keyboard.read();  
  leftStick.read();
  rightStick.read();
  
  if (keyboard.start->isPressed())
  {
    rightStick.setClamp();
  }

  if (keyboard.A->isChanged())
  {
    keyboard.A->isPressed() ? gamepad.press(1) : gamepad.release(1);
  }

  if (keyboard.B->isChanged())
  {
    keyboard.B->isPressed() ? gamepad.press(2) : gamepad.release(2);
  }

  if (keyboard.C->isChanged())
  {
    keyboard.C->isPressed() ? gamepad.press(3) : gamepad.release(3);
  }

  if (keyboard.x->isChanged())
  {
    keyboard.x->isPressed() ? gamepad.press(4) : gamepad.release(4);
  }

  if (!keyboard.stick->isPressed())
  {
    if (keyboard.y->isChanged())
      keyboard.y->isPressed() ? gamepad.press(5) : gamepad.release(5);
  
    if (keyboard.z->isChanged())
      keyboard.z->isPressed() ? gamepad.press(6) : gamepad.release(6);
  }
  else
  {
    if (keyboard.y->isChanged())
      keyboard.y->isPressed() ? gamepad.press(7) : gamepad.release(7);
  
    if (keyboard.z->isChanged())
      keyboard.z->isPressed() ? gamepad.press(8) : gamepad.release(8);
  }

  

  if (keyboard.start->isChanged())
  {
    keyboard.start->isPressed() ? gamepad.press(9) : gamepad.release(9);
  }

//  if (keyboard.shift->isChanged())
//  {
//    keyboard.shift->isPressed() ? gamepad.press(10) : gamepad.release(10);
//  }

  if (keyboard.y->isPressed())
  {
    gamepad.rxAxis(leftStick.getX() / 256);
    gamepad.ryAxis(leftStick.getY() / 256);
  }
  else
  {
    gamepad.xAxis(leftStick.getX());
    gamepad.yAxis(leftStick.getY());
  }
  
  if (keyboard.shift->isPressed())
  {
    gamepad.rxAxis(rightStick.getX());
    gamepad.ryAxis(rightStick.getY());
  }

  if (keyboard.y->isChanged() && !keyboard.y->isPressed())
  {
    gamepad.rxAxis(0);
    gamepad.ryAxis(0);
  }

  if (keyboard.shift->isChanged() && !keyboard.shift->isPressed())
  {
    gamepad.rxAxis(0);
    gamepad.ryAxis(0);
  }

  if (keyboard.stick->isChanged())
  {
//    keyboard.stick->isPressed() ? gamepad.press(11) : gamepad.release(11);
  }

  #ifndef DEBUG
  gamepad.send();
  #endif

  #ifdef DEBUG
    Serial.print("right x: ");
    Serial.print(rightStick.getX());
    Serial.print(", right y: ");
    Serial.print(rightStick.getY());
    Serial.println(" ");
//  leftStick.print(); 
  #endif
  
  delay(DELAY_TIME);
}
