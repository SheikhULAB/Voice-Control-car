#include <AFMotor.h>
 
AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor3(3, MOTOR12_64KHZ); // create motor #3, 1KHz pwm
AF_DCMotor motor4(4, MOTOR12_64KHZ); // create motor #4, 1KHz pwm

 
void setup() 
{
  Serial.begin(9600);//set up Serial library at 9600 bps
 // Serial.println("Motor test!");  
  MotorSpeed(200);
  AllForward();
  
}
 
void loop() {
 
}
 
void MotorSpeed(int Speed)
{
  motor1.setSpeed(Speed);     // set the speed to 200 (255 max)
  motor2.setSpeed(Speed); 
  motor3.setSpeed(Speed); 
  motor4.setSpeed(Speed);
}
 
void AllForward()
{
  //Serial.print("forward");  
  motor1.run(FORWARD);      // turn it on going forward
  motor2.run(FORWARD); 
  
  motor3.run(FORWARD); 
  motor4.run(FORWARD); 
}

void turnRight() { //Mert Arduino https://bit.ly/MertArduino
  motorSet = "RIGHT";
  Motor1.run(FORWARD);      // turn motor 1 forward
  Motor2.run(FORWARD);      // turn motor 2 forward
  Motor1.run(BACKWARD);    // turn motor 3 backward
  Motor2.run(BACKWARD);    // turn motor 4 backward
  Motor1.setSpeed(speedSet+MAX_SPEED_OFFSET);      
  Motor2.setSpeed(speedSet+MAX_SPEED_OFFSET);     
  delay(1500); // run motors this way for 1500        
  motorSet = "FORWARD";
  Motor1.run(FORWARD);      // set both motors back to forward
  Motor2.run(FORWARD);
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);      
}  

//-------------------------------------------------------------------------------------------------------------------------------------
void turnLeft() { //Mert Arduino https://bit.ly/MertArduino
  motorSet = "LEFT";
  Motor1.run(BACKWARD);      // turn motor 1 backward
  Motor2.run(BACKWARD);      // turn motor 2 backward
  Motor1.setSpeed(speedSet+MAX_SPEED_OFFSET);     
  Motor2.setSpeed(speedSet+MAX_SPEED_OFFSET);    
  Motor1.run(FORWARD);     // turn motor 3 forward
  Motor2.run(FORWARD);     // turn motor 4 forward
  delay(1500); // run motors this way for 1500  
  motorSet = "FORWARD";
  Motor1.run(FORWARD);      // turn it on going forward
  Motor2.run(FORWARD);      // turn it on going forward
  Motor1.run(FORWARD);     // turn it on going forward
  Motor2.run(FORWARD);     // turn it on going forward
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnAround() { //Mert Arduino https://bit.ly/MertArduino
  motorSet = "RIGHT";
  Motor1.run(FORWARD);      // turn motor 1 forward
  Motor2.run(FORWARD);      // turn motor 2 forward
  Motor1.run(BACKWARD);    // turn motor 3 backward
  Motor2.run(BACKWARD);    // turn motor 4 backward
  Motor1.setSpeed(speedSet+MAX_SPEED_OFFSET);      
  Motor2.setSpeed(speedSet+MAX_SPEED_OFFSET);
  delay(1700); // run motors this way for 1700
  motorSet = "FORWARD";
  Motor1.run(FORWARD);      // set both motors back to forward
  Motor2.run(FORWARD);
  Motor1.run(FORWARD);
  Motor2.run(FORWARD);      
}

 
