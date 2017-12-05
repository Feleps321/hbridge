#include "HBridgeManager.h"

HBridgeManager::HBridgeManager(HBridge* left, HBridge* right) {
  _left = left;
  _right = right;
}

void HBridgeManager::move(byte direction) {
  switch (direction) {
    case FORWARD:
    case BACKWARD:
    case STOP:
      _left->move(direction);
      _right->move(direction);
      break;

    case LEFT:
      _left->move(BACKWARD);
      _right->move(FORWARD);
      break;
      
    case RIGHT:
      _left->move(FORWARD);
      _right->move(BACKWARD);
      break;
  }
}
