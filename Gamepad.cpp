#pragma once

#include "Gamepad.h"

static const uint8_t _hidReportDescriptor[] PROGMEM ={
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)
    0x09, 0x04, // USAGE Joystick
    0xa1, 0x01, // COLLECTION (Application)
    0x85, HID_REPORTID_GAMEPAD, // REPORT_ID
    /* 32 Buttons */
    0x05, 0x09, // USAGE_PAGE (Button)
    0x19, 0x01, // USAGE_MINIMUM (Button 1)
    0x29, 0x20, // USAGE_MAXIMUM (Button 32)
    0x15, 0x00, // LOGICAL_MINIMUM (0),
    0x25, 0x01, // LOGICAL_MAXIMUM (1)
    0x75, 0x01, // REPORT_SIZE (1)
    0x95, 0x20, // REPORT_COUNT (32)
    0x81, 0x02, // INPUT (Data, Var, Abs)
    /* 4 16bit axis */
    0x05, 0x01,              /*   USAGE_PAGE (Generic Desktop) */
    0xa1, 0x00,             /*   COLLECTION (Physical) */
    0x09, 0x30,             /*     USAGE (X) */
    0x09, 0x31,             /*     USAGE (Y) */
    0x09, 0x33,             /*     USAGE (Rx) */
    0x09, 0x34,             /*     USAGE (Ry) */
    0x16, 0x00, 0x80,         /*     LOGICAL_MINIMUM (-32768) */
    0x26, 0xFF, 0x7F,         /*     LOGICAL_MAXIMUM (32767) */
    0x75, 0x10,             /*     REPORT_SIZE (16) */
    0x95, 0x04,             /*     REPORT_COUNT (4) */
    0x81, 0x02,             /*     INPUT (Data,Var,Abs) */
    /* 2 8bit axis */
    0x09, 0x32,              /*     USAGE (Z) */
    0x09, 0x35,             /*     USAGE (Rz) */
    0x15, 0x80,             /*     LOGICAL_MINIMUM (-128) */
    0x25, 0x7F,             /*     LOGICAL_MAXIMUM (127) */
    0x75, 0x08,             /*     REPORT_SIZE (8) */
    0x95, 0x02,             /*     REPORT_COUNT (2) */
    0x81, 0x02,             /*     INPUT (Data,Var,Abs) */
    0xc0,               /*   END_COLLECTION */
    /* 2 Hat Switches */
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)
    0x09, 0x39, // USAGE (Hat switch)
    0x09, 0x39, // USAGE (Hat switch)
    0x15, 0x01, // LOGICAL_MINIMUM (1)
    0x25, 0x08, // LOGICAL_MAXIMUM (8)
    0x95, 0x02, // REPORT_COUNT (2)
    0x75, 0x04, // REPORT_SIZE (4)
    0x81, 0x02, // INPUT (Data,Var,Abs)
    0xc0 // END_COLLECTION
};

Gamepad::Gamepad(void) 
{
  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
    HID().AppendDescriptor(&node);
}

void Gamepad::sendReport()
{
    HID().SendReport(HID_REPORTID_GAMEPAD, &_gamepadReport, sizeof(GamepadReport));
}

void Gamepad::init()
{
    sendReport();
}

void Gamepad::press(uint8_t b)
{
    _gamepadReport.buttons |= (uint32_t)1 << (b - 1);
}

void Gamepad::release(uint8_t b)
{
    _gamepadReport.buttons &= ~((uint32_t)1 << (b - 1));
}

void Gamepad::xAxis(int16_t a)
{
    _gamepadReport.xAxis = a;
}

void Gamepad::yAxis(int16_t a)
{
    _gamepadReport.yAxis = a;
}

void Gamepad::zAxis(int8_t a)
{
    _gamepadReport.zAxis = a;
}

void Gamepad::rxAxis(int16_t a)
{
    _gamepadReport.rxAxis = a;
}

void Gamepad::ryAxis(int16_t a)
{
    _gamepadReport.ryAxis = a;
}

void Gamepad::rzAxis(int8_t a)
{
    _gamepadReport.rzAxis = a;
}

void Gamepad::dPad1(int8_t a)
{
    _gamepadReport.dPad1 = a;
}

void Gamepad::dPad2(int8_t d)
{
    _gamepadReport.dPad2 = d;
}

void Gamepad::send()
{
  sendReport();
}

