/*
 -----------------------------------------
  Mert Arduino Tutorial and Projects
  Subscribe for more videos and projects
  Thanks all subscribers ;)
 ----------------------------------------
*/
 
#include <AFMotor.h> //Adafruit Motor Shield Library. First you must download and install AFMotor library
   //Servo library. This is standard library. (Sketch -> Include Library -> Servo)
String voice;
 
AF_DCMotor motor1 (1, MOTOR12_64KHZ); //create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor motor2 (2, MOTOR12_64KHZ); //create motor #2 using M2 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor motor3 (3, MOTOR34_1KHZ); // create motor #3, 1KHz pwm
AF_DCMotor motor4 (4, MOTOR34_1KHZ);


 
 
void setup()
{
  Serial.begin(9600); //start serial communication
  
  
}
 
void loop() 
{
  while (Serial.available()){ //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0){
    if(voice == "*go ahead"){
      forward_car();
      
      }
  
      
    else if(voice == "*go back"){
      back_car();
      }
      
      
    else if(voice == "*turn right") {
      right_car();
    }
    else if(voice == "*turn left") {
    //  left_car();
    }
    
    
    else if(voice == "*stop") {
      stop_car();
    }

   
    
  voice=""; //Reset the variable after initiating
  }
}

 
void forward_car()
{
  motor1.run(FORWARD);
  motor1.setSpeed(170);
  motor2.run(FORWARD);
  motor2.setSpeed(170);
  
  motor3.run(FORWARD);
  motor3.setSpeed(170);
  motor4.run(FORWARD);
  motor4.setSpeed(170);
  delay(2000);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
 
void back_car()
{
  motor1.run(BACKWARD);
  motor1.setSpeed(170);
  motor2.run(BACKWARD);
  motor2.setSpeed(170);
  motor3.run(BACKWARD);
  motor3.setSpeed(170);
  motor4.run(BACKWARD);
  motor4.setSpeed(170);
  delay(2000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
   motor3.run(RELEASE);
  motor4.run(RELEASE);
}

  
void right_car()
{
  
  motor1.run(FORWARD);
  motor1.setSpeed(170);
  motor2.run(BACKWARD);
  motor2.setSpeed(170);
   motor3.run(FORWARD);
  motor3.setSpeed(170);
  motor4.run(BACKWARD);
  motor4.setSpeed(170);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor3.run(RELEASE);
}
  
void left_car()
{
 
  motor1.run(BACKWARD);
  motor1.setSpeed(170);
  motor2.run(FORWARD);
  motor2.setSpeed(170);
  motor3.run(BACKWARD);
  motor3.setSpeed(170);
  motor4.run(FORWARD);
  motor4.setSpeed(170);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
 

 

 
 
void stop_car ()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
