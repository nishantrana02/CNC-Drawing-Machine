//Stepper Motor Test
//Nishant Rana
#include <AccelStepper.h>
#define HalfStep 8
#define motorPin1  3     // IN1 on the ULN2003 driver 1
#define motorPin2  4     // IN2 on the ULN2003 driver 2
#define motorPin3  5     // IN3 on the ULN2003 driver 3
#define motorPin4  6     // IN4 on the ULN2003 driver 4

AccelStepper stepper1(HalfStep, motorPin1, motorPin3, motorPin2, motorPin4);
int pot=0;          
int stepperspeed;
void setup() {
  stepper1.setMaxSpeed(1400.0);       
  stepper1.setAcceleration(600.0);
  stepper1.setSpeed(100);
  pinMode(A0,INPUT);  
}
 void loop() {

  pot=analogRead(A0);
  stepperspeed=map(pot,0,1023,-1400,1400);
  if(stepperspeed>-50&& stepperspeed<50){
    stepperspeed=0;
    }
  stepper1.setSpeed(stepperspeed);
  stepper1.runSpeed();
}
