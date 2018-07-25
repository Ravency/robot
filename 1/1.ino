#include <Wire.h>
#include <JY901.h>
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() 
{
  Serial.begin(57600);
  JY901.StartIIC();
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
   //print received data. Data was received in serialEvent;
  JY901.GetAngle();
  int heading=(int)((float)JY901.stcAngle.Angle[2]/32768*180);
  heading=abs(heading);
  Serial.println(heading);    
  myservo.write(heading); 
  delay(15);
}



