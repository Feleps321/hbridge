#include "HBridge.h"

HBridge::HBridge(int pinA, int pinB, int pinS) {
  _pinA = pinA;
  _pinB = pinB;
  _pinS = pinS;

  _speedPinEn = true;
}

HBridge::HBridge(int pinA, int pinB) {
  _pinA = pinA;
  _pinB = pinB;

  _speedPinEn = false;
}

void HBridge::begin() {
  pinMode(_pinA, OUTPUT);
  pinMode(_pinB, OUTPUT);
  if(_speedPinEn) pinMode(_pinS, OUTPUT);

  move(STOP);
}

void HBridge::setSpeed(byte speed) {
  _speed = speed;

  if(_speedPinEn) analogWrite(_pinS, speed);
}

void HBridge::move(byte direction) {
  if(_speedPinEn) analogWrite(_pinS, _speed);

  switch (direction) {
    case FORWARD:
      if(_speedPinEn) digitalWrite(_pinA, HIGH);
      else analogWrite(_pinA, _speed); //Controlling speed without the speed pin
      digitalWrite(_pinB, LOW);
      break;

    case BACKWARD:
      digitalWrite(_pinA, LOW);
      if(_speedPinEn) digitalWrite(_pinB, HIGH);
      else analogWrite(_pinB, _speed); //Controlling speed without the speed pin
      break;

    case STOP:
    default:
      digitalWrite(_pinA, LOW);
      digitalWrite(_pinB, LOW);
      break;
  }
}
