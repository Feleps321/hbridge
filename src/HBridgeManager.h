#ifndef HBridgeManager_H
#define HBridgeManager_H

#include <HBridge.h>

#define LEFT 0x3
#define RIGHT 0x4

class HBridgeManager {
  private:
    HBridge* _left;
    HBridge* _right;

  public:
    HBridgeManager(HBridge* left, HBridge* right);

    void move(byte);
};

#endif
