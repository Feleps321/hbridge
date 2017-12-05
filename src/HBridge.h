#ifndef HBridge_H
#define HBridge_H

#include <Arduino.h> //Arduino functions

#define STOP 0x0
#define FORWARD 0x1
#define BACKWARD 0x2

class HBridge {
  private:
    int _pinA;
    int _pinB;
    int _pinS; //Speed (PWM)

    bool _speedPinEn = false; //Enable HBridge extra pin for velocity control

    byte _speed = 255;

    void begin();

  public:
    HBridge(int pinA, int pinB, int pinS);
    HBridge(int pinA, int pinB);

    void move(byte direction);

    void setSpeed(byte speed);
};

#endif
