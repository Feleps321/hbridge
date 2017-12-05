#include <HBridge.h>
#include <HBridgeManager.h>

HBridge LeftMotor = HBridge(8, 9);
HBridge RightMotor = HBridge(10, 11);

HBridgeManager Motors = HBridgeManager(&LeftMotor, &RightMotor);

void setup() {
  LeftMotor.setSpeed(255);
  RightMotor.setSpeed(255);

}

void loop() {
  Motors.move(FORWARD);
  delay(1000);
  Motors.move(BACKWARD);
  delay(1000);
  Motors.move(LEFT);
  delay(1000);
  Motors.move(RIGHT);
  delay(1000);
  Motors.move(STOP);
  delay(1000);
}
