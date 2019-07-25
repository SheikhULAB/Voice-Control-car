#include <AFMotor.h>
 
AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm
AF_DCMotor motor3(3, MOTOR34_1KHZ); // create motor #3, 1KHz pwm
AF_DCMotor motor4(4, MOTOR34_1KHZ); // create motor #4, 1KHz pwm


unsigned long previousMillis = 0;
long interval = 10000; 
 
void setup() 
{

  Serial.begin(9600);//set up Serial library at 9600 bps
  Serial.println("Motor test!");  
  MotorSpeed(200);
  AllForward();
  delay(1000);
  //AllBackward();
 // delay(1000);
  //AllStop();
  //delay(1000);
}
 
void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval) {
     previousMillis = currentMillis;  

  motor1.run(RELEASE);      // turn it on going forward
  motor2.run(RELEASE); 
  motor3.run(RELEASE); 
  motor4.run(RELEASE); 
  }

 
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
  Serial.print("forward");  
 motor1.run(BACKWARD);      // turn it on going forward
 motor2.run(FORWARD); 
  motor3.run(FORWARD); 
  motor4.run(BACKWARD); 
}
 
