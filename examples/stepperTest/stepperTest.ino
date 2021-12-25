/* Test of 28BYJ-48.h Library for 28BYJ-48 5V (or 12V) DC Stepper Motor 
 *  with ULN2003 Driver
 *
 * Connections:
 * Plug the connector of the 28BYJ-48 stepper motor directly into the socket of the ULN2003.
 *
 * Wire ULN2003 to MCU:
 * ----------------------------
 * Blue wire (A) - IN1 to Pin 8
 * Pink Wire (B) - IN2 to Pin 9 
 * Yellow Wire (C) IN3 to Pin 10
 * Orange Wire (D) IN4 to Pin 11
 * - to GND
 * + to +5V (or +12V for the 12V version)
 */

#include <28BYJ-48.h>

StepperMotor motor(8,9,10,11);

void setup(){
  Serial.begin(9600); // Start the serial monitor
}

void loop(){
  Serial.println("Stepping clockwise.");
  motor.step(4096,15);  // CW 4096 steps (1 rotation) @15rpm
  delay(1000);
  Serial.println("Stepping counter-clockwise.");
  motor.step(-4096,15); // CCW 4096 steps (1 rotation) @15rpm
  delay(1000);
}
