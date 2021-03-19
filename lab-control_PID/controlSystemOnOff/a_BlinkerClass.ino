#define PIN_RELAY 8


/*
 * BLINKER CLASS DEFINITION
 */
class Relay {
  private:
     byte pinRelay;

     boolean RelayState = LOW;
     float voltageSetpoint;
 

  public:
      Relay(byte pinRelay,float voltageSetpoint) {
        
      this->pinRelay = pinRelay;
      this->voltageSetpoint = voltageSetpoint;
  

      pinMode(pinRelay, OUTPUT);
    }

    // Checks whether it is time to turn on or off the Relay.
    void check(float voltage) {
      

      if(voltage >= voltageSetpoint) {

        if(RelayState) {
          // Relay is currently turned On. Turn Off Relay.
          RelayState = LOW;
         
        }
        else{
          // Relay is currently turned Off. Turn On Relay.
         RelayState = HIGH;
         
        }

        digitalWrite(pinRelay, RelayState);
      }
    }
};
