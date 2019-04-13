/****VISION****/
#define sharp1max 230//updated 04/11/19 9pm
#define sharp1a  285//(plusminus 7) closest it can be to the wall (on it's left)while parallel
#define sharp1b 632//(plusminus 10) closest it could ever be to the wall, sharp 1 right in front
#define sharp1c 230//(delta )almost too close to the wall on the left
#define sharp1d 120//(delta )almost too far from the wall on the left
#define sharp1e 149//good distance from wall on left
#define sharp1delta 9//average variance of sharp 1
#define sharp2max 260//updated 04/11/19 9pm
#define sharp2a 360//(plusminus 7)closest it can be to the wall(on it's right) while parallel
#define sharp2b 637//(plusminus 10)closest it could ever be to the wall, sharp 1 right in front
#define sharp2c 232//(delta )almost too close to the wall on the right
#define sharp2d 171//(delta )almost too far from the wall on the right (parallel
#define sharp2e 189//good distance from wall on right
#define sharp2delta 17//average variance of sharp 2
#define sharp3max 300//updated 04/11/19 9pm
#define sharp4max 500//
#define sharp4nothingThereLo 110
#define sharp4nothingThereHi 155
int val1;
int val2;
int val3;
int val4;
int strCount;

void navigate(){//use the sharp sensors to search the maze by avoiding walls 
  val1 = s1();
  val2 = s2();
  val3 = s3();
  val4 = s4();
  if(val3>= sharp3max){//if something is too close in front, turn right
    turn90R();
  }
  else if(val2>sharp2a){//if really close to right sharp, turn left
    turnL();
  }
  else if((val1<115)&&(500<val4&&val4<600)&&val2<sharp2d){//when approaching a wall that ends on the left side
      leftWallEnd();
  }
  //follow wall on left with sharp sensor if nothing scarier is happening
  else if(val1>=sharp1c){
    turnR();
  }
  else if(val1<=sharp1d){
    turnL();
  }
  else{
    fwd();
  }
}
void joystick(){//control the hexapod via joystick
  Serial.print("x = ");
  Serial.println(joyX);
  Serial.print("y = ");
  Serial.println(joyY);
  if(analogRead(joyX) >= 1022){
      fwdSm();
  }
  if(analogRead(joyX) <= 1){
      back();
  }
  if(analogRead(joyY) >= 1022){
    //turnR();  
    turnSmR();
  }
  if(analogRead(joyY) <= 0){
    //turnL();
    turnSmL();
  }
}
void leftWallEnd(){
  soundLED(true);
  while(val4>300&&val1<120){//while s1 sees open space, but s4 still sees a wall
      val1 = s1();
      val4 = s4();
      if(s1()>=sharp1c){turnR();}
      else if(s4()>=500){turnR();}
      else{fwd();}
    }
    turn90L();
    fwd();
    fwd();
    turn90L();
    while(s4()<290){
      fwd();
    }
  soundLED(false);  
}
boolean inRoom(){
  if(str()){strCount++;}
  if(strCount%2!=0){return true;}
  else return false;
}
void roomCheck(){
  if(inRoom){
    fwd();
    fwd();
    fwd();
    turnSmR();
  }
}
///**GRAVEYARD**/
//  else if(s1()>= sharp1a){//if it is closer than sharp1a turn right
//    turnR();
//  }
//  else if(s2()>= sharp2a){//if it is closer than sharp2a turn left
//    turnL();
//  }
//  else if(s1()> sharp1c){//if it is kind of close shimmy right
//    strafe60();
//  }
//  else if(s2()>sharp2a){//if it is kind of close shimmy left
//    strafe330();
//  }
//  else if(s4()<sharp4nothingThereLo){//if there is nothing close on left, turn towards opening
//   buzz();
//   backHome();
//   diagLfwd();
//   diagLfwd();
//   diagLfwd();
//   diagLfwd();
//   diagLfwd();
//   diagLfwd();
//   diagLfwd();
//  }
////  else if(s4()>sharp4nothingThereLo &&s4()<sharp4nothingThereHi && !didThatOneTurn){
////    digitalWrite(soundLEDport, HIGH);
////    digitalWrite(flameLEDport, HIGH);
////    digitalWrite(runningLEDport, HIGH);
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    turn90L();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    turn90L();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    fwd();
////    digitalWrite(soundLEDport, LOW);
////    didThatOneTurn = true;
////  }
//  else{fwd();}//if none of the sensors read too close, go straight fwd
//}