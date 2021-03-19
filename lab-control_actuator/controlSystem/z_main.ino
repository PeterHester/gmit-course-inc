
  #define PIN_Servo A0
  #define PIN_SENSOR A2
  #define PIN_LED 8

 
Blinker blink8 = Blinker(PIN_LED, 500, 500);
depthSensor testDepthSensor = depthSensor(PIN_SENSOR,500);
servoActuator testServo(PIN_Servo,50);

void setup() {
   Serial.begin(9600);//open serial port at 9600

}

void loop() {
 
  blink8.check();
testDepthSensor.check();

testServo.setAngle(testDepthSensor.getDistance()); //distance readings used to control servo

}
