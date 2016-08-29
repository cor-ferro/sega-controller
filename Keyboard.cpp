#include "Arduino.h"
#include "Keyboard.h"

void Keyboard::setup()
{
  pinMode(A->getPin(), INPUT);
  pinMode(B->getPin(), INPUT);
  pinMode(C->getPin(), INPUT);
  pinMode(x->getPin(), INPUT);
  pinMode(y->getPin(), INPUT);
  pinMode(z->getPin(), INPUT);
  pinMode(start->getPin(), INPUT);
  pinMode(A0, INPUT_PULLUP);
  #ifdef SHIFT_ENABLE
  pinMode(A1, INPUT_PULLUP);
  #endif

  digitalWrite(A->getPin(), HIGH);
  digitalWrite(B->getPin(), HIGH);
  digitalWrite(C->getPin(), HIGH);
  digitalWrite(x->getPin(), HIGH);
  digitalWrite(y->getPin(), HIGH);
  digitalWrite(z->getPin(), HIGH);
  digitalWrite(start->getPin(), HIGH);
  #ifdef SHIFT_ENABLE
//  digitalWrite(A0, HIGH);
  #endif
}

void Keyboard::read()
{
  A->read();
  B->read();
  C->read();
  x->read();
  y->read();
  z->read();
  start->read();
  stick->read();
  #ifdef SHIFT_ENABLE
  shift->read();
  #endif
}

void Keyboard::print()
{
  Serial.print("A: ");Serial.print(A->getValue());Serial.print("; ");
  Serial.print("B: ");Serial.print(B->getValue());Serial.print("; ");
  Serial.print("C: ");Serial.print(C->getValue());Serial.print("; ");
  Serial.print("x: ");Serial.print(x->getValue());Serial.print("; ");
  Serial.print("y: ");Serial.print(y->getValue());Serial.print("; ");
  Serial.print("z: ");Serial.print(z->getValue());Serial.print("; ");
  Serial.print("start: ");Serial.print(start->getValue());Serial.print("; ");
  Serial.print("stick: ");Serial.print(stick->getValue());Serial.print("; ");
  #ifdef SHIFT_ENABLE
  Serial.print("shift: ");Serial.print(shift->getValue());Serial.print("; ");
  Serial.println(" ");
  #endif
}

