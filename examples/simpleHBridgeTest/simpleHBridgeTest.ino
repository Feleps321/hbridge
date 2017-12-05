#include <HBridge.h>

HBridge motor1 = HBridge(9, 10);
//HBridge motor1 = HBridge(9, 10, 11); //pin 11 is the PWM control

void setup() {
  motor1.setSpeed(255);

}

void loop() {
  motor1.move(FORWARD);
  delay(1000);
  motor1.move(BACKWARD);
  delay(1000);
  motor1.move(STOP);
  delay(1000);
}
