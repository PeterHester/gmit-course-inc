#include <Servo.h>

class servoActuator{
 private:
    byte pinServo;
    int angleVal; //The Angle Value
    unsigned long timeOn;
    Servo pServo; //object to control Servo
 public:
      // Constructor to input Private values
      servoActuator(byte pinServo, unsigned long timeOn){
       this->pinServo = pinServo;
      this->timeOn = timeOn;
      
      pinMode(pinServo, OUTPUT);
      
      }
      // Function for the angle values to be called
      void setAngle(int angle){
         pServo.attach(pinServo);             //"attach" will attach the servo variable to pinServo
         angleVal=analogRead(A2);             //read the input pin
         angle = map(angleVal,10,50,0,180);  //Map function in arduino map(value, fromLow, fromHigh, toLow, toHigh)
         pServo.write(angle);                 //Servo position moves to the angle
         delay(timeOn);                       // delay on the program when running

      }
      
    
  };
