#ifndef Gamepad_h
#define Gamepad_h

#include <Arduino.h>
#include "HID.h"

#define HID_REPORTID_GAMEPAD 6

typedef union {
  uint8_t whole8[];
    uint16_t whole16[];
    uint32_t whole32[];
    uint32_t buttons;

    struct {
        uint8_t button1 : 1;
        uint8_t button2 : 1;
        uint8_t button3 : 1;
        uint8_t button4 : 1;
        uint8_t button5 : 1;
        uint8_t button6 : 1;
        uint8_t button7 : 1;
        uint8_t button8 : 1;

        uint8_t button9 : 1;
        uint8_t button10 : 1;
        uint8_t button11 : 1;
        uint8_t button12 : 1;
        uint8_t button13 : 1;
        uint8_t button14 : 1;
        uint8_t button15 : 1;
        uint8_t button16 : 1;

        uint8_t button17 : 1;
        uint8_t button18 : 1;
        uint8_t button19 : 1;
        uint8_t button20 : 1;
        uint8_t button21 : 1;
        uint8_t button22 : 1;
        uint8_t button23 : 1;
        uint8_t button24 : 1;

        uint8_t button25 : 1;
        uint8_t button26 : 1;
        uint8_t button27 : 1;
        uint8_t button28 : 1;
        uint8_t button29 : 1;
        uint8_t button30 : 1;
        uint8_t button31 : 1;
        uint8_t button32 : 1;

        int16_t xAxis;
        int16_t yAxis;
        int8_t zAxis;

        int16_t rxAxis;
        int16_t ryAxis;
        int8_t rzAxis;

        uint8_t dPad1 : 4;
        uint8_t dPad2 : 4;
    };
} GamepadReport;

class Gamepad {
public:
  Gamepad(void);
    void init();
    void press(uint8_t b);
    void release(uint8_t b);
    void xAxis(int16_t a);
    void yAxis(int16_t a);
    void zAxis(int8_t a);
    void rxAxis(int16_t a);
    void ryAxis(int16_t a);
    void rzAxis(int8_t a);
    void dPad1(int8_t d);
    void dPad2(int8_t d);
    void send();
private:
  GamepadReport _gamepadReport;
  void sendReport();
};

#endif
