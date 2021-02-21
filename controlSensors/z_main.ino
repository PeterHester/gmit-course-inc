
 

 
Blinker blink8 = Blinker(PIN_LED, 500, 500);
depthSensor testDepthSensor = depthSensor(PIN_SENSOR,500);


void setup() {
   Serial.begin(9600);//open serial port at 9600

}

void loop() {
 
  blink8.check();
testDepthSensor.check();

}
