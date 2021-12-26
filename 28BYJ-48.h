/* 28BYJ-48.h
 * Controlling Stepper with ULN2003
 * David Dubins 15-Dec-20
 * Last Updated: 25-Dec-21
 *
 */

#ifndef Stepper_28BYJ48_h
#define Stepper_28BYJ48_h

class StepperMotor {
public:
    StepperMotor(byte in1, byte in2, byte in3, byte in4);    // Constructor to set in1-4 pins
    void delay_(unsigned long x);                                 // Constructor for delay
    float rpm; // to hold rpm  
    void step(int n, float speed);         // Step a certain number of steps. + for one way and - for the other
    byte IN[4];      // to hold digital pin numbers for control wires
};

#endif
