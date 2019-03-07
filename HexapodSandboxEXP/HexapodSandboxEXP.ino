/***********************************************************
*  Test code for hexapod bits and bobs
*  Evan Neu, Hunter Badey, Kirk Boyd and Mark Morales
*  Last edit: 02/10/2019 KB
************************************************************/
#include <ax12.h>
#define soundLEDport 2 //blue LED
#define flameLEDport 3 //red LED
#define videoLEDport 4 //green LED
#define pwrLEDport 5 //yellow LED
#define startButtonPort 6 //green button
#define button2 7//
#define button3 8
#define button4 9
#define button5 10//
#define versa 11//port for versa valve solenoid
#define mic1port 12//1st mic for start sequence
#define mic2port 13 //2nd mic for start sequence
#define flameSensor1 14 //port for 1st flame sensor
#define flameSensor2 15 //2nd flame sensor port, for now unused
#define sharp1port 16 //sharp sensor 1 port for navigation
#define sharp2port 17 //sharp sensor 2 port for navigation
#define vidPort 18 //for now unused port, but dedicated to the video detection for later
#define CFR 1 //ID num for Coxa Front Right Dynamixel AX12-A Servo
#define CMR 2 //ID num for Coxa Middle Right Dynamixel AX12-A Servo
#define CRR 3 //ID num for Coxa Rear Right Dynamixel AX12-A Servo
#define CRL 4 //ID num for Coxa Rear Left Dynamixel AX12-A Servo
#define CML 5 //ID num for Coxa Middle Left Dynamixel AX12-A Servo
#define CFL 6 //ID num for Coxa Front Left Dynamixel AX12-A Servo
#define FFR 7 //ID num for Femur Front Right Dynamixel AX12-A Servo
#define FMR 8 //ID num for Femur Middle Right Dynamixel AX12-A Servo
#define FRR 9 //ID num for Femur Rear Right Dynamixel AX12-A Servo
#define FRL 10 //ID num for Femur Rear Left Dynamixel AX12-A Servo
#define FML 11 //ID num for Femur Middle Left Dynamixel AX12-A Servo
#define FFL 12 //ID num for Femur Front Left Dynamixel AX12-A Servo

void setup() {
  pinMode(soundLEDport,OUTPUT);
  digitalWrite(soundLEDport,LOW);
  pinMode(flameLEDport,OUTPUT);
  digitalWrite(flameLEDport,LOW);
  pinMode(videoLEDport,OUTPUT);
  digitalWrite(videoLEDport,LOW);
  pinMode(pwrLEDport,OUTPUT);
  digitalWrite(pwrLEDport,HIGH);
  pinMode(startButtonPort,INPUT);
  stand(1000);
  
//  while(!soundSystem()){
//  }
}

void loop() {

  
  if (startButton()){
    walkStance(1000);
    walkA(500);
    delay(1000);
    while(!startButton()){
      walkB(500);
      walkC(500);
      walkD(500);
      walkE(500);
    }
  }
}