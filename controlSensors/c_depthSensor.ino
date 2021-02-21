 #define PIN_SENSOR A2

#define  pinMode(pinID, INPUT);

class depthSensor {
  private:
   int pinID;
   unsigned long timeOn;
   unsigned long nextChangeTime = 0;
  float voltage;
  float distance;
  
   

  public:
  
    depthSensor(float pinID, unsigned long timeOn) {
      this->pinID = pinID;
      this->timeOn = timeOn;
     

     
    }

      


    // the loop routine runs over and over again forever:
void check() {
  unsigned long currentTime = millis();
      
      if(currentTime >= nextChangeTime){
      nextChangeTime = currentTime + timeOn;
 
           pinID = analogRead(PIN_SENSOR);//Sensor value is reading analog values on A0 on the arduino
            voltage = pinID * (5.0 / 1023.0);//the voltage calculation of the Anolog input *(5.0/1023.0)
            distance=-22.044*(voltage)+60.062;//distance calulation using the graph in excel and the equation of a line 
           Serial.print("X,"); Serial.print(distance); Serial.print("  ");//print out the distance 
           Serial.println(" "); 
          
        }
          
              
 }

};
