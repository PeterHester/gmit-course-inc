 #define PIN_SENSOR A2



class lightSensor {
  private:
   byte pinID;
   unsigned long timeInterval;
   unsigned long nextChangeTime = 0;
   int pinValue=0;
  float voltage=0;
  unsigned long currentTime;
  
   

  public:
  
    lightSensor(byte pinVal, unsigned long interval) {
      this->pinID = pinVal;
      this->timeInterval = interval;
     pinMode(pinID, INPUT);

     
    }


      


    // Calcuations after Interval
void intervalCheck() {
  
      currentTime = millis(); 
      if(currentTime >= nextChangeTime){
        
        pinValue = analogRead(pinID);//Sensor value is reading analog values on A0 on the arduino
      
        voltage = pinValue * (5.0 / 1023.0);//the voltage calculation of the Anolog input *(5.0/1023.0)
           
        nextChangeTime = currentTime + timeInterval;
        Serial.println(getVoltage());
        }
        }
        
        float getPinValue(){
           return pinValue; 
        }
 
          
        float getVoltage(){
          return voltage;
        }

              
 

};
