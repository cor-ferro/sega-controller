#include "Button.h"
#include "Arduino.h"

Button::Button(int p, char n) {
  pin = p;
  name = n;
}

void Button::setValue(int v)
{
  isChange = value != v;
  value = v;
}

int Button::getValue()
{
  return value;
}

int Button::getPin()
{
  return pin;
}

void Button::read()
{
  setValue(!digitalRead(pin));
}

bool Button::isPressed()
{
  return !!value;
}

bool Button::isChanged()
{
  return isChange;
}

