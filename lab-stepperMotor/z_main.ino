#define PinA 4
#define PinB 5
#define PinC 6
#define PinD 7
#define FrwRevBTN 8 //Forward/Reverse Button, the motor direction depends on the state of this Button 
#define NUMBER_OF_STEPS_PER_REV 512;

void setup() {
  // put your setup code here, to run once:
    pinMode(PinA,OUTPUT);
    pinMode(PinB,OUTPUT);
    pinMode(PinC,OUTPUT);
    pinMode(PinD,OUTPUT);
    pinMode(FrwRevBTN,INPUT);
   
}
//reads pin a to d
void Forward(int a,int b,int c,int d) {
    digitalWrite(PinA,a);
    digitalWrite(PinB,b);
    digitalWrite(PinC,c);
    digitalWrite(PinD,d);

}//reads pin d to a
void Reverse(int d,int c,int b,int a) {
    digitalWrite(PinA,a);
    digitalWrite(PinB,b);
    digitalWrite(PinC,c);
    digitalWrite(PinD,d);

}

void stepForward(int DELAY){
    Forward(1,0,0,0);
    delay(DELAY);
    Forward(1,1,0,0);
    delay(DELAY);
     Forward(0,1,0,0);
    delay(DELAY);
    Forward(0,1,1,0);
    delay(DELAY);
    Forward(0,0,1,0);
    delay(DELAY);
    Forward(0,0,1,1);
    delay(DELAY);
     Forward(0,0,0,1);
    delay(DELAY);
    Forward(1,0,0,1);
    delay(DELAY);
      
}

void stepReverse(int DELAY){
    Reverse(1,0,0,0);
    delay(DELAY);
    Reverse(1,1,0,0);
    delay(DELAY);
     Reverse(0,1,0,0);
    delay(DELAY);
    Reverse(0,1,1,0);
    delay(DELAY);
    Reverse(0,0,1,0);
    delay(DELAY);
    Reverse(0,0,1,1);
    delay(DELAY);
     Reverse(0,0,0,1);
    delay(DELAY);
    Reverse(1,0,0,1);
    delay(DELAY);
      
}
//if Push button is Pressed the stepper motor will go in reverse if It's not pressed it will go Forward(CW)
  void loop(){
    bool SwitchDirection=digitalRead(FrwRevBTN);
    int rawValue = analogRead(A0);
    int delayValue = map(rawValue,0,1023,5,100);
   if (SwitchDirection==HIGH){
    stepReverse(delayValue);
    }
    else{
      stepForward(delayValue);
      }
    }
    
  
