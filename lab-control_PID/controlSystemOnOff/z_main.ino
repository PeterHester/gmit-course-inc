
  #include <PID_v1.h>
  #define PIN_SENSOR A2
  #define PIN_RELAY 8


/*
    double kp =2;
    double ki =5;
    double kd =1;

    unsigned long currentTime,previousTime;
    double elapsedTime;
    double error;
    double lastError;
    double input,output,setPoint;
    double cumerror,rateError;
*/
    

Relay relay8 = Relay(PIN_RELAY, 2.5);
lightSensor sensor(A2,1000);


void setup() {
   Serial.begin(9600);//open serial port at 9600
   float SetPoint=0;
}


void loop(){
 
 sensor.intervalCheck();
 relay8.check(sensor.getVoltage());

}
