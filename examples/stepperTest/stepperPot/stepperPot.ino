/* 28BYJ-48.h Library: Potentiometer control for 28BYJ-48 5V or 12V DC Stepper Motor 
 *  with ULN2003 Driver
 *  
 * Wire ULN2003 to Arduino Uno:
 * ----------------------------
 * Blue wire (A) - IN1 to Pin 8
 * Pink Wire (B) - IN2 to Pin 9 
 * Yellow Wire (C) IN3 to Pin 10
 * Orange Wire (D) IN4 to Pin 11
 * - to GND
 * + to +5V
 *
 * Potentiometer to Arduino Uno:
 * -----------------------------
 * Outer Leg - +5V
 * Wiper - A0
 * Other outer leg - GND
 */

const byte potPin=A0;
int v=0;
int last=0;

#include <28BYJ-48.h>

StepperMotor motor(8,9,10,11);

void setup(){
}

void loop(){
  v=map(analogRead(potPin),0,255,0,4096); // scale #steps to something bigger
  motor.step(v-last,15); // step difference at 15 rpm 
  last=v;
}
