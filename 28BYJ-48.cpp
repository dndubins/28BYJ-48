/* 28BYJ-48.cpp
 * Controlling Stepper with ULN2003
 * David Dubins 15-Dec-20
 * Last Updated: 25-Dec-21
 *
 */

#include <Arduino.h>
#include <28BYJ-48.h>

StepperMotor::StepperMotor(byte in1, byte in2, byte in3, byte in4){
  // store user's pin numbers into IN[] array
  this->IN[0] = in1;
  this->IN[1] = in2;
  this->IN[2] = in3;
  this->IN[3] = in4;
  // set pins to OUTPUT mode
  for(int i=0;i<4;i++){
    pinMode(this->IN[i],OUTPUT); // set pins to output mode
  }
}

void StepperMotor::step(int nSteps,float rpm){
  //convert rpm to time delay in microsec per step:
  unsigned long t=60000000/(rpm*4096); // #steps per revolution=4096
  bool mSequence[8][4]={
    {0, 0, 0, 1}, // step 0       
    {0, 0, 1, 1}, // step 1
    {0, 0, 1, 0}, // step 2
    {0, 1, 1, 0}, // step 3
    {0, 1, 0, 0}, // step 4
    {1, 1, 0, 0}, // step 5
    {1, 0, 0, 0}, // step 6    
    {1, 0, 0, 1}  // step 7
  };
  static int mStep; // remember last val of mStep
  for(int i=0;i<abs(nSteps);i++){ // STEP pulses
    if(nSteps>0){ // clockwise
      mStep++;
      if(mStep>7)mStep=0;
    }else{  // counter-clockwise
      mStep--;
      if(mStep<0)mStep=7;      
    }
    for(int j=0;j<4;j++){
      digitalWrite(this->IN[j],mSequence[mStep][j]);
    }
    delay_(t);
  }
}

void StepperMotor::delay_(unsigned long x){ // allows for delays <1ms (x is in microseconds)
  if(x<16383){ // delayMicroseconds() becomes less accurate above 16383 uS
    delayMicroseconds(x); // use microsec delay if x < 16383 usec
  }else{
    delay(x/1000); // use millisec delay if x >= 16383 usec (will be important at speeds under 1 rpm)
  }  
}
