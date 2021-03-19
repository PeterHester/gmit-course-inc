/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
   int sensorValue = analogRead(A0);//Sensor value is reading analog values on A0 on the arduino
   float voltage = sensorValue * (5.0 / 1023.0);//the voltage calculation of the Anolog input *(5.0/1023.0)
   float distance=-22.044*voltage+60.062;//distance calulation using the graph in excel and the equation of a line 
   Serial.print("X,"); Serial.print(distance); Serial.print("  ");//print out the distance 
   Serial.println(" "); 
   delay(500);// Enter a delay, can help when trying to view the results on the serial Monitor 
}
